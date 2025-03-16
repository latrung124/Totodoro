/*
 * File: WPreviousAsyncMessageCreator.cpp
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the implementation of the WPreviousAsyncMessageCreator class.
 */

#include "core/services/service-producer/window-service/WPreviousAsyncMessageCreator.h"
#include "core/services/service-messages/window-service/WPreviousAsyncMessage.h"
#include "core/services/service-strategies/window-service/WPreviousAsyncExtractStrategy.h"

ServiceMessageUPtr WPreviousAsyncMessageCreator::create() const
{
	return std::make_unique<WPreviousAsyncMessage>(
	    std::make_unique<WPreviousAsyncExtractStrategy>());
}
