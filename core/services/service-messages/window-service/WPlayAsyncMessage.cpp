/*
 * File: WPlayAsyncMessage.cpp
 * Author: trung.la
 * Date: 02-22-2025
 * Description: This defines class WPlayAsyncMessage
 */

#include "core/services/service-messages/window-service/WPlayAsyncMessage.h"

WPlayAsyncMessage::WPlayAsyncMessage()
    : ServiceMessage(ServiceMessageId::WPlayAsyncMessage)
{
}

bool WPlayAsyncMessage::isPlayAsync() const
{
	return m_playAsync;
}

void WPlayAsyncMessage::setPlayAsync(bool playAsync)
{
	m_playAsync = playAsync;
}
