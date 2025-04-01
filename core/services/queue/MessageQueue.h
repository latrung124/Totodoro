/*
 * File: MessageQueue.h
 * Author: trung.la
 * Date: 02-10-2025
 * Description: This file contains the declaration of the MessageQueue class.
 */

#ifndef SERVICE_MESSAGE_QUEUE_H
#define SERVICE_MESSAGE_QUEUE_H

#include <atomic>
#include <condition_variable>
#include <memory>
#include <mutex>
#include <queue>

class Message;

class MessageQueue
{
public:
	using ServiceMessageUPtr = std::unique_ptr<Message>;

	static MessageQueue &getInstance();
	~MessageQueue();

	MessageQueue(const MessageQueue &) = delete;
	MessageQueue &operator=(const MessageQueue &) = delete;
	MessageQueue(MessageQueue &&) = delete;
	MessageQueue &operator=(MessageQueue &&) = delete;

	void start();
	void stop();

	void push(ServiceMessageUPtr msg);

private:
	MessageQueue();
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
