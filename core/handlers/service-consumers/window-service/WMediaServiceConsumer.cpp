/*
* File: WMediaServiceConsumer.cpp
* Author: trung.la
* Date: 02-10-2025
* Description: This file contains the implementation of the WMediaServiceConsumer class.
*/

#include "WMediaServiceConsumer.h"

#include "core/handlers/WMediaServiceHandler.h"

#include "utils/ThreadGuard.h"

WMediaServiceConsumer::WMediaServiceConsumer(WMediaServiceHandler *handler)
    : m_handler(handler)
    , m_isRunning(false)
{
}

WMediaServiceConsumer::~WMediaServiceConsumer()
{
    utils::ThreadGuard guard(m_looper);
}

void WMediaServiceConsumer::start()
{
    m_isRunning = true;
    m_looper = std::thread(&WMediaServiceConsumer::loop, this);
}

void WMediaServiceConsumer::stop()
{
    m_isRunning = false;
    m_conditionVariable.notify_all();
}

bool WMediaServiceConsumer::canConsume()
{
    return m_isRunning && !m_messageQueue.empty();
}

void WMediaServiceConsumer::addMessage(ServiceMessageUPtr message)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    m_messageQueue.push(std::move(message));
    m_conditionVariable.notify_all();
}

void WMediaServiceConsumer::loop()
{
    while (true) {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_conditionVariable.wait(lock, [this] {
            return canConsume();
        });

        if (!m_isRunning && m_messageQueue.empty()) {
            break;
        }

        if (m_handler) {
            auto message = std::move(m_messageQueue.front());
            m_messageQueue.pop();
            processMessage(std::move(message));
        }
    }
}

void WMediaServiceConsumer::processMessage(ServiceMessageUPtr message)
{
    if (m_handler) {
        m_handler->processMessage(std::move(message));
    }
}
