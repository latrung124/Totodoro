/*
 * File: WPlaybackInfoMessageCreator.h
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the header of the WPlaybackInfoMessageCreator class.
 */

#ifndef WPLAYBACK_INFO_MESSAGE_CREATOR_H
#define WPLAYBACK_INFO_MESSAGE_CREATOR_H

#include "core/services/service-producer/ServiceMessageCreator.h"

class WPlaybackInfoMessageCreator : public ServiceMessageCreator
{
public:
	virtual ~WPlaybackInfoMessageCreator() = default;

	ServiceMessageUPtr create() const override;
};

#endif // WPLAYBACK_INFO_MESSAGE_CREATOR_H
