/**
 * @file DeleteSessionCommand.cpp
 * @author trung.la
 * @date 09-07-2025
 * @brief Command to delete a pomodoro session.
 */

#include "DeleteSessionCommand.h"

#include <QDebug>
#include <QJsonObject>

DeleteSessionCommand::DeleteSessionCommand(const QString& sessionId,
    ApiClientFactoryPtr factory,
    const QString& baseUrl,
    QObject* parent)
    : IApiCommand(parent),
      mDeleted(false),
      mSessionId(sessionId),
      mApiClientFactory(factory),
      mBaseUrl(baseUrl),
      mResponseHandler(nullptr),
      mApiClient(nullptr)
{
}

void DeleteSessionCommand::execute()
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

    connect(mApiClient.get(), &OpenAPI::OAIPomodoroServiceApi::pomodoroServiceDeleteSessionSignal,
            this, &DeleteSessionCommand::onSessionDeleted);
    connect(mApiClient.get(), &OpenAPI::OAIPomodoroServiceApi::pomodoroServiceDeleteSessionSignalError,
            this, &DeleteSessionCommand::onSessionError);

    mApiClient->pomodoroServiceDeleteSession(mSessionId);
}

void DeleteSessionCommand::setResponseHandler(IResponseHandlerPtr handler)
{
    mResponseHandler = handler;
}

IResponseHandlerPtr DeleteSessionCommand::getResponseHandler() const
{
    return mResponseHandler;
}

void DeleteSessionCommand::onSessionDeleted(const OAIPomodoro_serviceDeleteSessionResponse& response)
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

    QJsonObject obj = doc.object();
    if (obj.contains("success") && obj["success"].isBool()) {
        mDeleted = obj["success"].toBool();
    } else {
        qWarning() << "Response JSON does not contain 'success' boolean";
    }
    emit completed();
}

void DeleteSessionCommand::onSessionError(const OAIPomodoro_serviceDeleteSessionResponse& summary,
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

bool DeleteSessionCommand::isDeleted() const
{
    return mDeleted;
}