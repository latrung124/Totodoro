/*
 * File: WMediaInfoMessageCreator.cpp
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the implementation of the WMediaInfoMessageCreator class.
 */

#include "core/services/producer/window-service/WMediaInfoMessageCreator.h"
#include "core/services/messages/window-service/WMediaInfoMessage.h"
#include "core/services/strategies/window-service/WMediaInfoExtractStrategy.h"

ServiceMessageUPtr WMediaInfoMessageCreator::create() const
{
	return std::make_unique<WMediaInfoMessage>(std::make_unique<WMediaInfoExtractStrategy>());
}
