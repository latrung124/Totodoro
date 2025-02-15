/*
* File: ServiceMessageQueue.cpp
* Author: trung.la
* Date: 02-10-2025
* Description: This file contains the implementation of the ServiceMessageQueue class.
*/

#include "ServiceMessageQueue.h"

#include "core/handlers/service-consumer/ServiceMessageConsumer.h"

#include "utils/ThreadGuard.h"

ServiceMessageQueue::ServiceMessageQueue(ServiceMessageConsumer *handler)
    : m_consumer(handler)
    , m_isRunning(false)
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

        if (m_consumer) {
            auto message = std::move(m_messageQueue.front());
            m_messageQueue.pop();
            consumeMessage(std::move(message));
        }
    }
}

void ServiceMessageQueue::consumeMessage(ServiceMessageUPtr message)
{
    if (m_consumer) {
        m_consumer->handleMessage(std::move(message));
    }
}
