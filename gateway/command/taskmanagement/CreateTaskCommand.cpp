/**
 * @file CreateTaskCommand.cpp
 * @author trung.la
 * @date 09-13-2025
 * @brief Command to create a new task via the Task Management API.
 */

#include "CreateTaskCommand.h"

#include <QDebug>
#include <QJsonDocument>
#include <QObject>
#include <utility>

#include <OAITask_managementTask.h> // optional: if you need to inspect the model

#include "ApiClientFactory.h"


CreateTaskCommand::CreateTaskCommand(const QString& groupId,
                                     const OAIRequest& body,
                                     const QString& baseUrl,
                                     QObject* parent)
    : IApiCommand(parent)
    , mGroupId(groupId)
    , mBody(body)
    , mBaseUrl(baseUrl)
{
}

void CreateTaskCommand::setResponseHandler(IResponseHandlerPtr handler)
{
    mResponseHandler = handler;
}

IResponseHandlerPtr CreateTaskCommand::getResponseHandler() const
{
    return mResponseHandler;
}

QJsonObject CreateTaskCommand::getTask() const
{
    return mTask;
}

void CreateTaskCommand::execute()
{
    if (mResponseHandler) {
        mResponseHandler->handleError(QNetworkReply::NetworkError::UnknownNetworkError,
                                      R"({"error":"Internal error: no ApiClientFactory"})");
    }

    if (mApiClient) {
        qWarning() << "CreateTaskCommand: API client already created (already executing)";
        return;
    }

    // Factory returns std::unique_ptr<QObject>, cast to concrete type and transfer ownership
    auto objClient = ApiClientFactory::createClient(gateway::RouteType::TaskManagement, mBaseUrl);
    auto raw = qobject_cast<OAITaskManagementServiceApi*>(objClient.get());
    if (!raw) {
        qWarning() << "CreateTaskCommand: qobject_cast<OAITaskManagementServiceApi*> failed";
        if (mResponseHandler) {
            mResponseHandler->handleError(QNetworkReply::NetworkError::UnknownNetworkError,
                                          R"({"error":"Internal error: API client type mismatch"})");
        }
        return;
    }
    mApiClient.reset(raw);
    objClient.release(); // ownership moved to mApiClient

    // Connect signals (names follow the generator pattern; adjust if needed)
    connect(mApiClient.get(), &OAITaskManagementServiceApi::taskManagementServiceCreateTaskSignal,
            this, &CreateTaskCommand::onCreated);
    connect(mApiClient.get(), &OAITaskManagementServiceApi::taskManagementServiceCreateTaskSignalError,
            this, &CreateTaskCommand::onError);

    // Execute request
    mApiClient->taskManagementServiceCreateTask(mGroupId, mBody);
}

void CreateTaskCommand::onCreated(const OAIResponse& response)
{
    if (!mResponseHandler) {
        qWarning() << "CreateTaskCommand: Response handler not set";
        emit completed();
        return;
    }

    // Forward upstream JSON to handler
    const auto json = response.asJson();
    mResponseHandler->handleSuccess(json.toUtf8());

    // Optionally extract created task object for convenience
    QJsonDocument doc = QJsonDocument::fromJson(json.toUtf8());
    if (doc.isObject()) {
        const QJsonObject obj = doc.object();
        if (obj.contains("task") && obj["task"].isObject()) {
            mTask = obj["task"].toObject();
        } else if (obj.contains("data") && obj["data"].isObject()) {
            mTask = obj["data"].toObject();
        }
    }

    emit completed();
}

void CreateTaskCommand::onError(const OAIResponse& summary,
                                QNetworkReply::NetworkError errorType,
                                const QString& errorStr)
{
    if (!mResponseHandler) {
        qWarning() << "CreateTaskCommand: Response handler not set";
        emit completed();
        return;
    }

    QString msg = errorStr;
    if (msg.isEmpty()) {
        const auto json = summary.asJson();
        if (!json.isEmpty()) {
            msg = json;
        } else {
            msg = "Unknown error occurred";
        }
    }

    mResponseHandler->handleError(errorType, msg.toUtf8());
    emit completed();
}