/*
 * File: WPlaybackControlsMessageCreator.cpp
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the implementation of the WPlaybackControlsMessageCreator class.
 */

#include "core/services/service-producer/window-service/WPlaybackControlsMessageCreator.h"
#include "core/services/service-messages/window-service/WPlaybackControlsMessage.h"

ServiceMessageUPtr WPlaybackControlsMessageCreator::create() const
{
	return std::make_unique<WPlaybackControlsMessage>();
}
