/**
 * @file UpdateSettingsCommand.h
 * @author trung.la
 * @date 09-18-2025
 * @brief Declaration of UpdateSettingsCommand class that handles updating user settings via the OpenAPI client.
 */

#pragma once

#include <QJsonObject>

#include "IApiCommand.h"
#include "ApiClientFactory.h"

#include <OAIUserServiceApi.h>
#include <OAIUserServiceUpdateSettingsBody.h>
#include <OAIUser_serviceUpdateSettingsResponse.h>

class UpdateSettingsCommand : public IApiCommand
{
    Q_OBJECT
public:
    using ApiClientFactoryPtr = std::shared_ptr<ApiClientFactory>;
    using OAIUserServiceUpdateSettingsBody = OpenAPI::OAIUserServiceUpdateSettingsBody;
    using OAIUser_serviceUpdateSettingsResponse = OpenAPI::OAIUser_serviceUpdateSettingsResponse;
    using OAIUserServiceApiUPtr = std::unique_ptr<OpenAPI::OAIUserServiceApi>;
    UpdateSettingsCommand(const ApiClientFactoryPtr& apiClientFactory,
                         const OAIUserServiceUpdateSettingsBody& updateSettingsBody,
                         const QString& userId,
                         const QString& baseUrl,
                         QObject* parent = nullptr);
    ~UpdateSettingsCommand() override = default;

    void execute() override;
    void setResponseHandler(IResponseHandlerPtr handler) override;
    IResponseHandlerPtr getResponseHandler() const override;

    QJsonObject getSettings() const;

private slots:
    void onSettingsUpdated(const OAIUser_serviceUpdateSettingsResponse& response);
    void onSettingsError(const OAIUser_serviceUpdateSettingsResponse& response,
                       QNetworkReply::NetworkError errorType, const QString& errorStr);

private:
    QJsonObject mSettings;
    ApiClientFactoryPtr mApiClientFactory;
    OAIUserServiceUpdateSettingsBody mUpdateSettingsBody;
    QString mUserId;
    QString mBaseUrl;
    IResponseHandlerPtr mResponseHandler;
    OAIUserServiceApiUPtr mApiClient;
};
