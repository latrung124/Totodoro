/*
 * File: Message.h
 * Author: trung.la
 * Date: 02-09-2025
 * Description: Service message class
 */

#ifndef SERVICE_MESSAGE_H
#define SERVICE_MESSAGE_H

#include <memory>

#include "core/services/messages/MessageId.h"

class Message
{
public:
	Message(const MessageId &id)
	    : m_id(id)
	{
	}

	Message() = default;

	virtual ~Message() = default;

	MessageId getId() const
	{
		return m_id;
	}

	virtual void execute() = 0;

private:
	MessageId m_id = MessageId::None;
};

using ServiceMessageUPtr = std::unique_ptr<Message>;

#endif // SERVICE_MESSAGE_H
