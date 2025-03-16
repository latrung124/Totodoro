/*
 * File: WPlayAsyncMessageCreator.cpp
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the implementation of the WPlayAsyncMessageCreator class.
 */

#include "core/services/service-producer/window-service/WPlayAsyncMessageCreator.h"
#include "core/services/service-messages/window-service/WPlayAsyncMessage.h"

ServiceMessageUPtr WPlayAsyncMessageCreator::create() const
{
	return std::make_unique<WPlayAsyncMessage>();
}
