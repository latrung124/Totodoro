/*
* File: ServiceConsumer.h
* Author: trung.la
* Date: 02-09-2025
* Description: This file contains the declaration of the ServiceConsumer class.
*/

#ifndef SERVICE_CONSUMER_H
#define SERVICE_CONSUMER_H

#include "core/handlers/service-messages/ServiceMessage.h"

#include <memory>

class ServiceConsumer
{
public:
    ServiceConsumer() = default;
    virtual ~ServiceConsumer() = default;

    ServiceConsumer(const ServiceConsumer&) = delete;
    ServiceConsumer& operator=(const ServiceConsumer&) = delete;
    ServiceConsumer(ServiceConsumer&&) = delete;
    ServiceConsumer& operator=(ServiceConsumer&&) = delete;

    virtual void start() = 0;
    virtual void stop() = 0;

    virtual void addMessage(std::unique_ptr<ServiceMessage> msg) = 0;
};

#endif // SERVICE_CONSUMER_H