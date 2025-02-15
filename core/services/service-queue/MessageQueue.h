/*
* File: MessageQueue.h
* Author: trung.la
* Date: 02-09-2025
* Description: This file contains the declaration of the MessageQueue class.
*/

#ifndef MESSAGE_QUEUE_H
#define MESSAGE_QUEUE_H

#include "core/services/service-messages/ServiceMessage.h"

#include <memory>

class MessageQueue
{
public:
    MessageQueue() = default;
    virtual ~MessageQueue() = default;

    MessageQueue(const MessageQueue&) = delete;
    MessageQueue& operator=(const MessageQueue&) = delete;
    MessageQueue(MessageQueue&&) = delete;
    MessageQueue& operator=(MessageQueue&&) = delete;

    virtual void start() = 0;
    virtual void stop() = 0;

    virtual void addMessage(std::unique_ptr<ServiceMessage> msg) = 0;
};

#endif // MESSAGE_QUEUE_H