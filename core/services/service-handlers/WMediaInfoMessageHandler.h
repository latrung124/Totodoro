/*
* File: WMediaInfoMessageHandler.h
* Author: trung.la
* Date: 02-15-2025
* Description: This file contains the declaration of the WMediaInfoMessageHandler class.
*/

#ifndef WMEDIA_SERVICE_MESSAGE_HANDLER_H
#define WMEDIA_SERVICE_MESSAGE_HANDLER_H

#include "core/services/service-handlers/ServiceMessageHandler.h"

class WMediaInfoMessageHandler : public ServiceMessageHandler
{
public:
    WMediaInfoMessageHandler();
    virtual ~WMediaInfoMessageHandler();

    void handleMessage(ServiceMessageUPtr message) override;
};

#endif // WMEDIA_SERVICE_MESSAGE_HANDLER_H
