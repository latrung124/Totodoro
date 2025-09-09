/**
 * @file UpdateSessionCommand.cpp
 * @author trung.la
 * @date 09-04-2025
 * @brief Implementation of UpdateSessionCommand class that handles updating Pomodoro sessions via the OpenAPI client.
 */

#include "UpdateSessionCommand.h"

#include <QDebug>

UpdateSessionCommand::UpdateSessionCommand(const IPomodoroApiClientFactoryPtr& apiClientFactory,
                                           const OAIPomodoroServiceUpdateSessionBody& updateSessionBody,
                                           const QString& sessionId,
                                           const QString& baseUrl,
                                           QObject* parent)
    : IApiCommand(parent),
      mApiClientFactory(apiClientFactory),
      mUpdateSessionBody(updateSessionBody),
      mSessionId(sessionId),
      mBaseUrl(baseUrl),
      mResponseHandler(nullptr)
{
}

void UpdateSessionCommand::execute()
{
    if (!mApiClientFactory) {
        qWarning() << "API client factory is null.";
        return;
    }

    mApiClient = mApiClientFactory->createClient(mBaseUrl);
    if (!mApiClient) {
        qWarning() << "Failed to create API client.";
        return;
    }

    // Connect signals for handling responses
    connect(mApiClient.get(), &OpenAPI::OAIPomodoroServiceApi::pomodoroServiceUpdateSessionSignal,
            this, &UpdateSessionCommand::onSessionUpdated);
    connect(mApiClient.get(), &OpenAPI::OAIPomodoroServiceApi::pomodoroServiceUpdateSessionSignalError,
            this, &UpdateSessionCommand::onSessionError);

    // Execute the update session API call
    mApiClient->pomodoroServiceUpdateSession(mSessionId, mUpdateSessionBody);
}

void UpdateSessionCommand::setResponseHandler(IResponseHandlerPtr handler)
{
    mResponseHandler = handler;
}

IResponseHandlerPtr UpdateSessionCommand::getResponseHandler() const
{
    return mResponseHandler;
}

void UpdateSessionCommand::onSessionUpdated(const OAIPomodoro_serviceUpdateSessionResponse& summary)
{
    if (!mResponseHandler) {
        qWarning() << "Response handler is not set.";
        emit completed();
        return;
    }

    auto const json = summary.asJson();
    mResponseHandler->handleSuccess(json.toUtf8());
    QJsonDocument doc = QJsonDocument::fromJson(json.toUtf8());
    if (!doc.isObject() || doc.isNull()) {
        qWarning() << "Failed to parse JSON response or response is not an object.";
        emit completed();
        return;
    }

    if (doc.object().contains("session") && doc.object()["session"].isObject()) {
        mSession = doc.object()["session"].toObject();
    } else {
        qWarning() << "Response JSON does not contain 'session' object";
    }

    emit completed();
}

void UpdateSessionCommand::onSessionError(const OAIPomodoro_serviceUpdateSessionResponse& summary,
                                         QNetworkReply::NetworkError errorType, const QString& errorStr)
{
    if (!mResponseHandler) {
        qWarning() << "Response handler is not set.";
        emit completed();
        return;
    }

    QString errorMessage = errorStr;
    if (errorMessage.isEmpty()) {
        errorMessage = summary.asJson();
    }

    mResponseHandler->handleError(errorType, errorMessage.toUtf8());
    emit completed();
}

QJsonObject UpdateSessionCommand::getSession() const
{
    return mSession;
}
