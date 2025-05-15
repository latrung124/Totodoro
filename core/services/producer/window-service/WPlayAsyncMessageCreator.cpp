/*
 * File: WPlayAsyncMessageCreator.cpp
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the implementation of the WPlayAsyncMessageCreator class.
 */

#include "core/services/producer/window-service/WPlayAsyncMessageCreator.h"
#include "core/services/messages/window-service/WPlayAsyncMessage.h"
#include "core/services/strategies/window-service/WPlayAsyncExtractStrategy.h"

ServiceMessageUPtr WPlayAsyncMessageCreator::create(ParamContainerBase *param) const
{
	return std::make_unique<WPlayAsyncMessage>(std::make_unique<WPlayAsyncExtractStrategy>());
}
