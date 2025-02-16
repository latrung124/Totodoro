/*
* File: ServiceMessageQueue.cpp
* Author: trung.la
* Date: 02-10-2025
* Description: This file contains the implementation of the ServiceMessageQueue class.
*/

#include "ServiceMessageQueue.h"

#include "core/services/service-consumer/ServiceMessageConsumer.h"

#include "utils/ThreadGuard.h"

ServiceMessageQueue::ServiceMessageQueue()
    : m_isRunning(false)
{
}

ServiceMessageQueue::~ServiceMessageQueue()
{
    utils::ThreadGuard guard(m_looper);
}

void ServiceMessageQueue::start()
{
    m_isRunning = true;
    m_looper = std::thread(&ServiceMessageQueue::loop, this);
}

void ServiceMessageQueue::stop()
{
    m_isRunning = false;
    m_conditionVariable.notify_all();
}

bool ServiceMessageQueue::canConsume()
{
    return m_isRunning && !m_messageQueue.empty();
}

void ServiceMessageQueue::addMessage(ServiceMessageUPtr message)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    m_messageQueue.push(std::move(message));
    m_conditionVariable.notify_all();
}

void ServiceMessageQueue::loop()
{
    while (true) {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_conditionVariable.wait(lock, [this] {
            return canConsume();
        });

        if (!m_isRunning && m_messageQueue.empty()) {
            break;
        }

        auto message = std::move(m_messageQueue.front());
        m_messageQueue.pop();
        ServiceMessageConsumer::getInstance().consumeMessage(std::move(message));
    }
}
