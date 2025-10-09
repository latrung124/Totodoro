/**
 * @file UpdateTaskGroupCommand.h
 * @author trung.la
 * @date 09-11-2025
 * @brief Header file for UpdateTaskGroupCommand class that handles updating a task group via the
 * OpenAPI client.
 */

#pragma once

#include <QJsonObject>

#include "command/IApiCommand.h"

#include <OAITask_managementUpdateTaskGroupResponse.h>
#include <OAITaskManagementServiceApi.h>
#include <OAITaskManagementServiceUpdateTaskGroupBody.h>

class UpdateTaskGroupCommand : public IApiCommand
{
	Q_OBJECT

public:
	using OAITaskManagementServiceUpdateTaskGroupBody =
	    OpenAPI::OAITaskManagementServiceUpdateTaskGroupBody;
	using OAITask_managementUpdateTaskGroupResponse =
	    OpenAPI::OAITask_managementUpdateTaskGroupResponse;
	using OAITaskManagementServiceApiUPtr = std::unique_ptr<OpenAPI::OAITaskManagementServiceApi>;
	UpdateTaskGroupCommand(
	    const OAITaskManagementServiceUpdateTaskGroupBody &updateTaskGroupBody,
	    const QString &taskGroupId,
	    const QString &baseUrl,
	    QObject *parent = nullptr);
	~UpdateTaskGroupCommand() override = default;

	void execute() override;
	void setResponseHandler(IResponseHandlerPtr handler) override;
	IResponseHandlerPtr getResponseHandler() const override;

	QJsonObject getTaskGroup() const;

private slots:
	void onTaskGroupUpdated(const OAITask_managementUpdateTaskGroupResponse &summary);
	void onTaskGroupError(
	    const OAITask_managementUpdateTaskGroupResponse &summary,
	    QNetworkReply::NetworkError errorType,
	    const QString &errorStr);

private:
	QJsonObject mTaskGroup;
	OAITaskManagementServiceUpdateTaskGroupBody mUpdateTaskGroupBody;
	QString mTaskGroupId;
	QString mBaseUrl;
	IResponseHandlerPtr mResponseHandler;
	OAITaskManagementServiceApiUPtr mApiClient;
};
