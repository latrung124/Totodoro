/*
 * File: ServiceMessageQueue.h
 * Author: trung.la
 * Date: 02-10-2025
 * Description: This file contains the declaration of the ServiceMessageQueue class.
 */

#ifndef SERVICE_MESSAGE_QUEUE_H
#define SERVICE_MESSAGE_QUEUE_H

#include "core/services/queue/MessageQueue.h"

#include <atomic>
#include <condition_variable>
#include <memory>
#include <mutex>
#include <queue>

class ServiceMessageQueue : public MessageQueue
{
public:
	using ServiceMessageUPtr = std::unique_ptr<ServiceMessage>;

	static ServiceMessageQueue &getInstance();
	~ServiceMessageQueue() override;

	ServiceMessageQueue(const ServiceMessageQueue &) = delete;
	ServiceMessageQueue &operator=(const ServiceMessageQueue &) = delete;
	ServiceMessageQueue(ServiceMessageQueue &&) = delete;
	ServiceMessageQueue &operator=(ServiceMessageQueue &&) = delete;

	virtual void start() override;
	virtual void stop() override;

	virtual void push(ServiceMessageUPtr msg) override;

private:
	ServiceMessageQueue();
	void loop();
	bool canConsume();

	void consumeMessage(ServiceMessageUPtr message);

	mutable std::mutex m_mutex;
	std::thread m_looper;
	std::condition_variable m_conditionVariable;
	std::queue<ServiceMessageUPtr> m_messageQueue;
	std::atomic<bool> m_stopFlag{false};
};

#endif // SERVICE_MESSAGE_QUEUE_H
