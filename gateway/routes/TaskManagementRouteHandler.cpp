/**
 * @file TaskManagementRouteHandler.cpp
 * @author trung.la
 * @date 09-21-2025
 * @brief Route handler for task management-related endpoints.
 */

#include "routes/TaskManagementRouteHandler.h"

#include <QString>

#include "handler/JsonResponseHandler.h"
#include "processor/AsyncRequestProcessor.h"

#include "command/taskmanagement/CreateTaskCommand.h"
#include "command/taskmanagement/GetTasksCommand.h"
#include "command/taskmanagement/UpdateTaskCommand.h"
#include "command/taskmanagement/DeleteTaskCommand.h"
#include "command/taskmanagement/CreateTaskGroupCommand.h"
#include "command/taskmanagement/GetTaskGroupsCommand.h"
#include "command/taskmanagement/UpdateTaskGroupCommand.h"
#include "command/taskmanagement/DeleteTaskGroupCommand.h"

TaskManagementRouteHandler::TaskManagementRouteHandler(AsyncRequestProcessorPtr requestProcessor,
                                                       const std::string& baseUrl)
{
    mRequestProcessor = requestProcessor;
    mBaseUrl = baseUrl;
    initializeRoutes();
}

void TaskManagementRouteHandler::initializeRoutes()
{
    // ---- Task Group endpoints ----
    // POST /v1/task-groups
    mRoutePatterns.emplace_back(
        std::regex(R"(^/v1/task-groups$)"),
        "POST",
        [this](const httplib::Request& req, httplib::Response& res) { handleCreateTaskGroup(req, res); });

    // GET /v1/task-groups/users/{userId}
    mRoutePatterns.emplace_back(
        std::regex(R"(^/v1/task-groups/users/([^/]+)$)"),
        "GET",
        [this](const httplib::Request& req, httplib::Response& res) { handleGetTaskGroups(req, res); });

    // PATCH /v1/task-groups/{groupId}
    mRoutePatterns.emplace_back(
        std::regex(R"(^/v1/task-groups/([^/]+)$)"),
        "PATCH",
        [this](const httplib::Request& req, httplib::Response& res) { handleUpdateTaskGroup(req, res); });

    // DELETE /v1/task-groups/{groupId}
    mRoutePatterns.emplace_back(
        std::regex(R"(^/v1/task-groups/([^/]+)$)"),
        "DELETE",
        [this](const httplib::Request& req, httplib::Response& res) { handleDeleteTaskGroup(req, res); });

    // ---- Tasks under a group ----
    // GET /v1/task-groups/{groupId}/tasks
    mRoutePatterns.emplace_back(
        std::regex(R"(^/v1/task-groups/([^/]+)/tasks$)"),
        "GET",
        [this](const httplib::Request& req, httplib::Response& res) { handleGetTasks(req, res); });

    // POST /v1/task-groups/{groupId}/tasks
    mRoutePatterns.emplace_back(
        std::regex(R"(^/v1/task-groups/([^/]+)/tasks$)"),
        "POST",
        [this](const httplib::Request& req, httplib::Response& res) { handleCreateTask(req, res); });

    // ---- Task collection for a user ----
    // GET /v1/tasks/users/{userId}
    mRoutePatterns.emplace_back(
        std::regex(R"(^/v1/tasks/users/([^/]+)$)"),
        "GET",
        [this](const httplib::Request& req, httplib::Response& res) { handleGetTasks(req, res); });

    // ---- Single task operations ----
    // PATCH /v1/tasks/{taskId}
    mRoutePatterns.emplace_back(
        std::regex(R"(^/v1/tasks/([^/]+)$)"),
        "PATCH",
        [this](const httplib::Request& req, httplib::Response& res) { handleUpdateTask(req, res); });

    // DELETE /v1/tasks/{taskId}
    mRoutePatterns.emplace_back(
        std::regex(R"(^/v1/tasks/([^/]+)$)"),
        "DELETE",
        [this](const httplib::Request& req, httplib::Response& res) { handleDeleteTask(req, res); });
}

bool TaskManagementRouteHandler::canHandle(const std::string& path, const std::string& method) const
{
    for (const auto& route : mRoutePatterns) {
        if (method == route.method && std::regex_match(path, route.pattern)) {
            return true;
        }
    }
    return false;
}

void TaskManagementRouteHandler::handleRequest(const httplib::Request &req, httplib::Response &res)
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

std::shared_ptr<IResponseHandler> TaskManagementRouteHandler::createResponseHandler() const
{
    return std::make_shared<JsonResponseHandler>();
}

