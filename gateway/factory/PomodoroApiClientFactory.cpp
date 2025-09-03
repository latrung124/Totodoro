/**
 * @file PomodoroApiClientFactory.h
 * @author trung.la
 * @date 09-03-2025
 * @brief Implementation of factory for creating Pomodoro API client instances.
 */

#include "PomodoroApiClientFactory.h"

std::shared_ptr<OpenAPI::OAIPomodoroServiceApi> PomodoroApiClientFactory::createClient(const QString& baseUrl)
{
    auto client = std::make_shared<OpenAPI::OAIPomodoroServiceApi>();
    return client;
}