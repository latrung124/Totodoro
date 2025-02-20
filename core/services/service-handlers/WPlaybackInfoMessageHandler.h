/*
 * File: WPlaybackInfoMessageHandler.h
 * Author: trung.la
 * Date: 02-20-2025
 * Description: This file contains the declaration of the WPlaybackInfoMessageHandler class.
 */

#ifndef WPLAYBACK_INFO_MESSAGE_HANDLER_H
#define WPLAYBACK_INFO_MESSAGE_HANDLER_H

#include "core/services/service-handlers/ServiceMessageHandler.h"

class WPlaybackInfoMessageHandler : public ServiceMessageHandler
{
public:
	WPlaybackInfoMessageHandler();
	virtual ~WPlaybackInfoMessageHandler();

	void handleMessage(ServiceMessageUPtr message) override;
};

#endif // WPLAYBACK_INFO_MESSAGE_HANDLER_H
