/**
 * @file UserRouteHandler.cpp
 * @date 09-21-2025
 * @brief Route handler for user-related endpoints.
 */

#include "routes/UserRouteHandler.h"

#include <QString>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

#include "handler/JsonResponseHandler.h"
#include "processor/AsyncRequestProcessor.h"

#include "command/user/CreateUserCommand.h"
#include "command/user/GetUserCommand.h"
#include "command/user/UpdateUserCommand.h"
#include "command/user/GetSettingsCommand.h"
#include "command/user/UpdateSettingsCommand.h"

UserRouteHandler::UserRouteHandler(AsyncRequestProcessorPtr requestProcessor,
                                   const std::string& baseUrl)
{
    mRequestProcessor = requestProcessor;
    mBaseUrl = baseUrl;
    initializeRoutes();
}

void UserRouteHandler::initializeRoutes()
{
    // POST /v1/users - Create user
    mRoutePatterns.emplace_back(
        std::regex(R"(^/v1/users$)"),
        "POST",
        [this](const httplib::Request& req, httplib::Response& res) { handleCreateUser(req, res); });

    // GET /v1/users/{userId} - Get user
    mRoutePatterns.emplace_back(
        std::regex(R"(^/v1/users/([^/]+)$)"),
        "GET",
        [this](const httplib::Request& req, httplib::Response& res) { handleGetUser(req, res); });

    // PATCH /v1/users/{userId} - Update user
    mRoutePatterns.emplace_back(
        std::regex(R"(^/v1/users/([^/]+)$)"),
        "PATCH",
        [this](const httplib::Request& req, httplib::Response& res) { handleUpdateUser(req, res); });

    // GET /v1/users/{userId}/settings - Get settings
    mRoutePatterns.emplace_back(
        std::regex(R"(^/v1/users/([^/]+)/settings$)"),
        "GET",
        [this](const httplib::Request& req, httplib::Response& res) { handleGetSettings(req, res); });

    // PUT /v1/users/{userId}/settings - Update settings
    mRoutePatterns.emplace_back(
        std::regex(R"(^/v1/users/([^/]+)/settings$)"),
        "PUT",
        [this](const httplib::Request& req, httplib::Response& res) { handleUpdateSettings(req, res); });
}

void UserRouteHandler::handleRequest(const httplib::Request &req, httplib::Response &res)
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

bool UserRouteHandler::canHandle(const std::string& path, const std::string& method) const
{
    for (const auto& route : mRoutePatterns) {
        if (method == route.method && std::regex_match(path, route.pattern)) {
            return true;
        }
    }
    return false;
}

std::shared_ptr<IResponseHandler> UserRouteHandler::createResponseHandler() const
{
    return std::make_shared<JsonResponseHandler>();
}

std::string UserRouteHandler::extractPathParam(const httplib::Request& req, size_t index) const
{
    std::smatch matches;
    for (const auto& route : mRoutePatterns) {
        if (std::regex_match(req.path, matches, route.pattern) && index < matches.size()) {
            return matches[index].str();
        }
    }
    return "";
}

// ================= Handlers =================

void UserRouteHandler::handleCreateUser(const httplib::Request& req, httplib::Response& res)
{
    // Parse body into generated request model
    OpenAPI::OAIUser_serviceCreateUserRequest body;
    if (req.body.empty()) {
        res.status = 400;
        res.set_content(R"({"error":"Request body required"})", "application/json");
        return;
    }
    body.fromJson(QString::fromUtf8(req.body.data(), static_cast<int>(req.body.size())));

    auto command = std::make_shared<CreateUserCommand>(body, QString::fromStdString(mBaseUrl));
    if (!command) {
        res.status = 500;
        res.set_content(R"({"error":"Failed to create command"})", "application/json");
        return;
    }

    auto responseHandler = createResponseHandler();
    if (!responseHandler) {
        res.status = 500;
        res.set_content(R"({"error":"Failed to create response handler"})", "application/json");
        return;
    }

    command->setResponseHandler(responseHandler);
    bool success = mRequestProcessor->processCommand(command, 10000);
    if (!success) {
        qWarning() << "Failed to process CreateUserCommand";
    }

    // Optionally use command->getUser() if implemented

    res.status = responseHandler->getStatusCode();
    res.set_content(responseHandler->getResponseData().constData(), "application/json");
}

