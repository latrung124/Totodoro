/**
 * @file GetSessionByIdCommand.cpp
 * @author trung.la
 * @date 09-03-2025
 * @brief Command to get a Pomodoro session by ID via the Pomodoro API.
 */

#include "command/pomodoro/GetSessionByIdCommand.h"

#include "factory/ApiClientFactory.h"

GetSessionByIdCommand::GetSessionByIdCommand(
    const QString& sessionId,
    const QString& baseUrl,
    QObject* parent)
    : IApiCommand(parent),
      mSessionId(sessionId),
      mBaseUrl(baseUrl),
      mResponseHandler(nullptr),
      mApiClient(nullptr)
{
}

void GetSessionByIdCommand::execute()
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

    connect(mApiClient.get(), &OpenAPI::OAIPomodoroServiceApi::pomodoroServiceGetSessionByIdSignal,
            this, &GetSessionByIdCommand::onSessionRetrieved);
    connect(mApiClient.get(), &OpenAPI::OAIPomodoroServiceApi::pomodoroServiceGetSessionByIdSignalError,
            this, &GetSessionByIdCommand::onSessionError);

    mApiClient->pomodoroServiceGetSessionById(mSessionId);
}

void GetSessionByIdCommand::setResponseHandler(IResponseHandlerPtr handler)
{
    mResponseHandler = handler;
}

IResponseHandlerPtr GetSessionByIdCommand::getResponseHandler() const
{
    return mResponseHandler;
}

void GetSessionByIdCommand::onSessionRetrieved(const OAIPomodoro_serviceGetSessionByIdResponse& response)
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
        qWarning() << "Failed to parse response JSON or it is not an object";
        emit completed();
        return;
    }

    QJsonObject obj = doc.object();
    if (obj.contains("session") && obj["session"].isObject()) {
        mSession = obj["session"].toObject();
    } else {
        qWarning() << "Response JSON does not contain 'session' object";
    }
    
    emit completed();
}

void GetSessionByIdCommand::onSessionError(const OAIPomodoro_serviceGetSessionByIdResponse& summary,
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

QJsonObject GetSessionByIdCommand::getSession() const
{
    return mSession;
}
