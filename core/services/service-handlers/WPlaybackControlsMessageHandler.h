/*
 * File: WPlaybackControlsMessageHandler.h
 * Author: trung.la
 * Date: 02-20-2025
 * Description: This file contains the declaration of the WPlaybackControlsMessageHandler class.
 */

#ifndef WPLAYBACK_CONTROLS_MESSAGE_HANDLER_H
#define WPLAYBACK_CONTROLS_MESSAGE_HANDLER_H

#include "core/services/service-handlers/ServiceMessageHandler.h"

class WPlaybackControlsMessageHandler : public ServiceMessageHandler
{
public:
	WPlaybackControlsMessageHandler();
	virtual ~WPlaybackControlsMessageHandler();

	void handleMessage(ServiceMessageUPtr message) override;
};

#endif // WPLAYBACK_CONTROLS_MESSAGE_HANDLER_H
