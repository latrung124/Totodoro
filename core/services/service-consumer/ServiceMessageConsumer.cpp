/*
 * File: ServiceMessageConsumer.cpp
 * Author: trung.la
 * Date: 02-10-2025
 * Description: This file contains the implementation of the ServiceMessageConsumer class.
 */

#include "ServiceMessageConsumer.h"

#include "core/services/service-handlers/WMediaInfoMessageHandler.h"
#include "core/services/service-messages/window-service/WMediaInfoMessage.h"

ServiceMessageConsumer &ServiceMessageConsumer::getInstance()
{
	static ServiceMessageConsumer instance;
	return instance;
}

ServiceMessageConsumer::~ServiceMessageConsumer()
{
}

void ServiceMessageConsumer::addHandler(std::unique_ptr<ServiceMessageHandler> handler)
{
	m_handlers[handler->getId()] = std::move(handler);
}

void ServiceMessageConsumer::consumeMessage(ServiceMessageUPtr message)
{
	if (message == nullptr) {
		return;
	}

	auto id = message->getId();
	if (m_handlers.find(id) == m_handlers.end()) {
		return;
	}
	m_handlers[id]->handleMessage(std::move(message));
}
