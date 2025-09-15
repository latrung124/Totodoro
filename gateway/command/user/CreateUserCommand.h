/**
 * @file CreateUserCommand.h
 * @author trung.la
 * @date 09-15-2025
 * @brief Declaration of CreateUserCommand class that handles creating a user via the OpenAPI client.
 */

#pragma once

#include "IApiCommand.h"
#include "ApiClientFactory.h"

#include <OAIUserServiceApi.h>
#include <OAIUser_serviceCreateUserRequest.h>
#include <OAIUser_serviceCreateUserResponse.h>

class CreateUserCommand : public IApiCommand
{
    Q_OBJECT
public:
    using ApiClientFactoryPtr = std::shared_ptr<ApiClientFactory>;
    using OAIUser_serviceCreateUserRequest = OpenAPI::OAIUser_serviceCreateUserRequest;
    using OAIUser_serviceCreateUserResponse = OpenAPI::OAIUser_serviceCreateUserResponse;
    using OAIUserServiceApiUPtr = std::unique_ptr<OpenAPI::OAIUserServiceApi>;

    CreateUserCommand(const ApiClientFactoryPtr& apiClientFactory,
                      const OAIUser_serviceCreateUserRequest& createUserRequest,
                      const QString& baseUrl,
                      QObject* parent = nullptr);
    ~CreateUserCommand() override = default;

    void execute() override;
    void setResponseHandler(IResponseHandlerPtr handler) override;
    IResponseHandlerPtr getResponseHandler() const override;

    QJsonObject getUser() const;

private slots:
    void onUserCreated(const OAIUser_serviceCreateUserResponse& response);
    void onUserError(const OAIUser_serviceCreateUserResponse& response,
                     QNetworkReply::NetworkError errorType, const QString& errorStr);

private:
    QJsonObject mUser;
    ApiClientFactoryPtr mApiClientFactory;
    OAIUser_serviceCreateUserRequest mCreateUserRequest;
    QString mBaseUrl;
    IResponseHandlerPtr mResponseHandler;
    OAIUserServiceApiUPtr mApiClient;
};