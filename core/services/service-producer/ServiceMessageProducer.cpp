/*
 * File: ServiceMessageProducer.cpp
 * Author: trung.la
 * Date: 02-15-2025
 * Description: This file contains the implementation of the ServiceMessageProducer class.
 */

#include "ServiceMessageProducer.h"
#include "core/services/service-messages/ServiceMessageId.h"
#include "core/services/service-messages/window-service/WMediaInfoMessage.h"
#include "core/services/service-messages/window-service/WPlaybackControlsMessage.h"
#include "core/services/service-messages/window-service/WPlaybackInfoMessage.h"

ServiceMessageProducer &ServiceMessageProducer::getInstance()
{
	static ServiceMessageProducer instance;
	return instance;
}

ServiceMessageProducer::ServiceMessagePtr ServiceMessageProducer::produceMessage(
    ServiceMessageId messageId)
{
	switch (messageId) {
	case ServiceMessageId::WMediaInfoMessage:
		return std::make_shared<WMediaInfoMessage>();
	case ServiceMessageId::WPlaybackControlsMessage:
		return std::make_shared<WPlaybackControlsMessage>();
	case ServiceMessageId::WPlaybackInfoMessage:
		return std::make_shared<WPlaybackInfoMessage>();
	default:
		return nullptr;
	}
}
