/*
 * File: WPauseAsyncMessageHandler.cpp
 * Author: trung.la
 * Date: 02-22-2025
 * Description: This file contains the implementation of the WPauseAsyncMessageHandler class.
 */

#include "core/services/service-handlers/WPauseAsyncMessageHandler.h"

#include "core/services/service-messages/window-service/WPauseAsyncMessage.h"
#include "core/services/ServiceManager.h"

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
	auto wPauseAsyncMessage = dynamic_cast<WPauseAsyncMessage *>(message.get());
	if (wPauseAsyncMessage == nullptr) {
		return;
	}

	auto wmediaService = ServiceManager::instance().getService<IWMediaService>();
	if (wmediaService == nullptr) {
		return;
	}
	wmediaService->pauseAsync();
}
