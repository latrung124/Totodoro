/*
 * File: WPlayAsyncMessageHandler.cpp
 * Author: trung.la
 * Date: 02-22-2025
 * Description: This file contains the implementation of the WPlayAsyncMessageHandler class.
 */

#include "core/services/service-handlers/WPlayAsyncMessageHandler.h"

WPlayAsyncMessageHandler::WPlayAsyncMessageHandler()
    : ServiceMessageHandler(ServiceMessageId::WPlayAsyncMessage)
{
}

WPlayAsyncMessageHandler::~WPlayAsyncMessageHandler()
{
}

void WPlayAsyncMessageHandler::handleMessage(ServiceMessageUPtr message)
{
	// Cast the message to WPlayAsyncMessage
}
