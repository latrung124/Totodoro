/*
 * File: WNextAsyncMessageHandler.h
 * Author: trung.la
 * Date: 02-22-2025
 * Description: This file contains the declaration of the WNextAsyncMessageHandler class.
 */

#ifndef WNEXT_ASYNC_MESSAGE_HANDLER_H
#define WNEXT_ASYNC_MESSAGE_HANDLER_H

#include "core/services/service-handlers/ServiceMessageHandler.h"

class WNextAsyncMessageHandler : public ServiceMessageHandler
{
public:
	WNextAsyncMessageHandler();
	virtual ~WNextAsyncMessageHandler();

	virtual void handleMessage(ServiceMessageUPtr message) override;
};

#endif // WNEXT_ASYNC_MESSAGE_HANDLER_H
