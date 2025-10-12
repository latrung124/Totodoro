/**
 * @file UpdateUserCommand.cpp
 * @author trung.la
 * @date 09-17-2025
 * @brief Implementation of UpdateUserCommand class that handles updating a user via the OpenAPI client.
 */

#include "command/user/UpdateUserCommand.h"

#include <QDebug>

#include "factory/ApiClientFactory.h"

UpdateUserCommand::UpdateUserCommand(const OAIUserServiceUpdateUserBody& updateUserBody,
                                    const QString& userId,
                                    const QString& baseUrl,
                                    QObject* parent)
    : IApiCommand(parent),
      mUpdateUserBody(updateUserBody),
      mUserId(userId),
      mBaseUrl(baseUrl),
      mResponseHandler(nullptr)
{
}

void UpdateUserCommand::execute()
{
    // Create as QObject then cast to the concrete API type and transfer ownership
    auto objClient = ApiClientFactory::createClient(gateway::RouteType::User, mBaseUrl);
    auto raw = qobject_cast<OpenAPI::OAIUserServiceApi*>(objClient.get());
    if (!raw) {
        qWarning() << "Failed to create Pomodoro API client (type mismatch).";
        return;
    }
    mApiClient.reset(raw);
    objClient.release(); // ownership moved to mApiClient

    // Connect signals for handling responses
    connect(mApiClient.get(), &OpenAPI::OAIUserServiceApi::userServiceUpdateUserSignal,
            this, &UpdateUserCommand::onUserUpdated);
    connect(mApiClient.get(), &OpenAPI::OAIUserServiceApi::userServiceUpdateUserSignalError,
            this, &UpdateUserCommand::onUserError);

    // Execute the update user API call
    mApiClient->userServiceUpdateUser(mUserId, mUpdateUserBody);
}

void UpdateUserCommand::setResponseHandler(IResponseHandlerPtr handler)
{
    mResponseHandler = handler;
}

IResponseHandlerPtr UpdateUserCommand::getResponseHandler() const
{
    return mResponseHandler;
}

void UpdateUserCommand::onUserUpdated(const OAIUser_serviceUpdateUserResponse& summary)
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

    if (doc.object().contains("user") && doc.object()["user"].isObject()) {
        mUser = doc.object()["user"].toObject();
    } else {
        qWarning() << "Response JSON does not contain 'user' object";
    }

    emit completed();
}

void UpdateUserCommand::onUserError(const OAIUser_serviceUpdateUserResponse& summary,
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

QJsonObject UpdateUserCommand::getUser() const
{
    return mUser;
}
