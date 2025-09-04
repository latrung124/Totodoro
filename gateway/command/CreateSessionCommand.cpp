/**
 * @file CreateSessionCommand.cpp
 * @author trung.la
 * @date 09-03-2025
 * @brief Implementation of CreateSessionCommand to create a Pomodoro session via the Pomodoro API.
 */

#include "CreateSessionCommand.h"

#include <QEventLoop>
#include <QTimer>

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
        return;
    }

    if (mApiClient) {
        return; // Already executing
    }

    mApiClient = mFactory->createClient(mBaseUrl);
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
        return;
    }

    auto const json = response.asJson();
    mResponseHandler->handleSuccess(json.toUtf8());
    mApiClient.get()->deleteLater();
    deleteLater();
}

void CreateSessionCommand::onSessionError(const OAIPomodoro_serviceCreateSessionResponse& summary, 
                                         QNetworkReply::NetworkError errorType, const QString& errorStr)
{
    if (!mResponseHandler) {
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
    mApiClient.get()->deleteLater();
    deleteLater();
}

