/*
 * File: WMediaServiceHandler.cpp
 * Author: trung.la
 * Date: 02-15-2025
 * Description: This file contains the implementation of the WMediaServiceHandler class.
 */

#include "WMediaInfoMessageHandler.h"

WMediaInfoMessageHandler::WMediaInfoMessageHandler()
    : ServiceMessageHandler(ServiceMessageId::WMediaInfoMessage)
{
}

WMediaInfoMessageHandler::~WMediaInfoMessageHandler()
{
}

void WMediaInfoMessageHandler::handleMessage(ServiceMessageUPtr message)
{
	// Cast the message to WMediaInfoMessage
}
