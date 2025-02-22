/*
 * File: WNextAsyncMessage.cpp
 * Author: trung.la
 * Date: 02-22-2025
 * Description: This defines class WNextAsyncMessage
 */

#include "core/services/service-messages/window-service/WNextAsyncMessage.h"

WNextAsyncMessage::WNextAsyncMessage()
    : ServiceMessage(ServiceMessageId::WNextAsyncMessage)
{
}

bool WNextAsyncMessage::isNextAsync() const
{
	return m_nextAsync;
}

void WNextAsyncMessage::setNextAsync(bool nextAsync)
{
	m_nextAsync = nextAsync;
}
