/**
 * @file DeleteTaskGroupCommand.cpp
 * @author trung.la
 * @date 09-11-2025
 * @brief Implementation of DeleteTaskGroupCommand to delete a task group via the OpenAPI client.
 */

#include "DeleteTaskGroupCommand.h"

#include <QDebug>
#include <QJsonObject>

DeleteTaskGroupCommand::DeleteTaskGroupCommand(const QString& groupId,
    ApiClientFactoryPtr factory,
    const QString& baseUrl,
    QObject* parent)
    : IApiCommand(parent),
      mDeleted(false),
      mGroupId(groupId),
      mApiClientFactory(factory),
      mBaseUrl(baseUrl),
      mResponseHandler(nullptr),
      mApiClient(nullptr)
{
}

void DeleteTaskGroupCommand::execute()
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

    connect(mApiClient.get(), &OpenAPI::OAITaskManagementServiceApi::taskManagementServiceDeleteTaskGroupSignal,
            this, &DeleteTaskGroupCommand::onTaskGroupDeleted);
    connect(mApiClient.get(), &OpenAPI::OAITaskManagementServiceApi::taskManagementServiceDeleteTaskGroupSignalError,
            this, &DeleteTaskGroupCommand::onTaskGroupError);

    mApiClient->taskManagementServiceDeleteTaskGroup(mGroupId);
}

void DeleteTaskGroupCommand::setResponseHandler(IResponseHandlerPtr handler)
{
    mResponseHandler = handler;
}

IResponseHandlerPtr DeleteTaskGroupCommand::getResponseHandler() const
{
    return mResponseHandler;
}

bool DeleteTaskGroupCommand::isDeleted() const
{
    return mDeleted;
}

void DeleteTaskGroupCommand::onTaskGroupDeleted(const OAITask_managementDeleteTaskGroupResponse& response)
{
    if (!mResponseHandler) {
        qWarning() << "DeleteTaskGroupCommand: Response handler is not set.";
        emit completed();
        return;
    }

    auto const json = response.asJson();
    mResponseHandler->handleSuccess(json.toUtf8());

    // Assuming the response contains a field indicating deletion success
    QJsonDocument doc = QJsonDocument::fromJson(json.toUtf8());
    if (doc.isNull() || !doc.isObject()) {
        qWarning() << "DeleteTaskGroupCommand: Failed to parse JSON response";
        emit completed();
        return;
    }

    QJsonObject obj = doc.object();
    if (obj.contains("deleted") && obj["deleted"].isBool()) {
        mDeleted = obj["deleted"].toBool();
    } else {
        qWarning() << "DeleteTaskGroupCommand: JSON response does not contain 'deleted' boolean";
    }

    emit completed();
}

void DeleteTaskGroupCommand::onTaskGroupError(const OAITask_managementDeleteTaskGroupResponse& summary,
                                       QNetworkReply::NetworkError errorType,
                                       const QString& errorStr)
{
    if (!mResponseHandler) {
        qWarning() << "DeleteTaskGroupCommand: Response handler is not set.";
        emit completed();
        return;
    }

    QString msg = errorStr;
    if (msg.isEmpty()) {
        const auto json = summary.asJson();
        if (!json.isEmpty()) {
            msg = json;
        } else {
            msg = "Unknown error occurred during DeleteTaskGroupCommand";
        }
    }

    mResponseHandler->handleError(static_cast<int>(errorType), msg);
    emit completed();
}
