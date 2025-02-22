/*
 * File: WPlayAsynMessage.h
 * Author: trung.la
 * Date: 02-22-2025
 * Description: This defines class WPlayAsynMessage
 */

#ifndef W_PLAY_ASYNC_MESSAGE_H
#define W_PLAY_ASYNC_MESSAGE_H

#include "core/services/service-messages/ServiceMessage.h"

class WPlayAsyncMessage : public ServiceMessage
{
public:
	WPlayAsyncMessage();
	~WPlayAsyncMessage() = default;

	bool isPlayAsync() const;
	void setPlayAsync(bool playAsync);

private:
	bool m_playAsync = false;
};

#endif // W_PLAY_ASYNC_MESSAGE_H
