/**
 * @file UpdateTaskGroupsCommand.cpp
 * @author trung.la
 * @date 09-11-2025
 * @brief Implementation of UpdateTaskGroupCommand to update a task group via the OpenAPI client.
 */

#include "command/taskmanagement/UpdateTaskGroupCommand.h"

#include <QDebug>

#include "factory/ApiClientFactory.h"

UpdateTaskGroupCommand::UpdateTaskGroupCommand(const OAITaskManagementServiceUpdateTaskGroupBody& updateTaskGroupBody,
                                                const QString& taskGroupId,
                                                const QString& baseUrl,
                                                QObject* parent)
    : IApiCommand(parent),
      mUpdateTaskGroupBody(updateTaskGroupBody),
      mTaskGroupId(taskGroupId),
      mBaseUrl(baseUrl),
      mResponseHandler(nullptr)
{
}

void UpdateTaskGroupCommand::execute()
{
    // Create as QObject then cast to the concrete API type and transfer ownership
    auto objClient = ApiClientFactory::createClient(gateway::RouteType::TaskManagement, mBaseUrl);
    auto raw = qobject_cast<OpenAPI::OAITaskManagementServiceApi*>(objClient.get());
    if (!raw) {
        qWarning() << "Failed to create Pomodoro API client (type mismatch).";
        return;
    }
    mApiClient.reset(raw);
    objClient.release(); // ownership moved to mApiClient

    // Connect signals for handling responses
    connect(mApiClient.get(), &OpenAPI::OAITaskManagementServiceApi::taskManagementServiceUpdateTaskGroupSignal,
            this, &UpdateTaskGroupCommand::onTaskGroupUpdated);
    connect(mApiClient.get(), &OpenAPI::OAITaskManagementServiceApi::taskManagementServiceUpdateTaskGroupSignalError,
            this, &UpdateTaskGroupCommand::onTaskGroupError);

    // Execute the update taskgroup API call
    mApiClient->taskManagementServiceUpdateTaskGroup(mTaskGroupId, mUpdateTaskGroupBody);
}

void UpdateTaskGroupCommand::setResponseHandler(IResponseHandlerPtr handler)
{
    mResponseHandler = handler;
}

IResponseHandlerPtr UpdateTaskGroupCommand::getResponseHandler() const
{
    return mResponseHandler;
}

void UpdateTaskGroupCommand::onTaskGroupUpdated(const OAITask_managementUpdateTaskGroupResponse& summary)
{
    if (!mResponseHandler) {
        qWarning() << "Response handler is not set.";
        emit completed();
        return;
    }

    auto const json = summary.asJson();
    mResponseHandler->handleSuccess(json.toUtf8());
    QJsonDocument doc = QJsonDocument::fromJson(json.toUtf8());
    if (!doc.isObject() || doc.isNull()) {
        qWarning() << "Failed to parse JSON response or response is not an object.";
        emit completed();
        return;
    }

    if (doc.object().contains("group") && doc.object()["group"].isObject()) {
        mTaskGroup = doc.object()["group"].toObject();
    } else {
        qWarning() << "Response JSON does not contain 'group' object";
    }

    emit completed();
}

void UpdateTaskGroupCommand::onTaskGroupError(const OAITask_managementUpdateTaskGroupResponse& summary,
                                         QNetworkReply::NetworkError errorType, const QString& errorStr)
{
    if (!mResponseHandler) {
        qWarning() << "Response handler is not set.";
        emit completed();
        return;
    }

    QString errorMessage = errorStr;
    if (errorMessage.isEmpty()) {
        errorMessage = summary.asJson();
    }

    mResponseHandler->handleError(errorType, errorMessage.toUtf8());
    emit completed();
}

QJsonObject UpdateTaskGroupCommand::getTaskGroup() const
{
    return mTaskGroup;
}
