/**
 * @file DeleteSessionCommand.cpp
 * @author trung.la
 * @date 09-07-2025
 * @brief Command to delete a pomodoro session.
 */

#include "DeleteSessionCommand.h"

#include <QDebug>

DeleteSessionCommand::DeleteSessionCommand(const QString& sessionId,
    IPomodoroApiClientFactoryPtr factory,
    const QString& baseUrl,
    QObject* parent)
    : IApiCommand(parent),
      mSessionId(sessionId),
      mFactory(factory),
      mBaseUrl(baseUrl),
      mResponseHandler(nullptr),
      mApiClient(nullptr)
{
}

void DeleteSessionCommand::execute()
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


