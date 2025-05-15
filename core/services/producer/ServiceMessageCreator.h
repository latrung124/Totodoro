/*
 * File: ServiceMessageCreator.h
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the declaration of the ServiceMessageCreator class.
 */

#ifndef SERVICE_MESSAGE_CREATOR_H
#define SERVICE_MESSAGE_CREATOR_H

#include "core/factories/ParamContainer.h"
#include "core/services/messages/Message.h"

class ServiceMessageCreator
{
public:
	using ParamContainerBase = core::factories::ParamContainerBase;

	ServiceMessageCreator() = default;
	virtual ~ServiceMessageCreator() = default;

	virtual ServiceMessageUPtr create(ParamContainerBase *param) const = 0;
};

#endif // SERVICE_MESSAGE_CREATOR_H
