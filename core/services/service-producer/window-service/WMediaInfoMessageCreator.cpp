/*
 * File: WMediaInfoMessageCreator.cpp
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the implementation of the WMediaInfoMessageCreator class.
 */

#include "core/services/service-producer/window-service/WMediaInfoMessageCreator.h"
#include "core/services/service-messages/window-service/WMediaInfoMessage.h"

ServiceMessageUPtr WMediaInfoMessageCreator::create() const
{
	return std::make_unique<WMediaInfoMessage>();
}
