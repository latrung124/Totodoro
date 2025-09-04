/**
 * @file PomodoroApiClientFactory.h
 * @author trung.la
 * @date 09-03-2025
 * @brief Implementation of factory for creating Pomodoro API client instances.
 */

#include "PomodoroApiClientFactory.h"

std::unique_ptr<OpenAPI::OAIPomodoroServiceApi> PomodoroApiClientFactory::createClient(const QString& baseUrl)
{
    return std::make_unique<OpenAPI::OAIPomodoroServiceApi>();
}