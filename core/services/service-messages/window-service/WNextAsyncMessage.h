/*
 * File: WNextAsyncMessage.h
 * Author: trung.la
 * Date: 02-22-2025
 * Description: This defines class WNextAsyncMessage
 */

#ifndef W_NEXT_ASYNC_MESSAGE_H
#define W_NEXT_ASYNC_MESSAGE_H

#include "core/services/service-messages/ServiceMessage.h"

class WNextAsyncMessage : public ServiceMessage
{
public:
	WNextAsyncMessage();
	~WNextAsyncMessage() = default;
};

#endif // W_NEXT_ASYNC_MESSAGE_H
