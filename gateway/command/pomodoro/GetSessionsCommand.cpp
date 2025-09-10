/**
 * @file GetSessionsCommand.cpp
 * @author trung.la
 * @date 09-04-2025
 * @brief Command to get all Pomodoro sessions for a user via the Pomodoro API.
 */

#include "GetSessionsCommand.h"

#include <QJsonObject>
#include <QJsonArray>
#include <QVariantList>
#include <QJsonDocument>

GetSessionsCommand::GetSessionsCommand(const QString& userId,
    const QString& taskId,
    ApiClientFactoryPtr factory,
    const QString& baseUrl,
    QObject* parent)
    : IApiCommand(parent),
      mUserId(userId),
      mTaskId(taskId),
      mApiClientFactory(factory),
      mBaseUrl(baseUrl),
      mResponseHandler(nullptr),
      mApiClient(nullptr)
{
}

void GetSessionsCommand::execute()
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
    auto objClient = mApiClientFactory->createClient(gateway::RouteType::Session, mBaseUrl);
    auto raw = qobject_cast<OpenAPI::OAIPomodoroServiceApi*>(objClient.get());
    if (!raw) {
        qWarning() << "Failed to create Pomodoro API client (type mismatch).";
        return;
    }
    mApiClient.reset(raw);
    objClient.release(); // ownership moved to mApiClient

    connect(mApiClient.get(), &OpenAPI::OAIPomodoroServiceApi::pomodoroServiceGetSessionsSignal,
            this, &GetSessionsCommand::onSessionsRetrieved);
    connect(mApiClient.get(), &OpenAPI::OAIPomodoroServiceApi::pomodoroServiceGetSessionsSignalError,
            this, &GetSessionsCommand::onSessionsError);

    mApiClient->pomodoroServiceGetSessions(mUserId, ::OpenAPI::OptionalParam<QString>(mTaskId));
}

void GetSessionsCommand::setResponseHandler(IResponseHandlerPtr handler)
{
    mResponseHandler = handler;
}

IResponseHandlerPtr GetSessionsCommand::getResponseHandler() const
{
    return mResponseHandler;
}

QList<QVariantMap> GetSessionsCommand::getSessions() const
{
    return mSessions;
}

void GetSessionsCommand::onSessionsRetrieved(const OAIPomodoro_serviceGetSessionsResponse& response)
{
    if (!mResponseHandler) {
        qWarning() << "Response handler is not set.";
        emit completed();
        return;
    }

    auto const json = response.asJson();
    mResponseHandler->handleSuccess(json.toUtf8());
    QJsonDocument doc = QJsonDocument::fromJson(json.toUtf8());
    if (doc.isNull() || !doc.isObject()) {
        qWarning() << "Failed to parse JSON response";
        emit completed();
        return;
    }

    QJsonObject obj = doc.object();
    if (!obj.contains("sessions") || !obj["sessions"].isArray()) {
        qWarning() << "JSON response does not contain 'sessions' array";
        emit completed();
        return;
    }

    QJsonArray sessionsArray = obj["sessions"].toArray();
    for (const QJsonValue& sessionValue : sessionsArray) {
        if (sessionValue.isObject()) {
            mSessions.append(sessionValue.toObject().toVariantMap());
        } else {
            qWarning() << "Session entry is not an object";
        }
    }

    emit completed();
}

void GetSessionsCommand::onSessionsError(const OAIPomodoro_serviceGetSessionsResponse& response, QNetworkReply::NetworkError errorType, const QString& errorStr)
{
    if (!mResponseHandler) {
        qWarning() << "Response handler is not set.";
        emit completed();
        return;
    }

    auto errorMessage = errorStr;
    if (errorMessage.isEmpty()) {
        auto const json = response.asJson();
        if (!json.isEmpty()) {
            errorMessage = json;
        } else {
            errorMessage = "Unknown error occurred";
        }
    }

    mResponseHandler->handleError(errorType, errorMessage.toUtf8());
    emit completed();
}
