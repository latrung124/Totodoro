/*
 * File: ServiceMessageHandler.h
 * Author: trung.la
 * Date: 02-15-2025
 * Description: This file contains the declaration of the ServiceMessageHandler class.
 */

#ifndef SERVICE_MESSAGE_HANDLER_H
#define SERVICE_MESSAGE_HANDLER_H

#include "core/services/service-messages/ServiceMessage.h"

#include <memory>

class ServiceMessageHandler
{
public:
	using ServiceMessageUPtr = std::unique_ptr<ServiceMessage>;

	ServiceMessageHandler(ServiceMessageId id)
	    : m_id(id){};
	ServiceMessageHandler() = delete;
	virtual ~ServiceMessageHandler() = default;

	ServiceMessageHandler(const ServiceMessageHandler &) = delete;
	ServiceMessageHandler &operator=(const ServiceMessageHandler &) = delete;

	ServiceMessageHandler(ServiceMessageHandler &&) = delete;
	ServiceMessageHandler &operator=(ServiceMessageHandler &&) = delete;

	ServiceMessageId getId() const
	{
		return m_id;
	}

	virtual void handleMessage(ServiceMessageUPtr message) = 0;

private:
	ServiceMessageId m_id = ServiceMessageId::None;
};

#endif // SERVICE_MESSAGE_HANDLER_H
