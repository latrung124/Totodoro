/**
 * @file CreateSessionCommand.h
 * @author trung.la
 * @date 09-03-2025
 * @brief Command to create a Pomodoro session via the Pomodoro API.
 */

#pragma once

#include <QNetworkReply>
#include <QJsonObject>

#include "IApiCommand.h"
#include "ApiClientFactory.h"

#include <OAIPomodoroServiceApi.h>
#include <OAIPomodoroServiceCreateSessionBody.h>
#include <OAIPomodoro_serviceCreateSessionResponse.h>

class CreateSessionCommand : public IApiCommand
{
    Q_OBJECT
public:
    using OAIPomodoroServiceCreateSessionBody = OpenAPI::OAIPomodoroServiceCreateSessionBody;
    using OAIPomodoro_serviceCreateSessionResponse = OpenAPI::OAIPomodoro_serviceCreateSessionResponse;
    CreateSessionCommand(const QString& userId, 
        const OAIPomodoroServiceCreateSessionBody& body,
        ApiClientFactoryPtr factory,
        const QString& baseUrl,
        QObject* parent = nullptr);
    ~CreateSessionCommand() override = default;

    void execute() override;
    void setResponseHandler(IResponseHandlerPtr handler) override;
    IResponseHandlerPtr getResponseHandler() const override;

    QJsonObject getSession() const;

private slots:
    // Private slots to handle API responses
    void onSessionCreated(const OAIPomodoro_serviceCreateSessionResponse& response);
    void onSessionError(const OAIPomodoro_serviceCreateSessionResponse& summary, 
                       QNetworkReply::NetworkError errorType, const QString& errorStr);

private:
    QString mUserId;
    QJsonObject mSession;
    OAIPomodoroServiceCreateSessionBody mBody;
    ApiClientFactoryPtr mApiClientFactory;
    QString mBaseUrl;
    IResponseHandlerPtr mResponseHandler;
    std::unique_ptr<OpenAPI::OAIPomodoroServiceApi> mApiClient;
};
