/**
 * @file CreateSessionCommand.cpp
 * @author trung.la
 * @date 09-03-2025
 * @brief Implementation of CreateSessionCommand to create a Pomodoro session via the Pomodoro API.
 */

#include "command/pomodoro/CreateSessionCommand.h"

#include <QDebug>

#include <OAIPomodoroServiceCreateSessionBody.h>
#include <OAIPomodoro_serviceCreateSessionResponse.h>

#include "factory/ApiClientFactory.h"

namespace
{
    using namespace OpenAPI;
}

CreateSessionCommand::CreateSessionCommand(const QString& userId, 
    const OAIPomodoroServiceCreateSessionBody& body,
    const QString& baseUrl,
    QObject* parent)
    : IApiCommand(parent),
      mUserId(userId),
      mBody(std::make_unique<OAIPomodoroServiceCreateSessionBody>(body)),
      mBaseUrl(baseUrl),
      mResponseHandler(nullptr),
      mApiClient(nullptr)
{
}

void CreateSessionCommand::execute()
{
    if (mApiClient) {
        qWarning() << "API client is already created.";
        return; // Already executing
    }

    // Create as QObject then cast to the concrete API type and transfer ownership
    auto objClient = ApiClientFactory::createClient(gateway::RouteType::Pomodoro, mBaseUrl);
    auto raw = qobject_cast<OpenAPI::OAIPomodoroServiceApi*>(objClient.get());
    if (!raw) {
        qWarning() << "Failed to create Pomodoro API client (type mismatch).";
        return;
    }
    mApiClient.reset(raw);
    objClient.release(); // ownership moved to mApiClient

    connect(mApiClient.get(), &OpenAPI::OAIPomodoroServiceApi::pomodoroServiceCreateSessionSignal,
            this, &CreateSessionCommand::onSessionCreated);
    connect(mApiClient.get(), &OpenAPI::OAIPomodoroServiceApi::pomodoroServiceCreateSessionSignalError,
            this, &CreateSessionCommand::onSessionError);

    mApiClient->pomodoroServiceCreateSession(mUserId, mBody ? *mBody : OAIPomodoroServiceCreateSessionBody());
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