void UserRouteHandler::handleGetUser(const httplib::Request& req, httplib::Response& res)
{
    const auto userId = QString::fromStdString(extractPathParam(req, 1));
    if (userId.isEmpty()) {
        res.status = 400;
        res.set_content(R"({"error":"User ID is required"})", "application/json");
        return;
    }

    auto command = std::make_shared<GetUserCommand>(userId, QString::fromStdString(mBaseUrl));
    if (!command) {
        res.status = 500;
        res.set_content(R"({"error":"Failed to create command"})", "application/json");
        return;
    }

    auto responseHandler = createResponseHandler();
    command->setResponseHandler(responseHandler);

    bool success = mRequestProcessor->processCommand(command, 10000);
    if (!success) {
        qWarning() << "Failed to process GetUserCommand";
    }

    // QJsonObject user = command->getUser(); // If implemented, could inspect

    res.status = responseHandler->getStatusCode();
    res.set_content(responseHandler->getResponseData().constData(), "application/json");
}

void UserRouteHandler::handleUpdateUser(const httplib::Request& req, httplib::Response& res)
{
    const auto userId = QString::fromStdString(extractPathParam(req, 1));
    if (userId.isEmpty()) {
        res.status = 400;
        res.set_content(R"({"error":"User ID is required"})", "application/json");
        return;
    }

    if (req.body.empty()) {
        res.status = 400;
        res.set_content(R"({"error":"Request body required"})", "application/json");
        return;
    }

    OpenAPI::OAIUserServiceUpdateUserBody body;
    body.fromJson(QString::fromUtf8(req.body.data(), static_cast<int>(req.body.size())));

    auto command = std::make_shared<UpdateUserCommand>(body, userId, QString::fromStdString(mBaseUrl));
    if (!command) {
        res.status = 500;
        res.set_content(R"({"error":"Failed to create command"})", "application/json");
        return;
    }

    auto responseHandler = createResponseHandler();
    command->setResponseHandler(responseHandler);

    bool success = mRequestProcessor->processCommand(command, 10000);
    if (!success) {
        qWarning() << "Failed to process UpdateUserCommand";
    }

    res.status = responseHandler->getStatusCode();
    res.set_content(responseHandler->getResponseData().constData(), "application/json");
}

void UserRouteHandler::handleGetSettings(const httplib::Request& req, httplib::Response& res)
{
    const auto userId = QString::fromStdString(extractPathParam(req, 1));
    if (userId.isEmpty()) {
        res.status = 400;
        res.set_content(R"({"error":"User ID is required"})", "application/json");
        return;
    }

    auto command = std::make_shared<GetSettingsCommand>(userId, QString::fromStdString(mBaseUrl));
    if (!command) {
        res.status = 500;
        res.set_content(R"({"error":"Failed to create command"})", "application/json");
        return;
    }

    auto responseHandler = createResponseHandler();
    command->setResponseHandler(responseHandler);

    bool success = mRequestProcessor->processCommand(command, 10000);
    if (!success) {
        qWarning() << "Failed to process GetSettingsCommand";
    }

    // QJsonObject settings = command->getSettings(); // if available

    res.status = responseHandler->getStatusCode();
    res.set_content(responseHandler->getResponseData().constData(), "application/json");
}

void UserRouteHandler::handleUpdateSettings(const httplib::Request& req, httplib::Response& res)
{
    const auto userId = QString::fromStdString(extractPathParam(req, 1));
    if (userId.isEmpty()) {
        res.status = 400;
        res.set_content(R"({"error":"User ID is required"})", "application/json");
        return;
    }

    if (req.body.empty()) {
        res.status = 400;
        res.set_content(R"({"error":"Request body required"})", "application/json");
        return;
    }

    OpenAPI::OAIUserServiceUpdateSettingsBody body;
    body.fromJson(QString::fromUtf8(req.body.data(), static_cast<int>(req.body.size())));

    auto command = std::make_shared<UpdateSettingsCommand>(body, userId, QString::fromStdString(mBaseUrl));
    if (!command) {
        res.status = 500;
        res.set_content(R"({"error":"Failed to create command"})", "application/json");
        return;
    }

    auto responseHandler = createResponseHandler();
    command->setResponseHandler(responseHandler);

    bool success = mRequestProcessor->processCommand(command, 10000);
    if (!success) {
        qWarning() << "Failed to process UpdateSettingsCommand";
    }

    res.status = responseHandler->getStatusCode();
    res.set_content(responseHandler->getResponseData().constData(), "application/json");
}
