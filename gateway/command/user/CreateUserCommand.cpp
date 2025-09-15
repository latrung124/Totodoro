/**
 * @file CreateUserCommand.cpp
 * @author trung.la
 * @date 09-15-2025
 * @brief Implementation of CreateUserCommand class that handles creating a user via the OpenAPI client.
 */

#include "CreateUserCommand.h"

CreateUserCommand::CreateUserCommand(const ApiClientFactoryPtr& apiClientFactory,
    const OAIUser_serviceCreateUserRequest& createUserRequest,
    const QString& baseUrl,
    QObject* parent)
    : IApiCommand(parent),
      mUser(),
      mApiClientFactory(apiClientFactory),
      mCreateUserRequest(createUserRequest),
      mBaseUrl(baseUrl),
      mResponseHandler(nullptr),
      mApiClient(nullptr)
{
}

void CreateUserCommand::execute()
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
    auto objClient = mApiClientFactory->createClient(gateway::RouteType::User, mBaseUrl);
    auto raw = qobject_cast<OpenAPI::OAIUserServiceApi*>(objClient.get());
    if (!raw) {
        qWarning() << "Failed to create User API client (type mismatch).";
        return;
    }
    mApiClient.reset(raw);
    objClient.release(); // ownership moved to mApiClient

    connect(mApiClient.get(), &OpenAPI::OAIUserServiceApi::userServiceCreateUserSignal,
            this, &CreateUserCommand::onUserCreated);
    connect(mApiClient.get(), &OpenAPI::OAIUserServiceApi::userServiceCreateUserSignalError,
            this, &CreateUserCommand::onUserError);

    mApiClient->userServiceCreateUser(mCreateUserRequest);
}

void CreateUserCommand::setResponseHandler(IResponseHandlerPtr handler)
{
    mResponseHandler = handler;
}

IResponseHandlerPtr CreateUserCommand::getResponseHandler() const
{
    return mResponseHandler;
}

QJsonObject CreateUserCommand::getUser() const
{
    return mUser;
}

void CreateUserCommand::onUserCreated(const OAIUser_serviceCreateUserResponse& response)
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
    if (!obj.contains("user") || !obj["user"].isObject()) {
        qWarning() << "Response does not contain a valid 'user' object";
        emit completed();
        return;
    }

    mUser = obj["user"].toObject();

    emit completed();
}

void CreateUserCommand::onUserError(const OAIUser_serviceCreateUserResponse& response,
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
