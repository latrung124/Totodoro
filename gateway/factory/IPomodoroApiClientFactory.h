/**
 * @file IPomodoroApiClientFactory.h
 * @author trung.la
 * @date 09-03-2025
 * @brief Interface for creating Pomodoro API client instances.
 */

#pragma once

#include <memory>

#include <QString>

#include <OAIPomodoroServiceApi.h>

class IPomodoroApiClientFactory
{
public:
    virtual ~IPomodoroApiClientFactory() = default;

    // Create and return a new instance of OAIPomodoroServiceApi
    virtual std::shared_ptr<OpenAPI::OAIPomodoroServiceApi> createClient(const QString& baseUrl) = 0;
};

using IPomodoroApiClientFactoryPtr = std::shared_ptr<IPomodoroApiClientFactory>;