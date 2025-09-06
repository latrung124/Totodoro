/**
 * @file SessionRouteHandler.cpp
 * @author trung.la
 * @date 09-05-2025
 * @brief Route handler for Pomodoro session-related endpoints.
 */

#include "SessionRouteHandler.h"

#include "JsonResponseHandler.h"
#include "AsyncRequestProcessor.h"

#include "CreateSessionCommand.h"
#include "GetSessionByIdCommand.h"
#include "UpdateSessionCommand.h"
#include "GetSessionsCommand.h"

#include <QString>

SessionRouteHandler::SessionRouteHandler(AsyncRequestProcessorPtr requestProcessor,
                                         IPomodoroApiClientFactoryPtr apiClientFactory,
                                         const std::string& baseUrl)
{
    mRequestProcessor = requestProcessor;
    mApiClientFactory = apiClientFactory;
    mBaseUrl = baseUrl;
    initializeRoutes();
}

void SessionRouteHandler::initializeRoutes()
{
    // GET /v1/sessions/users/{userId}
    mRoutePatterns.emplace_back(
        std::regex(R"(^/v1/sessions/users/([^/]+)$)"),
        "GET",
        [this](const httplib::Request& req, httplib::Response& res) { handleGetUserSessions(req, res); });

    // POST /v1/sessions/users/{userId}
    mRoutePatterns.emplace_back(
        std::regex(R"(^/v1/sessions/users/([^/]+)$)"),
        "POST",
        [this](const httplib::Request& req, httplib::Response& res) { handleCreateSession(req, res); });

    // GET /v1/sessions/{sessionId}
    mRoutePatterns.emplace_back(
        std::regex(R"(^/v1/sessions/([^/]+)$)"),
        "GET",
        [this](const httplib::Request& req, httplib::Response& res) { handleGetSession(req, res); });

    // DELETE /v1/sessions/{sessionId}
    mRoutePatterns.emplace_back(
        std::regex(R"(^/v1/sessions/([^/]+)$)"),
        "DELETE",
        [this](const httplib::Request& req, httplib::Response& res) { handleDeleteSession(req, res); });

    // PATCH /v1/sessions/{sessionId}
    mRoutePatterns.emplace_back(
        std::regex(R"(^/v1/sessions/([^/]+)$)"),
        "PATCH",
        [this](const httplib::Request& req, httplib::Response& res) { handleUpdateSession(req, res); });
}

void SessionRouteHandler::handleRequest(const httplib::Request &req, httplib::Response &res)
{
    for (const auto& route : mRoutePatterns) {
        if (std::regex_match(req.path, route.pattern) && req.method == route.method) {
            route.handler(req, res);
            return;
        }
    }

    res.status = 404;
    res.set_content(R"({"error": "Not found"})", "application/json");
}

bool SessionRouteHandler::canHandle(const std::string& path, const std::string& method) const
{
    for (const auto& route : mRoutePatterns) {
        if (method == route.method && std::regex_match(path, route.pattern)) {
            return true;
        }
    }
    return false;
}

std::shared_ptr<IResponseHandler> SessionRouteHandler::createResponseHandler() const
{
    return std::make_shared<JsonResponseHandler>();
}

void SessionRouteHandler::handleCreateSession(const httplib::Request& req, httplib::Response& res)
{
    const auto userId = QString::fromStdString(extractPathParam(req, 1)); // 1 is the first capture group
    if (userId.isEmpty()) {
        res.status = 400;
        res.set_content(R"({"error": "User ID is required"})", "application/json");
        return;
    }

    OpenAPI::OAIPomodoroServiceCreateSessionBody body;
    const auto bodyStr = QString::fromUtf8(req.body.c_str(), static_cast<int>(req.body.size()));
    body.fromJson(bodyStr);

    auto command = std::make_shared<CreateSessionCommand>(userId, body, mApiClientFactory, QString::fromStdString(mBaseUrl));

    auto responseHandler = createResponseHandler();
    command->setResponseHandler(responseHandler);

    // Process the command - this will block until completion or timeout
    bool success = mRequestProcessor->processCommand(command, 10000);
    
    // Set the response based on the command execution
    res.status = responseHandler->getStatusCode();
    res.set_content(responseHandler->getResponseData().constData(), "application/json");
}

void SessionRouteHandler::handleGetSession(const httplib::Request& req, httplib::Response& res)
{
}

void SessionRouteHandler::handleUpdateSession(const httplib::Request& req, httplib::Response& res)
{
}

void SessionRouteHandler::handleDeleteSession(const httplib::Request& req, httplib::Response& res)
{
}

void SessionRouteHandler::handleGetUserSessions(const httplib::Request& req, httplib::Response& res)
{
}

std::string SessionRouteHandler::extractPathParam(const httplib::Request& req, size_t index) const
{
    return "";
}
