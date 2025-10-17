/**
 * @file command/taskmanagement/CreateTaskGroupCommand.h
 * @author trung.la
 * @date 09-10-2025
 * @brief Command to create a new task group for a user.
 */

#pragma once

#include <QNetworkReply>
#include <QJsonObject>
#include <memory>

#include "command/IApiCommand.h"

namespace OpenAPI
{
    class OAITaskManagementServiceApi;
    class OAITask_managementCreateTaskGroupRequest;
    class OAITask_managementCreateTaskGroupResponse;
} // namespace OpenAPI

class CreateTaskGroupCommand : public IApiCommand
{
    Q_OBJECT
public:
    using OAIRequest  = OpenAPI::OAITask_managementCreateTaskGroupRequest;
    using OAIResponse = OpenAPI::OAITask_managementCreateTaskGroupResponse;
    using OAIRequestUPtr = std::unique_ptr<OAIRequest>;
    using OAIServiceApiUPtr = std::unique_ptr<OpenAPI::OAITaskManagementServiceApi>;

    CreateTaskGroupCommand(const OAIRequest& body,
                           const QString& baseUrl,
                           QObject* parent = nullptr);

    ~CreateTaskGroupCommand();
    
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
    OAIRequestUPtr mBody;
    QJsonObject mGroup;
    QString mBaseUrl;
    IResponseHandlerPtr mResponseHandler;
    OAIServiceApiUPtr mApiClient;
};