/*
 * File: ServiceMessageConsumer.cpp
 * Author: trung.la
 * Date: 02-10-2025
 * Description: This file contains the implementation of the ServiceMessageConsumer class.
 */

#include "ServiceMessageConsumer.h"

#include "core/services/service-messages/window-service/WMediaInfoMessage.h"

ServiceMessageConsumer &ServiceMessageConsumer::getInstance()
{
	static ServiceMessageConsumer instance;
	return instance;
}

ServiceMessageConsumer::~ServiceMessageConsumer()
{
}

void ServiceMessageConsumer::consumeMessage(ServiceMessageUPtr message)
{
	if (message == nullptr) {
		return;
	}

	message->extract();
}
