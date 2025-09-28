/**
 * @file SessionRouteHandler.cpp
 * @author trung.la
 * @date 09-05-2025
 * @brief Route handler for Pomodoro session-related endpoints.
 */

#include "SessionRouteHandler.h"

#include <QString>

#include "JsonResponseHandler.h"
#include "AsyncRequestProcessor.h"

#include "CreateSessionCommand.h"
#include "GetSessionByIdCommand.h"
#include "UpdateSessionCommand.h"
#include "GetSessionsCommand.h"
#include "DeleteSessionCommand.h"

SessionRouteHandler::SessionRouteHandler(AsyncRequestProcessorPtr requestProcessor,
                                         const std::string& baseUrl)
{
    mRequestProcessor = requestProcessor;
    mBaseUrl = baseUrl;
    initializeRoutes();
}

void SessionRouteHandler::initializeRoutes()
{
    // GET /v1/sessions/users/{userId} - List all sessions for a user
    mRoutePatterns.emplace_back(
        std::regex(R"(^/v1/sessions/users/([^/]+)$)"),
        "GET",
        [this](const httplib::Request& req, httplib::Response& res) { handleGetUserSessions(req, res); });

    // POST /v1/sessions/users/{userId} - Create a new session
    mRoutePatterns.emplace_back(
        std::regex(R"(^/v1/sessions/users/([^/]+)$)"),
        "POST",
        [this](const httplib::Request& req, httplib::Response& res) { handleCreateSession(req, res); });

    // GET /v1/sessions/{sessionId} - Get a session by ID
    mRoutePatterns.emplace_back(
        std::regex(R"(^/v1/sessions/([^/]+)$)"),
        "GET",
        [this](const httplib::Request& req, httplib::Response& res) { handleGetSession(req, res); });

    // DELETE /v1/sessions/{sessionId} - Delete a session
    mRoutePatterns.emplace_back(
        std::regex(R"(^/v1/sessions/([^/]+)$)"),
        "DELETE",
        [this](const httplib::Request& req, httplib::Response& res) { handleDeleteSession(req, res); });

    // PATCH /v1/sessions/{sessionId} - Update a session
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

    auto command = std::make_shared<CreateSessionCommand>(userId, body, QString::fromStdString(mBaseUrl));

    auto responseHandler = createResponseHandler();
    command->setResponseHandler(responseHandler);

    // Process the command - this will block until completion or timeout
    bool success = mRequestProcessor->processCommand(command, 10000);

    if (!success) {
        qWarning() << "Failed to process CreateSessionCommand";
    }

    QJsonObject session = command->getSession();
    if (session.isEmpty()) {
        qWarning() << "No session data returned from CreateSessionCommand";
    }
    // TODO: Send the JSON response to Model layer

    
    // Set the response based on the command execution
    res.status = responseHandler->getStatusCode();
    res.set_content(responseHandler->getResponseData().constData(), "application/json");
}

void SessionRouteHandler::handleGetSession(const httplib::Request& req, httplib::Response& res)
{
    const auto sessionId = QString::fromStdString(extractPathParam(req, 1)); // 1 is the first capture group
    if (sessionId.isEmpty()) {
        res.status = 400;
        res.set_content(R"({"error": "Session ID is required"})", "application/json");
        return;
    }

    auto command = std::make_shared<GetSessionByIdCommand>(sessionId, QString::fromStdString(mBaseUrl));

    auto responseHandler = createResponseHandler();
    command->setResponseHandler(responseHandler);

    // Process the command - this will block until completion or timeout
    bool success = mRequestProcessor->processCommand(command, 10000);
    if (!success) {
        qWarning() << "Failed to process GetSessionByIdCommand";
    }

    QJsonObject session = command->getSession();
    if (session.isEmpty()) {
        qWarning() << "No session data returned from GetSessionByIdCommand";
    }
    // TODO: Send the JSON response to Model layer
    
    // Set the response based on the command execution
    res.status = responseHandler->getStatusCode();
    res.set_content(responseHandler->getResponseData().constData(), "application/json");
}

