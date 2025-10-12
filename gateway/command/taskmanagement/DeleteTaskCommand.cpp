/**
 * @file DeleteTaskCommand.cpp
 * @author trung.la
 * @date 09-14-2025
 * @brief Implementation of DeleteTaskCommand class that handles deleting a task via the OpenAPI client.
 */

#include "command/taskmanagement/DeleteTaskCommand.h"

#include "factory/ApiClientFactory.h"

DeleteTaskCommand::DeleteTaskCommand(const QString& taskId,
    const QString& baseUrl,
    QObject* parent)
    : IApiCommand(parent),
      mDeleted(false),
      mTaskId(taskId),
      mBaseUrl(baseUrl),
      mResponseHandler(nullptr),
      mApiClient(nullptr)
{
}

void DeleteTaskCommand::execute()
{
    if (mApiClient) {
        qWarning() << "API client is already created.";
        return; // Already executing
    }

    // Create as QObject then cast to the concrete API type and transfer ownership
    auto objClient = ApiClientFactory::createClient(gateway::RouteType::TaskManagement, mBaseUrl);
    auto raw = qobject_cast<OpenAPI::OAITaskManagementServiceApi*>(objClient.get());
    if (!raw) {
        qWarning() << "Failed to create Task Management API client (type mismatch).";
        return;
    }
    mApiClient.reset(raw);
    objClient.release(); // ownership moved to mApiClient

    connect(mApiClient.get(), &OpenAPI::OAITaskManagementServiceApi::taskManagementServiceDeleteTaskSignal,
            this, &DeleteTaskCommand::onTaskDeleted);
    connect(mApiClient.get(), &OpenAPI::OAITaskManagementServiceApi::taskManagementServiceDeleteTaskSignalError,
            this, &DeleteTaskCommand::onTaskError);

    mApiClient->taskManagementServiceDeleteTask(mTaskId);
}

void DeleteTaskCommand::setResponseHandler(IResponseHandlerPtr handler)
{
    mResponseHandler = handler;
}

IResponseHandlerPtr DeleteTaskCommand::getResponseHandler() const
{
    return mResponseHandler;
}

bool DeleteTaskCommand::isDeleted() const
{
    return mDeleted;
}

void DeleteTaskCommand::onTaskDeleted(const OAITask_managementDeleteTaskResponse& response)
{
    if (!mResponseHandler) {
        qWarning() << "Response handler is not set.";
        return;
    }

    auto const json = response.asJson();
    mResponseHandler->handleSuccess(json.toUtf8());

    QJsonDocument doc = QJsonDocument::fromJson(json.toUtf8());
    if (doc.isNull() || !doc.isObject()) {
        qWarning() << "DeleteTaskCommand: Invalid JSON response.";
        emit completed();
        return;
    }

    QJsonObject obj = doc.object();
    if (obj.contains("success") && obj["success"].isBool()) {
        mDeleted = obj["success"].toBool();
    } else {
        qWarning() << "DeleteTaskCommand: JSON response does not contain 'success' boolean.";
    }

    emit completed();
}

void DeleteTaskCommand::onTaskError(const OAITask_managementDeleteTaskResponse& response,
                                   QNetworkReply::NetworkError errorType, const QString& errorStr)
{
    if (!mResponseHandler) {
        qWarning() << "DeleteTaskCommand: Response handler is not set.";
        emit completed();
        return;
    }

    QString msg = errorStr;
    if (msg.isEmpty()) {
        const auto json = response.asJson();
        if (!json.isEmpty()) {
            msg = json;
        } else {
            msg = "Unknown error occurred during DeleteTaskCommand";
        }
    }

    mResponseHandler->handleError(static_cast<int>(errorType), msg);
    emit completed();
}
