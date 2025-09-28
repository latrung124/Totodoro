/**
 * @file GetUserCommand.cpp
 * @author trung.la
 * @date 09-17-2025
 * @brief Implementation of GetUserCommand class that handles retrieving a user via the OpenAPI client
 */

#include "GetUserCommand.h"

#include "ApiClientFactory.h"

GetUserCommand::GetUserCommand(
    const QString& userId,
    const QString& baseUrl,
    QObject* parent)
    : IApiCommand(parent),
      mUserId(userId),
      mBaseUrl(baseUrl),
      mResponseHandler(nullptr),
      mApiClient(nullptr)
{
}

void GetUserCommand::execute()
{
    if (mApiClient) {
        qWarning() << "API client is already created.";
        return; // Already executing
    }
    
    // Create as QObject then cast to the concrete API type and transfer ownership
    auto objClient = ApiClientFactory::createClient(gateway::RouteType::User, mBaseUrl);
    auto raw = qobject_cast<OpenAPI::OAIUserServiceApi*>(objClient.get());
    if (!raw) {
        qWarning() << "Failed to create Pomodoro API client (type mismatch).";
        return;
    }
    mApiClient.reset(raw);
    objClient.release(); // ownership moved to mApiClient

    connect(mApiClient.get(), &OpenAPI::OAIUserServiceApi::userServiceGetUserSignal,
            this, &GetUserCommand::onUserRetrieved);
    connect(mApiClient.get(), &OpenAPI::OAIUserServiceApi::userServiceGetUserSignalError,
            this, &GetUserCommand::onUserError);

    mApiClient->userServiceGetUser(mUserId);
}

void GetUserCommand::setResponseHandler(IResponseHandlerPtr handler)
{
    mResponseHandler = handler;
}

IResponseHandlerPtr GetUserCommand::getResponseHandler() const
{
    return mResponseHandler;
}

void GetUserCommand::onUserRetrieved(const OAIUser_serviceGetUserResponse& response)
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
    if (obj.contains("user") && obj["user"].isObject()) {
        mUser = obj["user"].toObject();
    } else {
        qWarning() << "Response JSON does not contain 'user' object";
    }
    
    emit completed();
}

void GetUserCommand::onUserError(const OAIUser_serviceGetUserResponse& response,
                                          QNetworkReply::NetworkError errorType, const QString& errorStr)
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

QJsonObject GetUserCommand::getUser() const
{
    return mUser;
}
