/**
 * @file GetSessionsCommand.cpp
 * @author trung.la
 * @date 09-04-2025
 * @brief Command to get all Pomodoro sessions for a user via the Pomodoro API.
 */

#include "GetSessionsCommand.h"

GetSessionsCommand::GetSessionsCommand(const QString& userId,
    const QString& taskId,
    IPomodoroApiClientFactoryPtr factory,
    const QString& baseUrl,
    QObject* parent)
    : IApiCommand(parent),
      mUserId(userId),
      mTaskId(taskId),
      mFactory(factory),
      mBaseUrl(baseUrl),
      mResponseHandler(nullptr),
      mApiClient(nullptr)
{
}

void GetSessionsCommand::execute()
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

void GetSessionsCommand::onSessionsRetrieved(const OAIPomodoro_serviceGetSessionsResponse& response)
{
    if (!mResponseHandler) {
        qWarning() << "Response handler is not set.";
        return;
    }

    auto const json = response.asJson();
    mResponseHandler->handleSuccess(json.toUtf8());
}

void GetSessionsCommand::onSessionsError(const OAIPomodoro_serviceGetSessionsResponse& response, QNetworkReply::NetworkError errorType, const QString& errorStr)
{
    if (!mResponseHandler) {
        qWarning() << "Response handler is not set.";
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
}
