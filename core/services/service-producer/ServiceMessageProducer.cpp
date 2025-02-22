/*
 * File: ServiceMessageProducer.cpp
 * Author: trung.la
 * Date: 02-15-2025
 * Description: This file contains the implementation of the ServiceMessageProducer class.
 */

#include "ServiceMessageProducer.h"
#include "core/services/service-messages/ServiceMessageId.h"
#include "core/services/service-messages/window-service/WMediaInfoMessage.h"
#include "core/services/service-messages/window-service/WNextAsyncMessage.h"
#include "core/services/service-messages/window-service/WPauseAsyncMessage.h"
#include "core/services/service-messages/window-service/WPlayAsyncMessage.h"
#include "core/services/service-messages/window-service/WPlaybackControlsMessage.h"
#include "core/services/service-messages/window-service/WPlaybackInfoMessage.h"
#include "core/services/service-messages/window-service/WPreviousAsyncMessage.h"
#include "core/services/service-messages/window-service/WTimelinePropertiesMessage.h"

ServiceMessageProducer &ServiceMessageProducer::getInstance()
{
	static ServiceMessageProducer instance;
	return instance;
}

ServiceMessageProducer::ServiceMessageUPtr ServiceMessageProducer::produce(
    ServiceMessageId messageId)
{
	switch (messageId) {
	case ServiceMessageId::WMediaInfoMessage:
		return std::make_unique<WMediaInfoMessage>();
	case ServiceMessageId::WPlaybackControlsMessage:
		return std::make_unique<WPlaybackControlsMessage>();
	case ServiceMessageId::WPlaybackInfoMessage:
		return std::make_unique<WPlaybackInfoMessage>();
	case ServiceMessageId::WTimelinePropertiesMessage:
		return std::make_unique<WTimelinePropertiesMessage>();
	case ServiceMessageId::WPlayAsyncMessage:
		return std::make_unique<WPlayAsyncMessage>();
	case ServiceMessageId::WPauseAsyncMessage:
		return std::make_unique<WPauseAsyncMessage>();
	case ServiceMessageId::WNextAsyncMessage:
		return std::make_unique<WNextAsyncMessage>();
	case ServiceMessageId::WPreviousAsyncMessage:
		return std::make_unique<WPreviousAsyncMessage>();
	default:
		return nullptr;
	}
}
