/*
 * File: WTimelinePropertiesMessageHandler.cpp
 * Author: trung.la
 * Date: 02-22-2025
 * Description: This file contains the implementation of the WTimelinePropertiesMessageHandler class.
 */

#include "WTimelinePropertiesMessageHandler.h"

#include "core/services/service-messages/window-service/WTimelinePropertiesMessage.h"

WTimelinePropertiesMessageHandler::WTimelinePropertiesMessageHandler()
    : ServiceMessageHandler(ServiceMessageId::WTimelinePropertiesMessage)
{
}

WTimelinePropertiesMessageHandler::~WTimelinePropertiesMessageHandler()
{
}

void WTimelinePropertiesMessageHandler::handleMessage(ServiceMessageUPtr message)
{
	// Cast the message to WTimelinePropertiesMessage
}
