/*
* File: WMediaServiceHandler.h
* Author: trung.la
* Date: 02-15-2025
* Description: This file contains the declaration of the WMediaServiceHandler class.
*/

#ifndef WMEDIA_SERVICE_HANDLER_H
#define WMEDIA_SERVICE_HANDLER_H

#include "core/services/service-handlers/ServiceMessageHandler.h"

class WMediaServiceHandler : public ServiceMessageHandler
{
public:
    WMediaServiceHandler();
    virtual ~WMediaServiceHandler();

    void handleMessage(ServiceMessageUPtr message) override;
};

#endif // WMEDIA_SERVICE_HANDLER_H