std::string TaskManagementRouteHandler::extractPathParam(const httplib::Request& req, size_t index) const
{
    std::smatch matches;
    for (const auto& route : mRoutePatterns) {
        if (std::regex_match(req.path, matches, route.pattern) && index < matches.size()) {
            return matches[index].str();
        }
    }
    return "";
}

// --------------------- Task Group Handlers ---------------------

void TaskManagementRouteHandler::handleCreateTaskGroup(const httplib::Request& req, httplib::Response& res)
{
    if (req.body.empty()) {
        res.status = 400;
        res.set_content(R"({"error":"Request body required"})", "application/json");
        return;
    }

    OpenAPI::OAITask_managementCreateTaskGroupRequest body;
    body.fromJson(QString::fromUtf8(req.body.data(), static_cast<int>(req.body.size())));

    auto command = std::make_shared<CreateTaskGroupCommand>(body, QString::fromStdString(mBaseUrl));
    auto responseHandler = createResponseHandler();
    command->setResponseHandler(responseHandler);

    bool ok = mRequestProcessor->processCommand(command, 10000);
    if (!ok) {
        qWarning() << "Failed to process CreateTaskGroupCommand";
    }

    res.status = responseHandler->getStatusCode();
    res.set_content(responseHandler->getResponseData().constData(), "application/json");
}

void TaskManagementRouteHandler::handleGetTaskGroups(const httplib::Request& req, httplib::Response& res)
{
    const QString userId = QString::fromStdString(extractPathParam(req, 1));
    if (userId.isEmpty()) {
        res.status = 400;
        res.set_content(R"({"error":"userId required"})", "application/json");
        return;
    }

    auto command = std::make_shared<GetTaskGroupsCommand>(userId, QString::fromStdString(mBaseUrl));
    auto responseHandler = createResponseHandler();
    command->setResponseHandler(responseHandler);

    bool ok = mRequestProcessor->processCommand(command, 10000);
    if (!ok) {
        qWarning() << "Failed to process GetTaskGroupsCommand";
    }

    res.status = responseHandler->getStatusCode();
    res.set_content(responseHandler->getResponseData().constData(), "application/json");
}

void TaskManagementRouteHandler::handleUpdateTaskGroup(const httplib::Request& req, httplib::Response& res)
{
    const QString groupId = QString::fromStdString(extractPathParam(req, 1));
    if (groupId.isEmpty()) {
        res.status = 400;
        res.set_content(R"({"error":"groupId required"})", "application/json");
        return;
    }
    if (req.body.empty()) {
        res.status = 400;
        res.set_content(R"({"error":"Request body required"})", "application/json");
        return;
    }

    OpenAPI::OAITaskManagementServiceUpdateTaskGroupBody body;
    body.fromJson(QString::fromUtf8(req.body.data(), static_cast<int>(req.body.size())));

    auto command = std::make_shared<UpdateTaskGroupCommand>(body, groupId, QString::fromStdString(mBaseUrl));
    auto responseHandler = createResponseHandler();
    command->setResponseHandler(responseHandler);

    bool ok = mRequestProcessor->processCommand(command, 10000);
    if (!ok) {
        qWarning() << "Failed to process UpdateTaskGroupCommand";
    }

    res.status = responseHandler->getStatusCode();
    res.set_content(responseHandler->getResponseData().constData(), "application/json");
}

void TaskManagementRouteHandler::handleDeleteTaskGroup(const httplib::Request& req, httplib::Response& res)
{
    const QString groupId = QString::fromStdString(extractPathParam(req, 1));
    if (groupId.isEmpty()) {
        res.status = 400;
        res.set_content(R"({"error":"groupId required"})", "application/json");
        return;
    }

    auto command = std::make_shared<DeleteTaskGroupCommand>(groupId, QString::fromStdString(mBaseUrl));
    auto responseHandler = createResponseHandler();
    command->setResponseHandler(responseHandler);

    bool ok = mRequestProcessor->processCommand(command, 10000);
    if (!ok) {
        qWarning() << "Failed to process DeleteTaskGroupCommand";
    }

    res.status = responseHandler->getStatusCode();
    res.set_content(responseHandler->getResponseData().constData(), "application/json");
}

// --------------------- Task Handlers ---------------------

