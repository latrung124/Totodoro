/**
 * @file GetTaskCommand.cpp
 * @author trung.la
 * @date 09-14-2025
 * @brief Implementation of GetTaskCommand class that handles retrieving a task via the OpenAPI client.
 */

#include "command/taskmanagement/GetTasksCommand.h"

#include "factory/ApiClientFactory.h"

GetTasksCommand::GetTasksCommand(const QString& userId,
    const QString& groupId,
    const QString& baseUrl,
    QObject* parent)
    : IApiCommand(parent),
      mUserId(userId),
      mGroupId(groupId),
      mBaseUrl(baseUrl),
      mResponseHandler(nullptr),
      mApiClient(nullptr)
{
}

void GetTasksCommand::execute()
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

    connect(mApiClient.get(), &OpenAPI::OAITaskManagementServiceApi::taskManagementServiceGetTasksSignal,
            this, &GetTasksCommand::onTasksRetrieved);
    connect(mApiClient.get(), &OpenAPI::OAITaskManagementServiceApi::taskManagementServiceGetTasksSignalError,
            this, &GetTasksCommand::onTasksError);

    mApiClient->taskManagementServiceGetTasks(mUserId, mGroupId);
}

void GetTasksCommand::setResponseHandler(IResponseHandlerPtr handler)
{
    mResponseHandler = handler;
}

IResponseHandlerPtr GetTasksCommand::getResponseHandler() const
{
    return mResponseHandler;
}

QList<QVariantMap> GetTasksCommand::getTasks() const
{
    return mTasks;
}

void GetTasksCommand::onTasksRetrieved(const OAIResponse& response)
{
    if (!mResponseHandler) {
        qWarning() << "GetTasksCommand: Response handler is not set.";
        emit completed();
        return;
    }

    auto const json = response.asJson();
    mResponseHandler->handleSuccess(json.toUtf8());
    QJsonDocument doc = QJsonDocument::fromJson(json.toUtf8());
    if (doc.isNull() || !doc.isObject()) {
        qWarning() << "GetTasksCommand: Failed to parse JSON response";
        emit completed();
        return;
    }

    QJsonObject obj = doc.object();
    if (!obj.contains("tasks") || !obj["tasks"].isArray()) {
        qWarning() << "GetTasksCommand: JSON response does not contain 'groups' array";
        emit completed();
        return;
    }

    QJsonArray taskArray = obj["tasks"].toArray();
    for (const QJsonValue& groupValue : taskArray) {
        if (groupValue.isObject()) {
            mTasks.append(groupValue.toObject().toVariantMap());
        } else {
            qWarning() << "GetTasksCommand: Group entry is not an object";
        }
    }

    emit completed();
}

void GetTasksCommand::onTasksError(const OAIResponse& response,
                                             QNetworkReply::NetworkError errorType,
                                             const QString& errorStr)
{
    if (!mResponseHandler) {
        qWarning() << "GetTasksCommand: Response handler is not set.";
        emit completed();
        return;
    }

    // Forward full JSON error like CreateSessionCommand
    const auto json = response.asJson();
    mResponseHandler->handleError(errorType, json.toUtf8());

    emit completed();
}
