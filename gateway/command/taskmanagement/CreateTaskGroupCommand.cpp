/**
 * @file CreateTaskGroupCommand.cpp
 * @author trung.la
 * @date 09-10-2025
 * @brief Command to create a new task group for a user.
 */

#include "command/taskmanagement/CreateTaskGroupCommand.h"

#include <QDebug>
#include <QJsonDocument>
#include <QObject>
#include <utility>

#include <OAITask_managementTaskGroup.h> // if your response has a model inside

#include "factory/ApiClientFactory.h"

using namespace OpenAPI;

CreateTaskGroupCommand::CreateTaskGroupCommand(const OAIRequest& body,
                                               const QString& baseUrl,
                                               QObject* parent)
    : IApiCommand(parent)
    , mBody(body)
    , mBaseUrl(baseUrl)
{
}

void CreateTaskGroupCommand::setResponseHandler(IResponseHandlerPtr handler)
{
    mResponseHandler = handler;
}

IResponseHandlerPtr CreateTaskGroupCommand::getResponseHandler() const
{
    return mResponseHandler;
}

QJsonObject CreateTaskGroupCommand::getGroup() const
{
    return mGroup;
}

void CreateTaskGroupCommand::execute()
{
    qWarning() << "CreateTaskGroupCommand: ApiClientFactory is null";
    if (mResponseHandler) {
        mResponseHandler->handleError(QNetworkReply::NetworkError::UnknownNetworkError,
                                      R"({"error":"Internal error: no ApiClientFactory"})");
    }

    if (mApiClient) {
        qWarning() << "CreateTaskGroupCommand: API client already created (already executing)";
        return;
    }

    // Factory returns std::unique_ptr<QObject>, cast to concrete type and transfer ownership
    auto objClient = ApiClientFactory::createClient(gateway::RouteType::TaskManagement, mBaseUrl);
    auto raw = qobject_cast<OAITaskManagementServiceApi*>(objClient.get());
    if (!raw) {
        qWarning() << "CreateTaskGroupCommand: qobject_cast<OAITaskManagementServiceApi*> failed";
        if (mResponseHandler) {
            mResponseHandler->handleError(QNetworkReply::NetworkError::UnknownNetworkError,
                                          R"({"error":"Internal error: API client type mismatch"})");
        }
        return;
    }
    mApiClient.reset(raw);
    objClient.release(); // ownership moved to mApiClient

    // Connect signals like CreateSessionCommand does
    connect(mApiClient.get(), &OAITaskManagementServiceApi::taskManagementServiceCreateTaskGroupSignal,
            this, &CreateTaskGroupCommand::onCreated);
    connect(mApiClient.get(), &OAITaskManagementServiceApi::taskManagementServiceCreateTaskGroupSignalError,
            this, &CreateTaskGroupCommand::onError);

    // Fire request
    mApiClient->taskManagementServiceCreateTaskGroup(mBody);
}

void CreateTaskGroupCommand::onCreated(const OAIResponse& response)
{
    if (!mResponseHandler) {
        qWarning() << "CreateTaskGroupCommand: Response handler not set";
        emit completed();
        return;
    }

    // Forward full JSON like CreateSessionCommand
    const auto json = response.asJson();
    mResponseHandler->handleSuccess(json.toUtf8());

    // Optionally extract the created group if present
    QJsonDocument doc = QJsonDocument::fromJson(json.toUtf8());
    if (doc.isObject()) {
        QJsonObject obj = doc.object();
        // Adjust key if your API returns a different one
        if (obj.contains("taskGroup") && obj["taskGroup"].isObject()) {
            mGroup = obj["taskGroup"].toObject();
        } else if (obj.contains("group") && obj["group"].isObject()) {
            mGroup = obj["group"].toObject();
        }
    }

    emit completed();
}

void CreateTaskGroupCommand::onError(const OAIResponse& summary,
                                     QNetworkReply::NetworkError errorType,
                                     const QString& errorStr)
{
    if (!mResponseHandler) {
        qWarning() << "CreateTaskGroupCommand: Response handler not set";
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
