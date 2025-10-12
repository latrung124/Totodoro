/**
 * @file GetTaskCommand.h
 * @author trung.la
 * @date 09-14-2025
 * @brief Header file for GetTaskCommand class that handles retrieving a task via the OpenAPI client.
 */

#pragma once

#include <QNetworkReply>
#include <QJsonObject>
#include <QList>
#include <QVariantMap>
#include <memory>

#include "IApiCommand.h"
#include "ApiClientFactory.h"

// Generated client types
#include <OAITaskManagementServiceApi.h>
#include <OAITask_managementGetTasksResponse.h>

class GetTasksCommand : public IApiCommand
{
    Q_OBJECT
public:
    using OAIResponse = OpenAPI::OAITask_managementGetTasksResponse;

    GetTasksCommand(const QString& userId,
                    const QString& groupId,
                           const QString& baseUrl,
                           QObject* parent = nullptr);

    void execute() override;

    void setResponseHandler(IResponseHandlerPtr handler) override;
    IResponseHandlerPtr getResponseHandler() const override;

    QList<QVariantMap> getTasks() const;

private slots:
    void onTasksRetrieved(const OAIResponse& response);
    void onTasksError(const OAIResponse& response,
                 QNetworkReply::NetworkError errorType,
                 const QString& errorStr);

private:
    QString mUserId;
    QString mGroupId;
    QList<QVariantMap> mTasks;
    QString mBaseUrl;
    IResponseHandlerPtr mResponseHandler;
    std::unique_ptr<OpenAPI::OAITaskManagementServiceApi> mApiClient;
};
