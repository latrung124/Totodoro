/*
 * File: WPauseAsyncMessageCreator.cpp
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the declaration of WPauseMessageCreator class.
 */

#include "core/services/producer/window-service/WPauseAsyncMessageCreator.h"
#include "core/services/messages/window-service/WPauseAsyncMessage.h"
#include "core/services/strategies/window-service/WPauseAsyncExtractStrategy.h"

ServiceMessageUPtr WPauseAsyncMessageCreator::create() const
{
	return std::make_unique<WPauseAsyncMessage>(std::make_unique<WPauseAsyncExtractStrategy>());
}
