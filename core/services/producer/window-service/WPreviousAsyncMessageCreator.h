/*
 * File: WPreviousAsyncMessageCreator.h
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the declaration of the WPreviousAsyncMessageCreator class.
 */

#ifndef WPREVIOUS_ASYNC_MESSAGE_CREATOR_H
#define WPREVIOUS_ASYNC_MESSAGE_CREATOR_H

#include "core/services/producer/ServiceMessageCreator.h"

class WPreviousAsyncMessageCreator : public ServiceMessageCreator
{
public:
	virtual ~WPreviousAsyncMessageCreator() = default;

	ServiceMessageUPtr create() const override;
};

#endif // WPREVIOUS_ASYNC_MESSAGE_CREATOR_H
