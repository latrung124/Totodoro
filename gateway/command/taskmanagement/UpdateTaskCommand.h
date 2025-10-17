/**
 * @file command/taskmanagement/UpdateTaskCommand.h
 * @author trung.la
 * @date 09-11-2025
 * @brief Header file for UpdateTaskCommand class that handles updating a task group via the OpenAPI client.
 */

#pragma once

#include <QNetworkReply>
#include <QJsonObject>

#include "command/IApiCommand.h"

namespace OpenAPI
{
    class OAITaskManagementServiceApi;
    class OAITaskManagementServiceUpdateTaskBody;
    class OAITask_managementUpdateTaskResponse;
} // namespace OpenAPI

class UpdateTaskCommand : public IApiCommand
{
    Q_OBJECT
public:
    using OAITaskManagementServiceUpdateTaskBody = OpenAPI::OAITaskManagementServiceUpdateTaskBody;
    using OAITask_managementUpdateTaskResponse = OpenAPI::OAITask_managementUpdateTaskResponse;
    using OAITaskManagementServiceApiUPtr = std::unique_ptr<OpenAPI::OAITaskManagementServiceApi>;
    using OAITaskManagementServiceUpdateTaskBodyUPtr = std::unique_ptr<OAITaskManagementServiceUpdateTaskBody>;

    UpdateTaskCommand(const OAITaskManagementServiceUpdateTaskBody& updateTaskBody,
                        const QString& taskId,
                        const QString& baseUrl,
                        QObject* parent = nullptr);
    ~UpdateTaskCommand();

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
    OAITaskManagementServiceUpdateTaskBodyUPtr mUpdateTaskBody;
    QString mTaskId;
    QString mBaseUrl;
    IResponseHandlerPtr mResponseHandler;
    OAITaskManagementServiceApiUPtr mApiClient;
};
 