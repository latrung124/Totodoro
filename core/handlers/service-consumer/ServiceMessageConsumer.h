/*
File: ServiceMessageConsumer.h
* Author: trung.la
* Date: 02-10-2025
* Description: This file contains the declaration of the ServiceMessageConsumer class.
*/

#ifndef SERVICE_MESSAGE_CONSUMER_H
#define SERVICE_MESSAGE_CONSUMER_H

#include "core/handlers/service-consumer/ServiceConsumer.h"

#include <memory>

class ServiceMessage;
class MessageQueue;

class ServiceMessageConsumer : public ServiceConsumer
{
public:
    using ServiceMessageUPtr = std::unique_ptr<ServiceMessage>;
    using MessageQueueUPtr = std::unique_ptr<MessageQueue>;

    ServiceMessageConsumer();
    virtual ~ServiceMessageConsumer();

    void start();
    void stop();

    void enqueueMessage(ServiceMessageUPtr message);
    void handleMessage(ServiceMessageUPtr message);

private:
    MessageQueueUPtr m_messageQueue = nullptr;
};

#endif // SERVICE_MESSAGE_CONSUMER_H
