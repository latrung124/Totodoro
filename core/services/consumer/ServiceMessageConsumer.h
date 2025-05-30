/*
File: ServiceMessageConsumer.h
* Author: trung.la
* Date: 02-10-2025
* Description: This file contains the declaration of the ServiceMessageConsumer class.
*/

#ifndef SERVICE_MESSAGE_CONSUMER_H
#define SERVICE_MESSAGE_CONSUMER_H

#include "core/services/consumer/ServiceConsumer.h"
#include "core/services/messages/Message.h"

#include <map>
#include <memory>

class Message;

class ServiceMessageConsumer : public ServiceConsumer
{
public:
	using ServiceMessageUPtr = std::unique_ptr<Message>;

	static ServiceMessageConsumer &getInstance();
	virtual ~ServiceMessageConsumer();

	void consumeMessage(ServiceMessageUPtr message);

private:
	ServiceMessageConsumer() = default;
};

#endif // SERVICE_MESSAGE_CONSUMER_H
