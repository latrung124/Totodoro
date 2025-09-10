/**
 * @file CreateTaskGroupCommand.h
 * @author trung.la
 * @date 09-10-2025
 * @brief Command to create a new task group for a user.
 */

#pragma once

#include <QNetworkReply>
#include <QJsonObject>
#include <memory>

#include "IApiCommand.h"
#include "ApiClientFactory.h"

// Generated client types
#include <OAITaskManagementServiceApi.h>
#include <OAITask_managementCreateTaskGroupRequest.h>
#include <OAITask_managementCreateTaskGroupResponse.h>

class CreateTaskGroupCommand : public IApiCommand
{
    Q_OBJECT
public:
    using OAIRequest  = OpenAPI::OAITask_managementCreateTaskGroupRequest;
    using OAIResponse = OpenAPI::OAITask_managementCreateTaskGroupResponse;

    CreateTaskGroupCommand(const OAIRequest& body,
                           ApiClientFactoryPtr factory,
                           const QString& baseUrl,
                           QObject* parent = nullptr);

    void execute() override;

    void setResponseHandler(IResponseHandlerPtr handler) override;
    IResponseHandlerPtr getResponseHandler() const override;

    QJsonObject getGroup() const;

private slots:
    void onCreated(const OAIResponse& response);
    void onError(const OAIResponse& summary,
                 QNetworkReply::NetworkError errorType,
                 const QString& errorStr);

private:
    OAIRequest mBody;
    QJsonObject mGroup;

    ApiClientFactoryPtr mApiClientFactory;
    QString mBaseUrl;
    IResponseHandlerPtr mResponseHandler;

    std::unique_ptr<OpenAPI::OAITaskManagementServiceApi> mApiClient;
};