/**
 * @file RouteHandlerFactory.cpp
 * @author trung.la
 * @date 09-07-2025
 * @brief Implementation file for RouteHandlerFactory class that creates route handlers for the gateway module.
 */

#include "factory/RouteHandlerFactory.h"

#include "routes/SessionRouteHandler.h"
#include "routes/UserRouteHandler.h"
#include "routes/TaskManagementRouteHandler.h"

std::shared_ptr<IRouteHandler> RouteHandlerFactory::createHandler(
    gateway::RouteType handlerType,
    std::shared_ptr<AsyncRequestProcessor> processor,
    const std::string& baseUrl
) {
    switch (handlerType) {
        case gateway::RouteType::Pomodoro:
            return std::make_shared<SessionRouteHandler>(processor, baseUrl);
            break;
        case gateway::RouteType::TaskManagement:
            return std::make_shared<TaskManagementRouteHandler>(processor, baseUrl);
            break;
        case gateway::RouteType::User:
            return std::make_shared<UserRouteHandler>(processor, baseUrl);
            break;
        case gateway::RouteType::Notification:
            // return std::make_shared<NotificationRouteHandler>(processor, baseUrl);
            break;
        default:
            return nullptr;
    }
    return nullptr;
}