void SessionRouteHandler::handleUpdateSession(const httplib::Request& req, httplib::Response& res)
{
    const auto sessionId = QString::fromStdString(extractPathParam(req, 1)); // 1 is the first capture group
    if (sessionId.isEmpty()) {
        res.status = 400;
        res.set_content(R"({"error": "Session ID is required"})", "application/json");
        return;
    }

    OpenAPI::OAIPomodoroServiceUpdateSessionBody body;
    const auto bodyStr = QString::fromUtf8(req.body.c_str(), static_cast<int>(req.body.size()));
    body.fromJson(bodyStr);

    auto command = std::make_shared<UpdateSessionCommand>(body, sessionId, QString::fromStdString(mBaseUrl));
    auto responseHandler = createResponseHandler();
    command->setResponseHandler(responseHandler);

    // Process the command - this will block until completion or timeout
    bool success = mRequestProcessor->processCommand(command, 10000);
    if (!success) {
        qWarning() << "Failed to process UpdateSessionCommand";
    }

    // Set the response based on the command execution
    res.status = responseHandler->getStatusCode();
    res.set_content(responseHandler->getResponseData().constData(), "application/json");
}

void SessionRouteHandler::handleDeleteSession(const httplib::Request& req, httplib::Response& res)
{
    const auto sessionId = QString::fromStdString(extractPathParam(req, 1)); // 1 is the first capture group
    if (sessionId.isEmpty()) {
        res.status = 400;
        res.set_content(R"({"error": "Session ID is required"})", "application/json");
        return;
    }

    auto command = std::make_shared<DeleteSessionCommand>(sessionId, QString::fromStdString(mBaseUrl));
    auto responseHandler = createResponseHandler();
    command->setResponseHandler(responseHandler);

    // Process the command - this will block until completion or timeout
    bool success = mRequestProcessor->processCommand(command, 10000);
    if (!success) {
        qWarning() << "Failed to process DeleteSessionCommand";
    }

    bool isDeleted = command->isDeleted();
    if (!isDeleted) {
        qWarning() << "Session was not deleted successfully";
    }
    // TODO: Send the bool to Model layer

    // Set the response based on the command execution
    res.status = responseHandler->getStatusCode();
    res.set_content(responseHandler->getResponseData().constData(), "application/json");
}

void SessionRouteHandler::handleGetUserSessions(const httplib::Request& req, httplib::Response& res)
{
    const auto userId = QString::fromStdString(extractPathParam(req, 1));
    if (userId.isEmpty()) {
        res.status = 400;
        res.set_content(R"({"error":"Missing userId"})", "application/json");
        return;
    }

    // Extract optional taskId query parameter
    QString taskId;
    auto taskIdIt = req.params.find("taskId");
    if (taskIdIt != req.params.end()) {
        taskId = QString::fromStdString(taskIdIt->second);
    }

    auto command = std::make_shared<GetSessionsCommand>(
        userId, taskId, QString::fromStdString(mBaseUrl)
    );

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

    // Process the command - this will block until completion or timeout
    bool success = mRequestProcessor->processCommand(command, 10000);

    if (success) {
        QList<QVariantMap> sessions = command->getSessions();

        QJsonObject responseJson;
        QJsonArray sessionsArray;
        
        for (const QVariantMap& session : sessions) {
            sessionsArray.append(QJsonObject::fromVariantMap(session));
        }
        
        responseJson["sessions"] = sessionsArray;
        //TODO: Send the JSON response to Model layer
    }

    // Set the response based on the command execution
    res.status = responseHandler->getStatusCode();
    res.set_content(responseHandler->getResponseData().constData(), "application/json");
}

std::string SessionRouteHandler::extractPathParam(const httplib::Request& req, size_t index) const
{
    std::smatch matches;
    for (const auto& route : mRoutePatterns) {
        if (std::regex_match(req.path, matches, route.pattern) && index < matches.size()) {
            return matches[index].str();
        }
    }
    return "";
}
