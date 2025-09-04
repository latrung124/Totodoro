/**
 * @file PomodoroApiClientFactory.h
 * @author trung.la
 * @date 09-03-2025
 * @brief Factory for creating Pomodoro API client instances.
 */

#pragma once

#include "IPomodoroApiClientFactory.h"

class PomodoroApiClientFactory : public IPomodoroApiClientFactory
{
public:
    std::unique_ptr<OpenAPI::OAIPomodoroServiceApi> createClient(const QString& baseUrl) override;
};