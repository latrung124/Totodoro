/*
 * File: MessageQueue.cpp
 * Author: trung.la
 * Date: 02-10-2025
 * Description: This file contains the implementation of the MessageQueue class.
 */

#include "MessageQueue.h"

#include "core/services/consumer/ServiceMessageConsumer.h"

#include "utils/ThreadGuard.h"

MessageQueue &MessageQueue::getInstance()
{
	static MessageQueue instance;
	return instance;
}

MessageQueue::MessageQueue()
{
}

MessageQueue::~MessageQueue()
{
}

void MessageQueue::start()
{
	m_stopFlag.store(false);
	m_looper = std::thread(&MessageQueue::loop, this);
}

void MessageQueue::stop()
{
	m_stopFlag.store(true);
	m_conditionVariable.notify_one();
	utils::ThreadGuard guard(m_looper);
}

bool MessageQueue::canConsume()
{
	return m_stopFlag.load() || !m_messageQueue.empty();
}

void MessageQueue::push(ServiceMessageUPtr message)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	m_messageQueue.push(std::move(message));
	m_conditionVariable.notify_one();
}

void MessageQueue::loop()
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
