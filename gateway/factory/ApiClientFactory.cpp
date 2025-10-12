/**
 * @file factory/ApiClientFactory.h
 * @author trung.la
 * @date 09-03-2025
 * @brief Implementation of factory for creating API client instances.
 */

#include "factory/ApiClientFactory.h"

#include "OAIPomodoroServiceApi.h"
#include "OAITaskManagementServiceApi.h"
#include "OAIUserServiceApi.h"

std::unique_ptr<QObject> ApiClientFactory::createClient(gateway::RouteType routeType, const QString& baseUrl)
{
    if (routeType == gateway::RouteType::Pomodoro) {
        return std::make_unique<OpenAPI::OAIPomodoroServiceApi>();
    }

    if (routeType == gateway::RouteType::TaskManagement) {
        return std::make_unique<OpenAPI::OAITaskManagementServiceApi>();
    }

    if (routeType == gateway::RouteType::User) {
        return std::make_unique<OpenAPI::OAIUserServiceApi>();
    }

    return nullptr;
}
