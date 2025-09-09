/**
 * @file CreateSessionCommand.cpp
 * @author trung.la
 * @date 09-03-2025
 * @brief Implementation of CreateSessionCommand to create a Pomodoro session via the Pomodoro API.
 */

#include "CreateSessionCommand.h"

#include <QDebug>

CreateSessionCommand::CreateSessionCommand(const QString& userId, 
    const OAIPomodoroServiceCreateSessionBody& body,
    IPomodoroApiClientFactoryPtr factory,
    const QString& baseUrl,
    QObject* parent)
    : IApiCommand(parent),
      mUserId(userId),
      mBody(body),
      mFactory(factory),
      mBaseUrl(baseUrl),
      mResponseHandler(nullptr),
      mApiClient(nullptr)
{
}

void CreateSessionCommand::execute()
{
    if (!mFactory) {
        qWarning() << "API client factory is null.";
        return;
    }

    if (mApiClient) {
        qWarning() << "API client is already created.";
        return; // Already executing
    }

    mApiClient = mFactory->createClient(mBaseUrl);
    if (!mApiClient) {
        qWarning() << "Failed to create API client.";
        return;
    }
    connect(mApiClient.get(), &OpenAPI::OAIPomodoroServiceApi::pomodoroServiceCreateSessionSignal,
            this, &CreateSessionCommand::onSessionCreated);
    connect(mApiClient.get(), &OpenAPI::OAIPomodoroServiceApi::pomodoroServiceCreateSessionSignalError,
            this, &CreateSessionCommand::onSessionError);

    mApiClient->pomodoroServiceCreateSession(mUserId, mBody);
}

void CreateSessionCommand::setResponseHandler(IResponseHandlerPtr handler)
{
    mResponseHandler = handler;
}

IResponseHandlerPtr CreateSessionCommand::getResponseHandler() const
{
    return mResponseHandler;
}

void CreateSessionCommand::onSessionCreated(const OAIPomodoro_serviceCreateSessionResponse& response)
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
    if (!obj.contains("session") || !obj["session"].isObject()) {
        qWarning() << "Response does not contain a valid 'session' object";
        emit completed();
        return;
    }

    mSession = obj["session"].toObject();

    emit completed();
}

void CreateSessionCommand::onSessionError(const OAIPomodoro_serviceCreateSessionResponse& summary, 
                                         QNetworkReply::NetworkError errorType, const QString& errorStr)
{
    if (!mResponseHandler) {
        qWarning() << "Response handler is not set.";
        emit completed();
        return;
    }

    auto errorMessage = errorStr;
    if (errorMessage.isEmpty()) {
        auto const json = summary.asJson();
        if (!json.isEmpty()) {
            errorMessage = json;
        } else {
            errorMessage = "Unknown error occurred";
        }
    }

    mResponseHandler->handleError(errorType, errorMessage.toUtf8());
    emit completed();
}

QJsonObject CreateSessionCommand::getSession() const
{
   return mSession;
}