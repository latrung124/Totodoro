/*
* File: ServiceMessageConsumer.cpp
* Author: trung.la
* Date: 02-10-2025
* Description: This file contains the implementation of the ServiceMessageConsumer class.
*/

#include "ServiceMessageConsumer.h"

#include "core/handlers/service-messages/window-service/WMediaInfoMessage.h"
#include "core/handlers/ServiceMessageQueue.h"

ServiceMessageConsumer::ServiceMessageConsumer()
    : m_messageQueue(std::make_unique<ServiceMessageQueue>(this))
{
}

ServiceMessageConsumer::~ServiceMessageConsumer()
{
}

void ServiceMessageConsumer::start()
{
    m_messageQueue->start();
}

void ServiceMessageConsumer::stop()
{
    m_messageQueue->stop();
}

void ServiceMessageConsumer::enqueueMessage(ServiceMessageUPtr message)
{
    m_messageQueue->addMessage(std::move(message));
}

void ServiceMessageConsumer::handleMessage(ServiceMessageUPtr message)
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
