/**
 * @file UpdateUserCommand.h
 * @author trung.la
 * @date 09-17-2025
 * @brief Declaration of UpdateUserCommand class that handles updating a user via the OpenAPI client.
 */

#pragma once

#include <QJsonObject>

#include "IApiCommand.h"

#include <OAIUserServiceApi.h>
#include <OAIUserServiceUpdateUserBody.h>
#include <OAIUser_serviceUpdateUserResponse.h>

class UpdateUserCommand : public IApiCommand
{
    Q_OBJECT
public:
    using OAIUserServiceUpdateUserBody = OpenAPI::OAIUserServiceUpdateUserBody;
    using OAIUser_serviceUpdateUserResponse = OpenAPI::OAIUser_serviceUpdateUserResponse;
    using OAIUserServiceApiUPtr = std::unique_ptr<OpenAPI::OAIUserServiceApi>;
    UpdateUserCommand(const OAIUserServiceUpdateUserBody& updateUserBody,
                        const QString& userId,
                        const QString& baseUrl,
                        QObject* parent = nullptr);
    ~UpdateUserCommand() override = default;

    void execute() override;
    void setResponseHandler(IResponseHandlerPtr handler) override;
    IResponseHandlerPtr getResponseHandler() const override;

    QJsonObject getUser() const;

private slots:
    void onUserUpdated(const OAIUser_serviceUpdateUserResponse& response);
    void onUserError(const OAIUser_serviceUpdateUserResponse& response,
                       QNetworkReply::NetworkError errorType, const QString& errorStr);

private:
    QJsonObject mUser;
    OAIUserServiceUpdateUserBody mUpdateUserBody;
    QString mUserId;
    QString mBaseUrl;
    IResponseHandlerPtr mResponseHandler;
    OAIUserServiceApiUPtr mApiClient;
};
