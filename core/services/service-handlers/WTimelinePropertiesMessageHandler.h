/*
 * File: WTimelinePropertiesMessageHandler.h
 * Author: trung.la
 * Date: 02-22-2025
 * Description: This file contains the declaration of the WTimelinePropertiesMessageHandler class.
 */

#ifndef W_TIMELINE_PROPERTIES_MESSAGE_HANDLER_H
#define W_TIMELINE_PROPERTIES_MESSAGE_HANDLER_H

#include "core/services/service-handlers/ServiceMessageHandler.h"

class WTimelinePropertiesMessageHandler : public ServiceMessageHandler
{
public:
	WTimelinePropertiesMessageHandler();
	~WTimelinePropertiesMessageHandler();

	void handleMessage(ServiceMessageUPtr message) override;
};

#endif // W_TIMELINE_PROPERTIES_MESSAGE_HANDLER_H
