/*
File: WMediaServiceHandler.h
* Author: trung.la
* Date: 02-10-2025
* Description: This file contains the declaration of the WMediaServiceHandler class.
*/

#ifndef W_MEDIA_SERVICE_HANDLER_H
#define W_MEDIA_SERVICE_HANDLER_H

#include "core/handlers/ServiceHandler.h"

#include <memory>

class ServiceMessage;
class ServiceConsumer;

class WMediaServiceHandler : public ServiceHandler
{
public:
    using ServiceMessageUPtr = std::unique_ptr<ServiceMessage>;
    using ServiceConsumerUPtr = std::unique_ptr<ServiceConsumer>;

    virtual ~WMediaServiceHandler();
    static WMediaServiceHandler& getInstance();

    void start();
    void stop();

    void enqueueMessage(ServiceMessageUPtr message);
    void processMessage(ServiceMessageUPtr message);

private:
    WMediaServiceHandler();
    ServiceConsumerUPtr m_serviceConsumer = nullptr;
};

#endif // W_MEDIA_SERVICE_HANDLER_H