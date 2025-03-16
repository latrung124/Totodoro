/*
 * File: WPlaybackInfoMessageCreator.cpp
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the implementation of the WPlaybackInfoMessageCreator class.
 */

#include "core/services/service-producer/window-service/WPlaybackInfoMessageCreator.h"
#include "core/services/service-messages/window-service/WPlaybackInfoMessage.h"

ServiceMessageUPtr WPlaybackInfoMessageCreator::create() const
{
	return std::make_unique<WPlaybackInfoMessage>();
}
