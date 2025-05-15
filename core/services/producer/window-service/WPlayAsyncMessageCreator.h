/*
 * File: WPlayAsyncMessageCreator.h
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the header of the WPlayAsyncMessageCreator class.
 */

#ifndef WPLAY_ASYNC_MESSAGE_CREATOR_H
#define WPLAY_ASYNC_MESSAGE_CREATOR_H

#include "core/services/producer/ServiceMessageCreator.h"

class WPlayAsyncMessageCreator : public ServiceMessageCreator
{
public:
	virtual ~WPlayAsyncMessageCreator() = default;

	ServiceMessageUPtr create(ParamContainerBase *param) const override;
};

#endif // WPLAY_ASYNC_MESSAGE_CREATOR_H
