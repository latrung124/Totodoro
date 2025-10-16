/**
 * @file command/pomodoro/CreateSessionCommand.h
 * @author trung.la
 * @date 09-03-2025
 * @brief Command to create a Pomodoro session via the Pomodoro API.
 */

#pragma once

#include <memory>
#include <QNetworkReply>
#include <QJsonObject>

#include "command/IApiCommand.h"

namespace OpenAPI
{
    class OAIPomodoroServiceApi;
    class OAIPomodoroServiceCreateSessionBody;
    class OAIPomodoro_serviceCreateSessionResponse;
} // namespace OpenAPI

class CreateSessionCommand : public IApiCommand
{
    Q_OBJECT
public:
    using OAIPomodoroServiceCreateSessionBody = OpenAPI::OAIPomodoroServiceCreateSessionBody;
    using OAIPomodoro_serviceCreateSessionResponse = OpenAPI::OAIPomodoro_serviceCreateSessionResponse;
    using OAIPomodoroServiceCreateSessionBodyUPtr = std::unique_ptr<OAIPomodoroServiceCreateSessionBody>;
    using OAIPomodoroServiceApiUPtr = std::unique_ptr<OpenAPI::OAIPomodoroServiceApi>;

    CreateSessionCommand(const QString& userId, 
        const OAIPomodoroServiceCreateSessionBody& body,
        const QString& baseUrl,
        QObject* parent = nullptr);
    ~CreateSessionCommand();

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
    QString mBaseUrl;
    OAIPomodoroServiceCreateSessionBodyUPtr mBody;
    OAIPomodoroServiceApiUPtr mApiClient;
    IResponseHandlerPtr mResponseHandler;
};
