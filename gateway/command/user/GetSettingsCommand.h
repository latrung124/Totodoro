/**
 * @file GetSettingsCommand.h
 * @author trung.la
 * @date 09-18-2025
 * @brief Declaration of GetSettingsCommand class that handles fetching user settings via the OpenAPI client.
 */

#pragma once

#include <QJsonObject>
#include <QNetworkReply>

#include "IApiCommand.h"

#include "ApiClientFactory.h"

#include <OAIUserServiceApi.h>
#include <OAIUser_serviceGetSettingsResponse.h>

class GetSettingsCommand : public IApiCommand
{
    Q_OBJECT
public:
    using OAIUser_serviceGetSettingsResponse = OpenAPI::OAIUser_serviceGetSettingsResponse;
    using ApiClientFactoryPtr = std::shared_ptr<ApiClientFactory>;
    GetSettingsCommand(
        const QString& userId,
        ApiClientFactoryPtr factory,
        const QString& baseUrl,
        QObject* parent = nullptr);
    ~GetSettingsCommand() override = default;

    void execute() override;
    void setResponseHandler(IResponseHandlerPtr handler) override;
    IResponseHandlerPtr getResponseHandler() const override;

    QJsonObject getSettings() const;

private slots:
    // Private slots to handle API responses
    void onSettingsRetrieved(const OAIUser_serviceGetSettingsResponse& response);
    void onSettingsError(const OAIUser_serviceGetSettingsResponse& response,
                       QNetworkReply::NetworkError errorType, const QString& errorStr);
private:
    QString mUserId;
    QJsonObject mSettings;
    ApiClientFactoryPtr mApiClientFactory;
    QString mBaseUrl;
    IResponseHandlerPtr mResponseHandler;
    std::unique_ptr<OpenAPI::OAIUserServiceApi> mApiClient;
};
