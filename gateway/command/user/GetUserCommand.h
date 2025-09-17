/**
 * @file GetUserCommand.h
 * @author trung.la
 * @date 09-17-2025
 * @brief Declaration of GetUserCommand class that handles retrieving a user via the OpenAPI client.
 */

#pragma once

#include <QJsonObject>
#include <QNetworkReply>

#include "IApiCommand.h"

#include "ApiClientFactory.h"

#include <OAIUserServiceApi.h>
#include <OAIUser_serviceGetUserResponse.h>

class GetUserCommand : public IApiCommand
{
    Q_OBJECT
public:
    using OAIUser_serviceGetUserResponse = OpenAPI::OAIUser_serviceGetUserResponse;
    using ApiClientFactoryPtr = std::shared_ptr<ApiClientFactory>;
    GetUserCommand(
        const QString& userId,
        ApiClientFactoryPtr factory,
        const QString& baseUrl,
        QObject* parent = nullptr);
    ~GetUserCommand() override = default;

    void execute() override;
    void setResponseHandler(IResponseHandlerPtr handler) override;
    IResponseHandlerPtr getResponseHandler() const override;

    QJsonObject getUser() const;

private slots:
    // Private slots to handle API responses
    void onUserRetrieved(const OAIUser_serviceGetUserResponse& response);
    void onUserError(const OAIUser_serviceGetUserResponse& response,
                       QNetworkReply::NetworkError errorType, const QString& errorStr);
private:
    QString mUserId;
    QJsonObject mUser;
    ApiClientFactoryPtr mApiClientFactory;
    QString mBaseUrl;
    IResponseHandlerPtr mResponseHandler;
    std::unique_ptr<OpenAPI::OAIUserServiceApi> mApiClient;
};
