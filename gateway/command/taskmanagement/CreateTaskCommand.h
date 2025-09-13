/**
 * @file CreateTaskCommand.h
 * @author trung.la
 * @date 09-13-2025
 * @brief Declaration of CreateTaskCommand class that handles creating tasks via the OpenAPI client.
 */

#pragma once

#pragma once

#include <QNetworkReply>
#include <QJsonObject>
#include <memory>

#include "IApiCommand.h"
#include "ApiClientFactory.h"

// Generated client types
#include <OAITaskManagementServiceApi.h>
#include <OAITask_managementCreateTaskRequest.h>
#include <OAITask_managementCreateTaskResponse.h>

class CreateTaskCommand : public IApiCommand
{
    Q_OBJECT
public:
    using OAIRequest  = OpenAPI::OAITask_managementCreateTaskRequest;
    using OAIResponse = OpenAPI::OAITask_managementCreateTaskResponse;

    CreateTaskCommand(const OAIRequest& body,
                      ApiClientFactoryPtr factory,
                      const QString& baseUrl,
                      QObject* parent = nullptr);

    void execute() override;

    void setResponseHandler(IResponseHandlerPtr handler) override;
    IResponseHandlerPtr getResponseHandler() const override;

    QJsonObject getTask() const;

private slots:
    void onCreated(const OAIResponse& response);
    void onError(const OAIResponse& summary,
                 QNetworkReply::NetworkError errorType,
                 const QString& errorStr);

private:
    OAIRequest mBody;
    QJsonObject mTask;

    ApiClientFactoryPtr mApiClientFactory;
    QString mBaseUrl;
    IResponseHandlerPtr mResponseHandler;

    std::unique_ptr<OpenAPI::OAITaskManagementServiceApi> mApiClient;
}