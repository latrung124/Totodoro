/**
 * @file command/pomodoro/DeleteSessionCommand.h
 * @author trung.la
 * @date 09-07-2025
 * @brief Command to delete a pomodoro session.
 */

#pragma once

#include <QNetworkReply>

#include "command/IApiCommand.h"

#include <OAIPomodoroServiceApi.h>
#include <OAIPomodoro_serviceDeleteSessionResponse.h>

class DeleteSessionCommand : public IApiCommand
{
    Q_OBJECT
public:
    using OAIPomodoro_serviceDeleteSessionResponse = OpenAPI::OAIPomodoro_serviceDeleteSessionResponse;
    DeleteSessionCommand(const QString& sessionId,
        const QString& baseUrl,
        QObject* parent = nullptr);
    ~DeleteSessionCommand() override = default;

    void execute() override;
    void setResponseHandler(IResponseHandlerPtr handler) override;
    IResponseHandlerPtr getResponseHandler() const override;

    bool isDeleted() const;

private slots:
    // Private slots to handle API responses
    void onSessionDeleted(const OAIPomodoro_serviceDeleteSessionResponse& response);
    void onSessionError(const OAIPomodoro_serviceDeleteSessionResponse& summary,
                       QNetworkReply::NetworkError errorType, const QString& errorStr);

private:
    bool mDeleted;
    QString mSessionId;
    QString mBaseUrl;
    IResponseHandlerPtr mResponseHandler;
    std::unique_ptr<OpenAPI::OAIPomodoroServiceApi> mApiClient;
};
