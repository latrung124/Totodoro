/**
 * @file UpdateTaskCommand.cpp
 * @author trung.la
 * @date 09-14-2025
 * @brief Implementation of UpdateTaskCommand class that handles updating a task via the OpenAPI client.
 */

#include "UpdateTaskCommand.h"

UpdateTaskCommand::UpdateTaskCommand(const ApiClientFactoryPtr& apiClientFactory,
    const OAITaskManagementServiceUpdateTaskBody& updateTaskBody,
    const QString& taskId,
    const QString& baseUrl,
    QObject* parent)
    : IApiCommand(parent),
      mTask(),
      mApiClientFactory(apiClientFactory),
      mUpdateTaskBody(updateTaskBody),
      mTaskId(taskId),
      mBaseUrl(baseUrl),
      mResponseHandler(nullptr),
      mApiClient(nullptr)
{
}

void UpdateTaskCommand::execute()
{
    if (!mApiClientFactory) {
        qWarning() << "API client factory is null.";
        return;
    }

    if (mApiClient) {
        qWarning() << "API client is already created.";
        return; // Already executing
    }

    // Create as QObject then cast to the concrete API type and transfer ownership
    auto objClient = mApiClientFactory->createClient(gateway::RouteType::TaskManagement, mBaseUrl);
    auto raw = qobject_cast<OpenAPI::OAITaskManagementServiceApi*>(objClient.get());
    if (!raw) {
        qWarning() << "Failed to create Task Management API client (type mismatch).";
        return;
    }
    mApiClient.reset(raw);
    objClient.release(); // ownership moved to mApiClient

    connect(mApiClient.get(), &OpenAPI::OAITaskManagementServiceApi::taskManagementServiceUpdateTaskSignal,
            this, &UpdateTaskCommand::onTaskUpdated);
    connect(mApiClient.get(), &OpenAPI::OAITaskManagementServiceApi::taskManagementServiceUpdateTaskSignalError,
            this, &UpdateTaskCommand::onTaskError);

    mApiClient->taskManagementServiceUpdateTask(mTaskId, mUpdateTaskBody);
}

void UpdateTaskCommand::setResponseHandler(IResponseHandlerPtr handler)
{
    mResponseHandler = handler;
}

IResponseHandlerPtr UpdateTaskCommand::getResponseHandler() const
{
    return mResponseHandler;
}

QJsonObject UpdateTaskCommand::getTask() const
{
    return mTask;
}

void UpdateTaskCommand::onTaskUpdated(const OAITask_managementUpdateTaskResponse& response)
{
    if (!mResponseHandler) {
        qWarning() << "Response handler is not set.";
        emit completed();
        return;
    }

    auto const json = response.asJson();
    mResponseHandler->handleSuccess(json.toUtf8());
    QJsonDocument doc = QJsonDocument::fromJson(json.toUtf8());
    if (!doc.isObject() || doc.isNull()) {
        qWarning() << "Failed to parse JSON response or response is not an object.";
        emit completed();
        return;
    }

    if (doc.object().contains("task") && doc.object()["task"].isObject()) {
        mTask = doc.object()["task"].toObject();
    } else {
        qWarning() << "Response JSON does not contain 'task' object";
    }

    emit completed();
}

void UpdateTaskCommand::onTaskError(const OAITask_managementUpdateTaskResponse& response,
                                         QNetworkReply::NetworkError errorType, const QString& errorStr)
{
    if (!mResponseHandler) {
        qWarning() << "Response handler is not set.";
        emit completed();
        return;
    }

    QString errorMessage = errorStr;
    if (errorMessage.isEmpty()) {
        errorMessage = response.asJson();
    }

    mResponseHandler->handleError(errorType, errorMessage.toUtf8());
    emit completed();
}
