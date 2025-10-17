/**
 * @file command/taskmanagement/DeleteTaskGroupCommand.h
 * @author trung.la
 * @date 09-11-2025
 * @brief Header file for DeleteTaskGroupCommand class that handles deleting a task group via the OpenAPI client.
 */

#pragma once

#include <QNetworkReply>

#include "command/IApiCommand.h"

namespace OpenAPI
{
    class OAITaskManagementServiceApi;
    class OAITask_managementDeleteTaskGroupResponse;
} // namespace OpenAPI

class DeleteTaskGroupCommand : public IApiCommand
{
    Q_OBJECT
public:
    using OAITask_managementDeleteTaskGroupResponse = OpenAPI::OAITask_managementDeleteTaskGroupResponse;
    using OAITaskManagementServiceApiUPtr = std::unique_ptr<OpenAPI::OAITaskManagementServiceApi>;

    DeleteTaskGroupCommand(const QString& groupId,
        const QString& baseUrl,
        QObject* parent = nullptr);
    ~DeleteTaskGroupCommand();

    void execute() override;
    void setResponseHandler(IResponseHandlerPtr handler) override;
    IResponseHandlerPtr getResponseHandler() const override;

    bool isDeleted() const;

private slots:
    // Private slots to handle API responses
    void onTaskGroupDeleted(const OAITask_managementDeleteTaskGroupResponse& response);
    void onTaskGroupError(const OAITask_managementDeleteTaskGroupResponse& response,
                       QNetworkReply::NetworkError errorType, const QString& errorStr);

private:
    bool mDeleted;
    QString mGroupId;
    QString mBaseUrl;
    IResponseHandlerPtr mResponseHandler;
    OAITaskManagementServiceApiUPtr mApiClient;
};
