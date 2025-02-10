/*
* File: WMediaServiceHandler.cpp
* Author: trung.la
* Date: 02-10-2025
* Description: This file contains the implementation of the WMediaServiceHandler class.
*/

#include "WMediaServiceHandler.h"

#include "core/handlers/service-messages/window-service/WMediaInfoMessage.h"
#include "core/handlers/service-consumers/window-service/WMediaServiceConsumer.h"

WMediaServiceHandler::WMediaServiceHandler()
    : m_serviceConsumer(std::make_unique<WMediaServiceConsumer>(this))
{
}

WMediaServiceHandler::~WMediaServiceHandler()
{
}

void WMediaServiceHandler::start()
{
    m_serviceConsumer->start();
}

void WMediaServiceHandler::stop()
{
    m_serviceConsumer->stop();
}

void WMediaServiceHandler::enqueueMessage(ServiceMessageUPtr message)
{
    m_serviceConsumer->addMessage(std::move(message));
}

void WMediaServiceHandler::processMessage(ServiceMessageUPtr message)
{
    if (!message) {
        return;
    }

    ServiceMessageId messageId = message->getId();
    switch (messageId)
    {
    case ServiceMessageId::WMediaInfoMessage: {
        // Process WMediaInfoMessage
        break;
    }
    default:
        break;
    }
}