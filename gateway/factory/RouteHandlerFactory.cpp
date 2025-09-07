/**
 * @file RouteHandlerFactory.cpp
 * @author trung.la
 * @date 09-07-2025
 * @brief Implementation file for RouteHandlerFactory class that creates route handlers for the gateway module.
 */

#include "RouteHandlerFactory.h"

#include "SessionRouteHandler.h"

std::shared_ptr<IRouteHandler> RouteHandlerFactory::createHandler(
    gateway::RouteHandlerType handlerType,
    std::shared_ptr<AsyncRequestProcessor> processor,
    std::shared_ptr<IPomodoroApiClientFactory> factory,
    const std::string& baseUrl
) {
    switch (handlerType) {
        case gateway::RouteHandlerType::Session:
            return std::make_shared<SessionRouteHandler>(processor, factory, baseUrl);
            break;
        case gateway::RouteHandlerType::Task:
            // return std::make_shared<TaskRouteHandler>(processor, factory, baseUrl);
            break;
        case gateway::RouteHandlerType::User:
            // return std::make_shared<UserRouteHandler>(processor, factory, baseUrl);
            break;
        case gateway::RouteHandlerType::Notification:
            // return std::make_shared<NotificationRouteHandler>(processor, factory, baseUrl);
            break;
        default:
            return nullptr;
    }
    return nullptr;
}
