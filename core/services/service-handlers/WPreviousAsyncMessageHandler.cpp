/*
 * File: WPreviousAsyncMessageHandler.cpp
 * Author: trung.la
 * Date: 02-22-2025
 * Description: This file contains the implementation of the WPreviousAsyncMessageHandler class.
 */

#include "core/services/service-handlers/WPreviousAsyncMessageHandler.h"

WPreviousAsyncMessageHandler::WPreviousAsyncMessageHandler()
    : ServiceMessageHandler(ServiceMessageId::WPreviousAsyncMessage)
{
}

WPreviousAsyncMessageHandler::~WPreviousAsyncMessageHandler()
{
}

void WPreviousAsyncMessageHandler::handleMessage(ServiceMessageUPtr message)
{
	// Cast the message to WPreviousAsyncMessage
}
