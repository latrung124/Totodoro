/*
 * File: WPlayAsyncMessageHandler.h
 * Author: trung.la
 * Date: 02-22-2025
 * Description: This file contains the declaration of the WPlayAsyncMessageHandler class.
 */

#ifndef WPLAY_ASYNC_MESSAGE_HANDLER_H
#define WPLAY_ASYNC_MESSAGE_HANDLER_H

#include "core/services/service-handlers/ServiceMessageHandler.h"

class WPlayAsyncMessageHandler : public ServiceMessageHandler
{
public:
	WPlayAsyncMessageHandler();
	virtual ~WPlayAsyncMessageHandler();

	void handleMessage(ServiceMessageUPtr message) override;
};
#endif // WPLAY_ASYNC_MESSAGE_HANDLER_H
