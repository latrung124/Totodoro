/**
 * @file DeleteTaskCommand.h
 * @author trung.la
 * @date 09-14-2025
 * @brief DeleteTaskCommand class definition
 */

#pragma once

#include <QNetworkReply>

#include "ApiClientFactory.h"
#include "IApiCommand.h"

#include <OAITaskManagementServiceApi.h>
#include <OAITask_managementDeleteTaskResponse.h>

class DeleteTaskCommand : public IApiCommand
{
    Q_OBJECT
public:
    using OAITask_managementDeleteTaskResponse = OpenAPI::OAITask_managementDeleteTaskResponse;
    DeleteTaskCommand(const QString& taskId,
        ApiClientFactoryPtr factory,
        const QString& baseUrl,
        QObject* parent = nullptr);
    ~DeleteTaskCommand() override = default;

    void execute() override;
    void setResponseHandler(IResponseHandlerPtr handler) override;
    IResponseHandlerPtr getResponseHandler() const override;

    bool isDeleted() const;

private slots:
    // Private slots to handle API responses
    void onTaskDeleted(const OAITask_managementDeleteTaskResponse& response);
    void onTaskError(const OAITask_managementDeleteTaskResponse& response,
                       QNetworkReply::NetworkError errorType, const QString& errorStr);

private:
    bool mDeleted;
    QString mTaskId;
    ApiClientFactoryPtr mApiClientFactory;
    QString mBaseUrl;
    IResponseHandlerPtr mResponseHandler;
    std::unique_ptr<OpenAPI::OAITaskManagementServiceApi> mApiClient;
};
