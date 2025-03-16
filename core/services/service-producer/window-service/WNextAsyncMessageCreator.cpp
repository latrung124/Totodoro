/*
 * File: WNextAsyncMessageCreator.cpp
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the implementation of the WNextAsyncMessageCreator class.
 */

#include "core/services/service-producer/window-service/WNextAsyncMessageCreator.h"
#include "core/services/service-messages/window-service/WNextAsyncMessage.h"
#include "core/services/service-strategies/window-service/WNextAsyncExtractStrategy.h"

ServiceMessageUPtr WNextAsyncMessageCreator::create() const
{
	return std::make_unique<WNextAsyncMessage>(std::make_unique<WNextAsyncExtractStrategy>());
}
