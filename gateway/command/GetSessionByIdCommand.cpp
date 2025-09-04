/**
 * @file GetSessionByIdCommand.cpp
 * @author trung.la
 * @date 09-03-2025
 * @brief Command to get a Pomodoro session by ID via the Pomodoro API.
 */

#include "GetSessionByIdCommand.h"

GetSessionByIdCommand::GetSessionByIdCommand(const QString& userId,
    const QString& sessionId,
    IPomodoroApiClientFactoryPtr factory,
    const QString& baseUrl,
    QObject* parent)
    : IApiCommand(parent),
      mUserId(userId),
      mSessionId(sessionId),
      mFactory(factory),
      mBaseUrl(baseUrl),
      mResponseHandler(nullptr),
      mApiClient(nullptr)
{
}

void GetSessionByIdCommand::execute()
{
    if (!mFactory) {
        return;
    }

    if (mApiClient) {
        return; // Already executing
    }

    mApiClient = mFactory->createClient(mBaseUrl);
    if (!mApiClient) {
        return;
    }
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
        return;
    }

    auto const json = response.asJson();
    mResponseHandler->handleSuccess(json.toUtf8());
    mApiClient.get()->deleteLater();
    deleteLater();
}

void GetSessionByIdCommand::onSessionError(const OAIPomodoro_serviceGetSessionByIdResponse& summary,
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
