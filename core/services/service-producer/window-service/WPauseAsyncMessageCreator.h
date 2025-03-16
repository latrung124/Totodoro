/*
 * File: WPauseAsyncMessageCreator.h
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the declaration of the WPauseAsyncMessageCreator class.
 */

#ifndef WPAUSE_ASYNC_MESSAGE_CREATOR_H
#define WPAUSE_ASYNC_MESSAGE_CREATOR_H

#include "core/services/service-producer/ServiceMessageCreator.h"

class WPauseAsyncMessageCreator : public ServiceMessageCreator
{
public:
	virtual ~WPauseAsyncMessageCreator() = default;

	ServiceMessageUPtr create() const override;
};

#endif // WPAUSE_ASYNC_MESSAGE_CREATOR_H
