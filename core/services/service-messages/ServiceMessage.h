/*
* File: ServiceMessage.h
* Author: trung.la
* Date: 02-09-2025
* Description: Service message class
*/

#ifndef SERVICE_MESSAGE_H
#define SERVICE_MESSAGE_H

#include "core/services/service-messages/ServiceMessageId.h"

class ServiceMessage
{
public:
    ServiceMessage(const ServiceMessageId& id) : m_id(id) {}
    ServiceMessage() = delete;
    virtual ~ServiceMessage() = default;

    ServiceMessageId getId() const { return m_id; }

private:
    ServiceMessageId m_id = ServiceMessageId::None;
};

#endif // SERVICE_MESSAGE_H
