/**
 * @file command/pomodoro/GetSessionByIdCommand.h
 * @author trung.la
 * @date 09-03-2025
 * @brief Command to get a Pomodoro session by ID via the Pomodoro API.
 */

#pragma once

#include <QJsonObject>
#include <QNetworkReply>

#include "command/IApiCommand.h"

namespace OpenAPI {

class OAIPomodoroServiceApi;
class OAIPomodoro_serviceGetSessionByIdResponse;

} // namespace OpenAPI

class GetSessionByIdCommand : public IApiCommand
{
    Q_OBJECT
public:
    using OAIPomodoro_serviceGetSessionByIdResponse = OpenAPI::OAIPomodoro_serviceGetSessionByIdResponse;
    GetSessionByIdCommand(
        const QString& sessionId,
        const QString& baseUrl,
        QObject* parent = nullptr);
    ~GetSessionByIdCommand();

    void execute() override;
    void setResponseHandler(IResponseHandlerPtr handler) override;
    IResponseHandlerPtr getResponseHandler() const override;

    QJsonObject getSession() const;

private slots:
    // Private slots to handle API responses
    void onSessionRetrieved(const OAIPomodoro_serviceGetSessionByIdResponse& response);
    void onSessionError(const OAIPomodoro_serviceGetSessionByIdResponse& summary,
                       QNetworkReply::NetworkError errorType, const QString& errorStr);
private:
    QString mSessionId;
    QJsonObject mSession;
    QString mBaseUrl;
    IResponseHandlerPtr mResponseHandler;
    std::unique_ptr<OpenAPI::OAIPomodoroServiceApi> mApiClient;
};
