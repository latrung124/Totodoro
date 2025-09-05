/**
 * @file UpdateSessionCommand.h
 * @author trung.la
 * @date 09-04-2025
 * @brief Header file for UpdateSessionCommand class that handles updating Pomodoro sessions via the OpenAPI client.
 */

#pragma once

#include "IApiCommand.h"

#include "IPomodoroApiClientFactory.h"
#include <OAIPomodoroServiceUpdateSessionBody.h>

class UpdateSessionCommand : public IApiCommand
{
    Q_OBJECT
public:
    using IPomodoroApiClientFactoryPtr = std::shared_ptr<IPomodoroApiClientFactory>;
    using OAIPomodoroServiceUpdateSessionBody = OpenAPI::OAIPomodoroServiceUpdateSessionBody;
    using OAIPomodoro_serviceUpdateSessionResponse = OpenAPI::OAIPomodoro_serviceUpdateSessionResponse;
    using OAIPomodoroServiceApiUPtr = std::unique_ptr<OpenAPI::OAIPomodoroServiceApi>;
    UpdateSessionCommand(const IPomodoroApiClientFactoryPtr& apiClientFactory,
                         const OAIPomodoroServiceUpdateSessionBody& updateSessionBody,
                         const QString& sessionId,
                         const QString& baseUrl,
                         QObject* parent = nullptr);
    ~UpdateSessionCommand() override = default;

    void execute() override;
    void setResponseHandler(IResponseHandlerPtr handler) override;
    IResponseHandlerPtr getResponseHandler() const override;

private slots:
    void onSessionUpdated(const OAIPomodoro_serviceUpdateSessionResponse& summary);
    void onSessionError(const OAIPomodoro_serviceUpdateSessionResponse& summary,
                       QNetworkReply::NetworkError errorType, const QString& errorStr);

private:
    IPomodoroApiClientFactoryPtr mApiClientFactory;
    OAIPomodoroServiceUpdateSessionBody mUpdateSessionBody;
    QString mSessionId;
    QString mBaseUrl;
    IResponseHandlerPtr mResponseHandler;
    OAIPomodoroServiceApiUPtr mApiClient;
};