void TaskManagementRouteHandler::handleCreateTask(const httplib::Request& req, httplib::Response& res)
{
    // Path: /v1/task-groups/{groupId}/tasks
    const QString groupId = QString::fromStdString(extractPathParam(req, 1));
    if (groupId.isEmpty()) {
        res.status = 400;
        res.set_content(R"({"error":"groupId required"})", "application/json");
        return;
    }

    if (req.body.empty()) {
        res.status = 400;
        res.set_content(R"({"error":"Request body required"})", "application/json");
        return;
    }

    OpenAPI::OAITaskManagementServiceCreateTaskBody body;
    body.fromJson(QString::fromUtf8(req.body.data(), static_cast<int>(req.body.size())));

    // body may not include groupId field; if generated model has setGroupId(), set it (pseudo):
    // body.setGroupId(groupId);

    auto command = std::make_shared<CreateTaskCommand>(groupId, body, QString::fromStdString(mBaseUrl));
    auto responseHandler = createResponseHandler();
    command->setResponseHandler(responseHandler);

    bool ok = mRequestProcessor->processCommand(command, 10000);
    if (!ok) {
        qWarning() << "Failed to process CreateTaskCommand";
    }

    res.status = responseHandler->getStatusCode();
    res.set_content(responseHandler->getResponseData().constData(), "application/json");
}

void TaskManagementRouteHandler::handleGetTasks(const httplib::Request& req, httplib::Response& res)
{
    // Two possible matched patterns:
    // 1) /v1/task-groups/{groupId}/tasks
    // 2) /v1/tasks/users/{userId}
    QString groupId;
    QString userId;

    // Determine which regex matched by re-testing
    if (std::regex_match(req.path, std::regex(R"(^/v1/task-groups/([^/]+)/tasks$)"))) {
        groupId = QString::fromStdString(extractPathParam(req, 1));
        // userId optional via query param ?userId=
        auto it = req.params.find("userId");
        if (it != req.params.end()) {
            userId = QString::fromStdString(it->second);
        }
    } else if (std::regex_match(req.path, std::regex(R"(^/v1/tasks/users/([^/]+)$)"))) {
        userId = QString::fromStdString(extractPathParam(req, 1));
        // Optional groupId in query ?groupId=
        auto it = req.params.find("groupId");
        if (it != req.params.end()) {
            groupId = QString::fromStdString(it->second);
        }
    }

    if (groupId.isEmpty() && userId.isEmpty()) {
        res.status = 400;
        res.set_content(R"({"error":"Either groupId or userId required"})", "application/json");
        return;
    }

    auto command = std::make_shared<GetTasksCommand>(userId, groupId, QString::fromStdString(mBaseUrl));
    auto responseHandler = createResponseHandler();
    command->setResponseHandler(responseHandler);

    bool ok = mRequestProcessor->processCommand(command, 10000);
    if (!ok) {
        qWarning() << "Failed to process GetTasksCommand";
    }

    res.status = responseHandler->getStatusCode();
    res.set_content(responseHandler->getResponseData().constData(), "application/json");
}

void TaskManagementRouteHandler::handleUpdateTask(const httplib::Request& req, httplib::Response& res)
{
    // Paths: /v1/tasks/{taskId}
    const QString taskId = QString::fromStdString(extractPathParam(req, 1));
    if (taskId.isEmpty()) {
        res.status = 400;
        res.set_content(R"({"error":"taskId required"})", "application/json");
        return;
    }
    if (req.body.empty()) {
        res.status = 400;
        res.set_content(R"({"error":"Request body required"})", "application/json");
        return;
    }

    OpenAPI::OAITaskManagementServiceUpdateTaskBody body;
    body.fromJson(QString::fromUtf8(req.body.data(), static_cast<int>(req.body.size())));

    auto command = std::make_shared<UpdateTaskCommand>(body, taskId, QString::fromStdString(mBaseUrl));
    auto responseHandler = createResponseHandler();
    command->setResponseHandler(responseHandler);

    bool ok = mRequestProcessor->processCommand(command, 10000);
    if (!ok) {
        qWarning() << "Failed to process UpdateTaskCommand";
    }

    res.status = responseHandler->getStatusCode();
    res.set_content(responseHandler->getResponseData().constData(), "application/json");
}

void TaskManagementRouteHandler::handleDeleteTask(const httplib::Request& req, httplib::Response& res)
{
    // Path: /v1/tasks/{taskId}
    const QString taskId = QString::fromStdString(extractPathParam(req, 1));
    if (taskId.isEmpty()) {
        res.status = 400;
        res.set_content(R"({"error":"taskId required"})", "application/json");
        return;
    }

    auto command = std::make_shared<DeleteTaskCommand>(taskId, QString::fromStdString(mBaseUrl));
    auto responseHandler = createResponseHandler();
    command->setResponseHandler(responseHandler);

    bool ok = mRequestProcessor->processCommand(command, 10000);
    if (!ok) {
        qWarning() << "Failed to process DeleteTaskCommand";
    }

    res.status = responseHandler->getStatusCode();
    res.set_content(responseHandler->getResponseData().constData(), "application/json");
}
