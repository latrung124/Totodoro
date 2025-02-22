/*
 * File: WPreviousAsyncMessage.h
 * Author: trung.la
 * Date: 02-22-2025
 * Description: This file contains the definition of the WPreviousAsyncMessage class.
 */

#ifndef WPREVIOUS_ASYNC_MESSAGE_H
#define WPREVIOUS_ASYNC_MESSAGE_H

#include "core/services/service-messages/ServiceMessage.h"

class WPreviousAsyncMessage : public ServiceMessage
{
public:
	WPreviousAsyncMessage();
	~WPreviousAsyncMessage() = default;

	bool isPreviousAsync() const;
	void setPreviousAsync(bool previousAsync);

private:
	bool m_previousAsync = false;
};

#endif // WPREVIOUS_ASYNC_MESSAGE_H
