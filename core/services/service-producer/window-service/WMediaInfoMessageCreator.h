/*
 * File: WMediaInfoMessageCreator.h
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the declaration of the WMediaInfoMessageCreator class.
 */

#ifndef WMEDIA_INFO_MESSAGE_CREATOR_H
#define WMEDIA_INFO_MESSAGE_CREATOR_H

#include "core/services/service-producer/ServiceMessageCreator.h"

class WMediaInfoMessageCreator : public ServiceMessageCreator
{
public:
	virtual ~WMediaInfoMessageCreator() = default;

	ServiceMessageUPtr create() const override;
};

#endif // WMEDIA_INFO_MESSAGE_CREATOR_H
