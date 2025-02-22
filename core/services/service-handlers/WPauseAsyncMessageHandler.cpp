/*
 * File: WPauseAsyncMessageHandler.cpp
 * Author: trung.la
 * Date: 02-22-2025
 * Description: This file contains the implementation of the WPauseAsyncMessageHandler class.
 */

#include "core/services/service-handlers/WPauseAsyncMessageHandler.h"

WPauseAsyncMessageHandler::WPauseAsyncMessageHandler()
    : ServiceMessageHandler(ServiceMessageId::WPauseAsyncMessage)
{
}

WPauseAsyncMessageHandler::~WPauseAsyncMessageHandler()
{
}

void WPauseAsyncMessageHandler::handleMessage(ServiceMessageUPtr message)
{
	// Cast the message to WPauseAsyncMessage
}
