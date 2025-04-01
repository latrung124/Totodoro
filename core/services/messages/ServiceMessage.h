/*
 * File: ServiceMessage.h
 * Author: trung.la
 * Date: 02-09-2025
 * Description: Service message class
 */

#ifndef SERVICE_MESSAGE_H
#define SERVICE_MESSAGE_H

#include <memory>

#include "core/services/messages/ServiceMessageId.h"

class ServiceMessage
{
public:
	ServiceMessage(const ServiceMessageId &id)
	    : m_id(id)
	{
	}

	ServiceMessage() = default;

	virtual ~ServiceMessage() = default;

	ServiceMessageId getId() const
	{
		return m_id;
	}

	virtual void extract() = 0;

private:
	ServiceMessageId m_id = ServiceMessageId::None;
};

using ServiceMessageUPtr = std::unique_ptr<ServiceMessage>;

#endif // SERVICE_MESSAGE_H
