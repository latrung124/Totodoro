/*
 * File: WPreviousAyncMessage.cpp
 * Author: trung.la
 * Date: 02-22-2025
 * Description: This file contains the implementation of the WPreviousAsyncMessage class.
 */

#include "core/services/service-messages/window-service/WPreviousAsyncMessage.h"

WPreviousAsyncMessage::WPreviousAsyncMessage()
    : ServiceMessage(ServiceMessageId::WPreviousAsyncMessage)
{
}

bool WPreviousAsyncMessage::isPreviousAsync() const
{
	return m_previousAsync;
}

void WPreviousAsyncMessage::setPreviousAsync(bool previousAsync)
{
	m_previousAsync = previousAsync;
}
