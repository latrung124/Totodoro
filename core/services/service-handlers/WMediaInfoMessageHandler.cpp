/*
* File: WMediaServiceHandler.cpp
* Author: trung.la
* Date: 02-15-2025
* Description: This file contains the implementation of the WMediaServiceHandler class.
*/

#include "WMediaInfoMessageHandler.h"

WMediaServiceHandler::WMediaServiceHandler()
    : ServiceMessageHandler(ServiceMessageId::WMediaInfoMessage)
{
}

WMediaServiceHandler::~WMediaServiceHandler()
{
}

void WMediaServiceHandler::handleMessage(ServiceMessageUPtr message)
{
    // Cast the message to WMediaInfoMessage
}
