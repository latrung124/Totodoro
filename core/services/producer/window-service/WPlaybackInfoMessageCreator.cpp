/*
 * File: WPlaybackInfoMessageCreator.cpp
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the implementation of the WPlaybackInfoMessageCreator class.
 */

#include "core/services/producer/window-service/WPlaybackInfoMessageCreator.h"
#include "core/services/messages/window-service/WPlaybackInfoMessage.h"
#include "core/services/strategies/window-service/WPlaybackInfoExtractStrategy.h"

ServiceMessageUPtr WPlaybackInfoMessageCreator::create() const
{
	return std::make_unique<WPlaybackInfoMessage>(std::make_unique<WPlaybackInfoExtractStrategy>());
}
