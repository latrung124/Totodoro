/*
 * File: WTimelinePropertiesMessageCreator.cpp
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the implementation of the WTimelinePropertiesMessageCreator class.
 */

#include "core/services/service-producer/window-service/WTimelinePropertiesMessageCreator.h"
#include "core/services/service-messages/window-service/WTimelinePropertiesMessage.h"

ServiceMessageUPtr WTimelinePropertiesMessageCreator::create() const
{
	return std::make_unique<WTimelinePropertiesMessage>();
}
