/*
 * File: WPauseAsyncMessageHandler.h
 * Author: trung.la
 * Date: 02-22-2025
 * Description: This file contains the declaration of the WPauseAsyncMessageHandler class.
 */

#ifndef WPAUSE_ASYNC_MESSAGE_HANDLER_H
#define WPAUSE_ASYNC_MESSAGE_HANDLER_H

#include "core/services/service-handlers/ServiceMessageHandler.h"

class WPauseAsyncMessageHandler : public ServiceMessageHandler
{
public:
	WPauseAsyncMessageHandler();
	virtual ~WPauseAsyncMessageHandler();

	virtual void handleMessage(ServiceMessageUPtr message) override;
};

#endif // WPAUSE_ASYNC_MESSAGE_HANDLER_H
