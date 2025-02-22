/*
 * File: WPreviousAsyncMessageHandler.h
 * Author: trung.la
 * Date: 02-22-2025
 * Description: This file contains the declaration of the WPreviousAsyncMessageHandler class.
 */

#ifndef WPREVIOUS_ASYNC_MESSAGE_HANDLER_H
#define WPREVIOUS_ASYNC_MESSAGE_HANDLER_H

#include "core/services/service-handlers/ServiceMessageHandler.h"

class WPreviousAsyncMessageHandler : public ServiceMessageHandler
{
public:
	WPreviousAsyncMessageHandler();
	virtual ~WPreviousAsyncMessageHandler();

	virtual void handleMessage(ServiceMessageUPtr message) override;
};

#endif // WPREVIOUS_ASYNC_MESSAGE_HANDLER_H
