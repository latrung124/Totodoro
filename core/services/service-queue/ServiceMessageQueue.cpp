/*
 * File: ServiceMessageQueue.cpp
 * Author: trung.la
 * Date: 02-10-2025
 * Description: This file contains the implementation of the ServiceMessageQueue class.
 */

#include "ServiceMessageQueue.h"

#include "core/services/service-consumer/ServiceMessageConsumer.h"

#include "utils/ThreadGuard.h"

ServiceMessageQueue &ServiceMessageQueue::getInstance()
{
	static ServiceMessageQueue instance;
	return instance;
}

ServiceMessageQueue::ServiceMessageQueue()
{
}

ServiceMessageQueue::~ServiceMessageQueue()
{
}

void ServiceMessageQueue::start()
{
	m_stopFlag.store(false);
	m_looper = std::thread(&ServiceMessageQueue::loop, this);
}

void ServiceMessageQueue::stop()
{
	m_stopFlag.store(true);
	m_conditionVariable.notify_one();
	utils::ThreadGuard guard(m_looper);
}

bool ServiceMessageQueue::canConsume()
{
	return m_stopFlag.load() || !m_messageQueue.empty();
}

void ServiceMessageQueue::push(ServiceMessageUPtr message)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	m_messageQueue.push(std::move(message));
	m_conditionVariable.notify_one();
}

void ServiceMessageQueue::loop()
{
	while (true) {
		std::unique_lock<std::mutex> lock(m_mutex);
		m_conditionVariable.wait(lock, [this] { return canConsume(); });

		if (m_stopFlag.load() && m_messageQueue.empty()) {
			break;
		}

		while (!m_messageQueue.empty()) {
			auto message = std::move(m_messageQueue.front());
			m_messageQueue.pop();
			ServiceMessageConsumer::getInstance().consumeMessage(std::move(message));
		}
	}
}
