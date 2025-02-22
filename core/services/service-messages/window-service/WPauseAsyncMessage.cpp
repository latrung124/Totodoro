/*
 * File: WPauseAsyncMessage.cpp
 * Author: trung.la
 * Date: 02-22-2025
 * Description: This defines class WPauseAsyncMessage
 */

#include "core/services/service-messages/window-service/WPauseAsyncMessage.h"

WPauseAsyncMessage::WPauseAsyncMessage()
    : ServiceMessage(ServiceMessageId::WPauseAsyncMessage)
{
}

bool WPauseAsyncMessage::isPauseAsync() const
{
	return m_pauseAsync;
}

void WPauseAsyncMessage::setPauseAsync(bool pauseAsync)
{
	m_pauseAsync = pauseAsync;
}
