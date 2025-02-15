/*
File: ServiceMessageConsumer.h
* Author: trung.la
* Date: 02-10-2025
* Description: This file contains the declaration of the ServiceMessageConsumer class.
*/

#ifndef SERVICE_MESSAGE_CONSUMER_H
#define SERVICE_MESSAGE_CONSUMER_H

#include "core/services/service-consumer/ServiceConsumer.h"
#include "core/services/service-messages/ServiceMessage.h"

#include <memory>
#include <map>

class ServiceMessage;
class ServiceMessageHandler;

class ServiceMessageConsumer : public ServiceConsumer
{
public:
    using ServiceMessageUPtr = std::unique_ptr<ServiceMessage>;

    ServiceMessageConsumer();
    virtual ~ServiceMessageConsumer();

    void consumeMessage(ServiceMessageUPtr message);

    void addHandler(std::unique_ptr<ServiceMessageHandler> handler);

private:
    std::map<ServiceMessageId, std::unique_ptr<ServiceMessageHandler>> m_handlers;
};

#endif // SERVICE_MESSAGE_CONSUMER_H
