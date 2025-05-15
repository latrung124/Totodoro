/*
 * File: WTimelinePropertiesMessageCreator.cpp
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the implementation of the WTimelinePropertiesMessageCreator class.
 */

#include "core/services/producer/window-service/WTimelinePropertiesMessageCreator.h"
#include "core/services/messages/window-service/WTimelinePropertiesMessage.h"
#include "core/services/strategies/window-service/WTimelinePropertiesExtractStrategy.h"

ServiceMessageUPtr WTimelinePropertiesMessageCreator::create(ParamContainerBase *param) const
{
	return std::make_unique<WTimelinePropertiesMessage>(
	    std::make_unique<WTimelinePropertiesExtractStrategy>());
}
