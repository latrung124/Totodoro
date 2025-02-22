/*
 * File: WPreviousAsyncMessageHandler.cpp
 * Author: trung.la
 * Date: 02-22-2025
 * Description: This file contains the implementation of the WPreviousAsyncMessageHandler class.
 */

#include "core/services/service-handlers/WPreviousAsyncMessageHandler.h"

#include "core/services/service-messages/window-service/WPreviousAsyncMessage.h"
#include "core/services/ServiceManager.h"

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
	auto wPreviousAsyncMessage = dynamic_cast<WPreviousAsyncMessage *>(message.get());
	if (wPreviousAsyncMessage == nullptr) {
		return;
	}

	auto wmediaService = ServiceManager::instance().getService<IWMediaService>();
	if (wmediaService == nullptr) {
		return;
	}
	wmediaService->previousAsync();
}
