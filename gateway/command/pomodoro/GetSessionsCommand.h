/**
 * @file GetSessionsCommand.h
 * @author trung.la
 * @date 09-04-2025
 * @brief Command to get all Pomodoro sessions for a user via the Pomodoro API.
 */

#pragma once

#include <QList>
#include <QVariantMap>

#include "IApiCommand.h"
#include "ApiClientFactory.h"

#include <OAIPomodoroServiceApi.h>
#include "OAIPomodoro_serviceGetSessionsResponse.h"

class GetSessionsCommand : public IApiCommand {
    Q_OBJECT
public:
    using OAIPomodoro_serviceGetSessionsResponse = OpenAPI::OAIPomodoro_serviceGetSessionsResponse;
    using ApiClientFactoryPtr = std::shared_ptr<ApiClientFactory>;

    GetSessionsCommand(const QString& userId,
        const QString& taskId,
        ApiClientFactoryPtr factory,
        const QString& baseUrl,
        QObject* parent = nullptr);
    ~GetSessionsCommand() override = default;

    void execute() override;
    void setResponseHandler(IResponseHandlerPtr handler) override;
    IResponseHandlerPtr getResponseHandler() const override;

    QList<QVariantMap> getSessions() const;

private slots:
    void onSessionsRetrieved(const OAIPomodoro_serviceGetSessionsResponse& response);
    void onSessionsError(const OAIPomodoro_serviceGetSessionsResponse& response, QNetworkReply::NetworkError errorType, const QString& errorStr);

private:
    QString mUserId;
    QString mTaskId;
    ApiClientFactoryPtr mApiClientFactory;
    QString mBaseUrl;
    QList<QVariantMap> mSessions;
    IResponseHandlerPtr mResponseHandler;
    std::unique_ptr<OpenAPI::OAIPomodoroServiceApi> mApiClient;
};
