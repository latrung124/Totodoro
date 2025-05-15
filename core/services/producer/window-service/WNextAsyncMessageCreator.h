/*
 * File: WNextAsyncMessageCreator.h
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the declaration of the WNextAsyncMessageCreator class.
 */

#ifndef WNEXT_ASYNC_MESSAGE_CREATOR_H
#define WNEXT_ASYNC_MESSAGE_CREATOR_H

#include "core/services/producer/ServiceMessageCreator.h"

class WNextAsyncMessageCreator : public ServiceMessageCreator
{
public:
	virtual ~WNextAsyncMessageCreator() = default;

	ServiceMessageUPtr create(ParamContainerBase *param) const override;
};

#endif // WNEXT_ASYNC_MESSAGE_CREATOR_H
