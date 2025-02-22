/*
 * File: WNextAsyncMessageHandler.cpp
 * Author: trung.la
 * Date: 02-22-2025
 * Description: This file contains the implementation of the WNextAsyncMessageHandler class.
 */

#include "core/services/service-handlers/WNextAsyncMessageHandler.h"

#include "core/services/service-messages/window-service/WNextAsyncMessage.h"
#include "core/services/ServiceManager.h"

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
	auto wNextAsyncMessage = dynamic_cast<WNextAsyncMessage *>(message.get());
	if (wNextAsyncMessage == nullptr) {
		return;
	}

	auto wmediaService = ServiceManager::instance().getService<IWMediaService>();
	if (wmediaService == nullptr) {
		return;
	}
	wmediaService->nextAsync();
}
