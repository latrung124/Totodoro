/*
* File: WMediaServiceConsumer.h
* Author: trung.la
* Date: 02-10-2025
* Description: This file contains the declaration of the WMediaServiceConsumer class.
*/

#ifndef W_MEDIA_SERVICE_CONSUMER_H
#define W_MEDIA_SERVICE_CONSUMER_H

#include "core/handlers/service-consumers/ServiceConsumer.h"

#include <mutex>
#include <condition_variable>
#include <queue>
#include <memory>

class WMediaServiceHandler;

class WMediaServiceConsumer : public ServiceConsumer
{
public:
    using ServiceMessageUPtr = std::unique_ptr<ServiceMessage>;

    WMediaServiceConsumer(WMediaServiceHandler* handler);
    ~WMediaServiceConsumer() override;

    WMediaServiceConsumer(const WMediaServiceConsumer&) = delete;
    WMediaServiceConsumer& operator=(const WMediaServiceConsumer&) = delete;
    WMediaServiceConsumer(WMediaServiceConsumer&&) = delete;
    WMediaServiceConsumer& operator=(WMediaServiceConsumer&&) = delete;

    virtual void start() override;
    virtual void stop() override;

    virtual void addMessage(ServiceMessageUPtr msg) override;

private:
    void loop();
    bool canConsume();

    void processMessage(ServiceMessageUPtr message);

    mutable std::mutex m_mutex;
    std::thread m_looper;
    std::condition_variable m_conditionVariable;
    std::queue<ServiceMessageUPtr> m_messageQueue;
    bool m_isRunning;
    WMediaServiceHandler* m_handler = nullptr;
};

#endif // W_MEDIA_SERVICE_CONSUMER_H