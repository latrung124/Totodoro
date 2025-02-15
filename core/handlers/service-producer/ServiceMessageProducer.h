/*
* File: ServiceMessageProducer.h
* Author: trung.la
* Date: 02-15-2025
* Description: This file contains the declaration of the ServiceMessageProducer class.
*/

#ifndef SERVICE_MESSAGE_PRODUCER_H
#define SERVICE_MESSAGE_PRODUCER_H

#include <memory>

class ServiceMessage;
enum class ServiceMessageId : uint16_t;

class ServiceMessageProducer
{
public:
    using ServiceMessagePtr = std::shared_ptr<ServiceMessage>;
    static ServiceMessageProducer& getInstance();
    virtual ~ServiceMessageProducer() = default;

    [[nodiscard]] ServiceMessagePtr produceMessage(ServiceMessageId messageId);

private:
    ServiceMessageProducer() = default;
};

#endif // SERVICE_MESSAGE_PRODUCER_H