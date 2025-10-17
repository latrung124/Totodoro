/**
 * @file GetTaskGroupsCommand.cpp
 * @author trung.la
 * @date 09-11-2025
 * @brief Implementation of GetTaskGroupsCommand to retrieve task groups via the OpenAPI client.
 */

#include "command/taskmanagement/GetTaskGroupsCommand.h"

#include <OAITaskManagementServiceApi.h>
#include <OAITask_managementGetTaskGroupsResponse.h>

#include "factory/ApiClientFactory.h"

GetTaskGroupsCommand::GetTaskGroupsCommand(const QString& userId,
                                               const QString& baseUrl,
                                               QObject* parent)
    : IApiCommand(parent)
    , mUserId(userId)
    , mBaseUrl(baseUrl)
    , mResponseHandler(nullptr)
    , mApiClient(nullptr)
{
}

GetTaskGroupsCommand::~GetTaskGroupsCommand() = default;

void GetTaskGroupsCommand::setResponseHandler(IResponseHandlerPtr handler)
{
    mResponseHandler = handler;
}

IResponseHandlerPtr GetTaskGroupsCommand::getResponseHandler() const
{
    return mResponseHandler;
}

QList<QVariantMap> GetTaskGroupsCommand::getGroups() const
{
    return mGroups;
}

void GetTaskGroupsCommand::execute()
{
    if (mResponseHandler) {
        mResponseHandler->handleError(QNetworkReply::NetworkError::UnknownNetworkError,
                                      R"({"error":"Internal error: no ApiClientFactory"})");
    }

    if (mApiClient) {
        qWarning() << "GetTaskGroupsCommand: API client already created (already executing)";
        return;
    }

    // Factory returns std::unique_ptr<QObject>, cast to concrete type and transfer ownership
    auto objClient = ApiClientFactory::createClient(gateway::RouteType::TaskManagement, mBaseUrl);
    auto raw = qobject_cast<OpenAPI::OAITaskManagementServiceApi*>(objClient.get());
    if (!raw) {
        qWarning() << "GetTaskGroupsCommand: qobject_cast<OAITaskManagementServiceApi*> failed";
        if (mResponseHandler) {
            mResponseHandler->handleError(QNetworkReply::NetworkError::UnknownNetworkError,
                                          R"({"error":"Internal error: API client type mismatch"})");
        }
        return;
    }
    mApiClient.reset(raw);
    objClient.release(); // ownership moved to mApiClient

    // Connect signals like CreateSessionCommand does
    connect(mApiClient.get(), &OpenAPI::OAITaskManagementServiceApi::taskManagementServiceGetTaskGroupsSignal,
            this, &GetTaskGroupsCommand::onTaskGroupsRetrieved);
    connect(mApiClient.get(), &OpenAPI::OAITaskManagementServiceApi::taskManagementServiceGetTaskGroupsSignalError,
            this, &GetTaskGroupsCommand::onTaskGroupsError);

    // Fire request
    mApiClient->taskManagementServiceGetTaskGroups(mUserId);
}

void GetTaskGroupsCommand::onTaskGroupsRetrieved(const OAIResponse& response)
{
    if (!mResponseHandler) {
        qWarning() << "GetTaskGroupsCommand: Response handler is not set.";
        emit completed();
        return;
    }

    auto const json = response.asJson();
    mResponseHandler->handleSuccess(json.toUtf8());
    QJsonDocument doc = QJsonDocument::fromJson(json.toUtf8());
    if (doc.isNull() || !doc.isObject()) {
        qWarning() << "GetTaskGroupsCommand: Failed to parse JSON response";
        emit completed();
        return;
    }

    QJsonObject obj = doc.object();
    if (!obj.contains("groups") || !obj["groups"].isArray()) {
        qWarning() << "GetTaskGroupsCommand: JSON response does not contain 'groups' array";
        emit completed();
        return;
    }

    QJsonArray groupsArray = obj["groups"].toArray();
    for (const QJsonValue& groupValue : groupsArray) {
        if (groupValue.isObject()) {
            mGroups.append(groupValue.toObject().toVariantMap());
        } else {
            qWarning() << "GetTaskGroupsCommand: Group entry is not an object";
        }
    }

    emit completed();
}

void GetTaskGroupsCommand::onTaskGroupsError(const OAIResponse& summary,
                                             QNetworkReply::NetworkError errorType,
                                             const QString& errorStr)
{
    if (!mResponseHandler) {
        qWarning() << "GetTaskGroupsCommand: Response handler is not set.";
        emit completed();
        return;
    }

    // Forward full JSON error like CreateSessionCommand
    const auto json = summary.asJson();
    mResponseHandler->handleError(errorType, json.toUtf8());

    emit completed();
}
