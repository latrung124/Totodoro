/**
 * @file command/taskmanagement/UpdateTaskCommand.h
 * @author trung.la
 * @date 09-11-2025
 * @brief Header file for UpdateTaskCommand class that handles updating a task group via the OpenAPI client.
 */

#pragma once

#include <QJsonObject>

#include "command/IApiCommand.h"

#include <OAITaskManagementServiceApi.h>
#include <OAITaskManagementServiceUpdateTaskBody.h>
#include <OAITask_managementUpdateTaskResponse.h>

class UpdateTaskCommand : public IApiCommand
{
    Q_OBJECT
public:
    using OAITaskManagementServiceUpdateTaskBody = OpenAPI::OAITaskManagementServiceUpdateTaskBody;
    using OAITask_managementUpdateTaskResponse = OpenAPI::OAITask_managementUpdateTaskResponse;
    using OAITaskManagementServiceApiUPtr = std::unique_ptr<OpenAPI::OAITaskManagementServiceApi>;
    UpdateTaskCommand(const OAITaskManagementServiceUpdateTaskBody& updateTaskBody,
                        const QString& taskId,
                        const QString& baseUrl,
                        QObject* parent = nullptr);
    ~UpdateTaskCommand() override = default;

    void execute() override;
    void setResponseHandler(IResponseHandlerPtr handler) override;
    IResponseHandlerPtr getResponseHandler() const override;

    QJsonObject getTask() const;

private slots:
    void onTaskUpdated(const OAITask_managementUpdateTaskResponse& response);
    void onTaskError(const OAITask_managementUpdateTaskResponse& response,
                       QNetworkReply::NetworkError errorType, const QString& errorStr);

private:
    QJsonObject mTask;
    OAITaskManagementServiceUpdateTaskBody mUpdateTaskBody;
    QString mTaskId;
    QString mBaseUrl;
    IResponseHandlerPtr mResponseHandler;
    OAITaskManagementServiceApiUPtr mApiClient;
};
 