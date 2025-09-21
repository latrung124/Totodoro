/**
 * @file RouteHandlerFactory.cpp
 * @author trung.la
 * @date 09-07-2025
 * @brief Implementation file for RouteHandlerFactory class that creates route handlers for the gateway module.
 */

#include "RouteHandlerFactory.h"

#include "SessionRouteHandler.h"
#include "UserRouteHandler.h"
#include "TaskManagementRouteHandler.h"

std::shared_ptr<IRouteHandler> RouteHandlerFactory::createHandler(
    gateway::RouteType handlerType,
    std::shared_ptr<AsyncRequestProcessor> processor,
    std::shared_ptr<ApiClientFactory> factory,
    const std::string& baseUrl
) {
    switch (handlerType) {
        case gateway::RouteType::Session:
            return std::make_shared<SessionRouteHandler>(processor, factory, baseUrl);
            break;
        case gateway::RouteType::TaskManagement:
            return std::make_shared<TaskManagementRouteHandler>(processor, factory, baseUrl);
            break;
        case gateway::RouteType::User:
            return std::make_shared<UserRouteHandler>(processor, factory, baseUrl);
            break;
        case gateway::RouteType::Notification:
            // return std::make_shared<NotificationRouteHandler>(processor, factory, baseUrl);
            break;
        default:
            return nullptr;
    }
    return nullptr;
}
