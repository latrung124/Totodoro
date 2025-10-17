/**
 * @file command/taskmanagement/CreateTaskCommand.h
 * @author trung.la
 * @date 09-13-2025
 * @brief Declaration of CreateTaskCommand class that handles creating tasks via the OpenAPI client.
 */

#pragma once

#pragma once

#include <memory>
#include <QNetworkReply>
#include <QJsonObject>

#include "command/IApiCommand.h"

namespace OpenAPI
{
    class OAITaskManagementServiceApi;
    class OAITaskManagementServiceCreateTaskBody;
    class OAITask_managementCreateTaskResponse;
} // namespace OpenAPI

class CreateTaskCommand : public IApiCommand
{
    Q_OBJECT
public:
    using OAIRequest  = OpenAPI::OAITaskManagementServiceCreateTaskBody;
    using OAIResponse = OpenAPI::OAITask_managementCreateTaskResponse;
    using OAITaskManagementServiceApi = OpenAPI::OAITaskManagementServiceApi;
    using OAITaskManagementServiceApiUPtr = std::unique_ptr<OAITaskManagementServiceApi>;
    using OAIRequestUPtr = std::unique_ptr<OAIRequest>;

    CreateTaskCommand(const QString& groupId,
                      const OAIRequest& body,
                      const QString& baseUrl,
                      QObject* parent = nullptr);

    ~CreateTaskCommand();

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
    QString mGroupId;
    QJsonObject mTask;
    QString mBaseUrl;
    IResponseHandlerPtr mResponseHandler;
    OAITaskManagementServiceApiUPtr mApiClient;
    OAIRequestUPtr mBody;
};
