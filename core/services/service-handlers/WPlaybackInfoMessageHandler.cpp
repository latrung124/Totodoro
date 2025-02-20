/*
 * File: WPlaybackInfoMessageHandler.cpp
 * Author: trung.la
 * Date: 02-20-2025
 * Description: This file contains the implementation of the WPlaybackInfoMessageHandler class.
 */

#include "WPlaybackInfoMessageHandler.h"

WPlaybackInfoMessageHandler::WPlaybackInfoMessageHandler()
    : ServiceMessageHandler(ServiceMessageId::WPlaybackInfoMessage)
{
}

WPlaybackInfoMessageHandler::~WPlaybackInfoMessageHandler()
{
}

void WPlaybackInfoMessageHandler::handleMessage(ServiceMessageUPtr message)
{
	// Cast the message to WPlaybackInfoMessage
}
