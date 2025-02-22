/*
 * File: WPlayAsyncMessageHandler.cpp
 * Author: trung.la
 * Date: 02-22-2025
 * Description: This file contains the implementation of the WPlayAsyncMessageHandler class.
 */

#include "core/services/service-handlers/WPlayAsyncMessageHandler.h"

#include "core/services/service-messages/window-service/WPlayAsyncMessage.h"
#include "core/services/ServiceManager.h"

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
	auto wPlayAsyncMessage = dynamic_cast<WPlayAsyncMessage *>(message.get());
	if (wPlayAsyncMessage == nullptr) {
		return;
	}

	auto wmediaService = ServiceManager::instance().getService<IWMediaService>();
	if (wmediaService == nullptr) {
		return;
	}
	wmediaService->playAsync();
}
