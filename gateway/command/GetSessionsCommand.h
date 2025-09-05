/**
 * @file GetSessionsCommand.h
 * @author trung.la
 * @date 09-04-2025
 * @brief Command to get all Pomodoro sessions for a user via the Pomodoro API.
 */

#pragma once

#include "IApiCommand.h"

#include "IPomodoroApiClientFactory.h"

#include "OAIPomodoro_serviceGetSessionsResponse.h"

class GetSessionsCommand : public IApiCommand {
    Q_OBJECT
public:
    using OAIPomodoro_serviceGetSessionsResponse = OpenAPI::OAIPomodoro_serviceGetSessionsResponse;
    using IPomodoroApiClientFactoryPtr = std::shared_ptr<IPomodoroApiClientFactory>;

    GetSessionsCommand(const QString& userId,
        const QString& taskId,
        IPomodoroApiClientFactoryPtr factory,
        const QString& baseUrl,
        QObject* parent = nullptr);
    ~GetSessionsCommand() override = default;

    void execute() override;
    void setResponseHandler(IResponseHandlerPtr handler) override;
    IResponseHandlerPtr getResponseHandler() const override;

private slots:
    void onSessionsRetrieved(const OAIPomodoro_serviceGetSessionsResponse& response);
    void onSessionsError(const OAIPomodoro_serviceGetSessionsResponse& response, QNetworkReply::NetworkError errorType, const QString& errorStr);

private:
    QString mUserId;
    QString mTaskId;
    IPomodoroApiClientFactoryPtr mFactory;
    QString mBaseUrl;
    IResponseHandlerPtr mResponseHandler;
    std::unique_ptr<OpenAPI::OAIPomodoroServiceApi> mApiClient;
};
