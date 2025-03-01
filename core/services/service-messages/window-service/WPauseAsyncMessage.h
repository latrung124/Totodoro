/*
 * File: WPauseAsyncMessage.h
 * Author: trung.la
 * Date: 02-22-2025
 * Description: This defines class WPauseAsyncMessage
 */

#ifndef W_PAUSE_ASYNC_MESSAGE_H
#define W_PAUSE_ASYNC_MESSAGE_H

#include "core/services/service-messages/ServiceMessage.h"

class WPauseAsyncMessage : public ServiceMessage
{
public:
	WPauseAsyncMessage();
	~WPauseAsyncMessage() = default;
};

#endif // W_PAUSE_ASYNC_MESSAGE_H
