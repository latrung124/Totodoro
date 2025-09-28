/**
 * File: PomodoroOpenApiController.cpp
 * Author: trung.la
 * Date: 09-02-2025
 * Description: Implementation file for PomodoroOpenApiController class that handles Pomodoro-related API endpoints.
 */

#include "PomodoroOpenApiController.h"

#include <QDebug>

#include "RouteHandlerFactory.h"

namespace gateway {

PomodoroOpenApiController::PomodoroOpenApiController(AsyncRequestProcessorPtr requestProcessor,
                                                     const std::string& baseUrl)
{
    initializeHandlers(requestProcessor, baseUrl);
}

void PomodoroOpenApiController::initializeHandlers(AsyncRequestProcessorPtr requestProcessor,
                                                   const std::string& baseUrl)
{
    auto sessionHandler = RouteHandlerFactory::createHandler(
        gateway::RouteType::Pomodoro,
        requestProcessor,
        baseUrl
    );
    mRouter.addHandler(sessionHandler);
}

void PomodoroOpenApiController::registerRoutes(httplib::Server& server)
{
    // Catch-all handler that delegates to the router
    server.Post(".*", [this](const httplib::Request& req, httplib::Response& res) {
        mRouter.handleRequest(req, res);
    });
    
    server.Get(".*", [this](const httplib::Request& req, httplib::Response& res) {
        mRouter.handleRequest(req, res);
    });
    
    server.Put(".*", [this](const httplib::Request& req, httplib::Response& res) {
        mRouter.handleRequest(req, res);
    });
    
    server.Delete(".*", [this](const httplib::Request& req, httplib::Response& res) {
        mRouter.handleRequest(req, res);
    });
}

}
