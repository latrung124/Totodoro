/*
 * File: WNextAsyncMessageCreator.cpp
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the implementation of the WNextAsyncMessageCreator class.
 */

#include "core/services/producer/window-service/WNextAsyncMessageCreator.h"
#include "core/services/messages/window-service/WNextAsyncMessage.h"
#include "core/services/strategies/window-service/WNextAsyncExtractStrategy.h"

ServiceMessageUPtr WNextAsyncMessageCreator::create(ParamContainerBase *param) const
{
	return std::make_unique<WNextAsyncMessage>(std::make_unique<WNextAsyncExtractStrategy>());
}
