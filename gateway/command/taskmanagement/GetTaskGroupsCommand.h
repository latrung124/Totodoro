/**
 * @file command/taskmanagement/GetTaskGroupsCommand.h
 * @author trung.la
 * @date 09-11-2025
 * @brief Header file for GetTaskGroupsCommand class that handles retrieving task groups via the OpenAPI client.
 */

#pragma once

#include <QNetworkReply>
#include <QJsonObject>
#include <QList>
#include <QVariantMap>
#include <memory>

#include "command/IApiCommand.h"

// Generated client types
#include <OAITaskManagementServiceApi.h>
#include <OAITask_managementGetTaskGroupsResponse.h>

class GetTaskGroupsCommand : public IApiCommand
{
    Q_OBJECT
public:
    using OAIResponse = OpenAPI::OAITask_managementGetTaskGroupsResponse;

    GetTaskGroupsCommand(const QString& userId,
                           const QString& baseUrl,
                           QObject* parent = nullptr);

    void execute() override;

    void setResponseHandler(IResponseHandlerPtr handler) override;
    IResponseHandlerPtr getResponseHandler() const override;

    QList<QVariantMap> getGroups() const;

private slots:
    void onTaskGroupsRetrieved(const OAIResponse& response);
    void onTaskGroupsError(const OAIResponse& response,
                 QNetworkReply::NetworkError errorType,
                 const QString& errorStr);

private:
    QString mUserId;
    QList<QVariantMap> mGroups;
    QString mBaseUrl;
    IResponseHandlerPtr mResponseHandler;
    std::unique_ptr<OpenAPI::OAITaskManagementServiceApi> mApiClient;
};
