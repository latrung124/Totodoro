/*
 * File: WNextAsyncMessageHandler.cpp
 * Author: trung.la
 * Date: 02-22-2025
 * Description: This file contains the implementation of the WNextAsyncMessageHandler class.
 */

#include "core/services/service-handlers/WNextAsyncMessageHandler.h"

WNextAsyncMessageHandler::WNextAsyncMessageHandler()
    : ServiceMessageHandler(ServiceMessageId::WNextAsyncMessage)
{
}

WNextAsyncMessageHandler::~WNextAsyncMessageHandler()
{
}

void WNextAsyncMessageHandler::handleMessage(ServiceMessageUPtr message)
{
	// Cast the message to WNextAsyncMessage
}
