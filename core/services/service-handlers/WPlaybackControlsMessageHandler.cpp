/*
 * File: WPlaybackControlsMessageHandler.cpp
 * Author: trung.la
 * Date: 02-20-2025
 * Description: This file contains the implementation of the WPlaybackControlsMessageHandler class.
 */

#include "WPlaybackControlsMessageHandler.h"

WPlaybackControlsMessageHandler::WPlaybackControlsMessageHandler()
    : ServiceMessageHandler(ServiceMessageId::WPlaybackControlsMessage)
{
}

WPlaybackControlsMessageHandler::~WPlaybackControlsMessageHandler()
{
}

void WPlaybackControlsMessageHandler::handleMessage(ServiceMessageUPtr message)
{
	// Cast the message to WPlaybackControlsMessage
}
