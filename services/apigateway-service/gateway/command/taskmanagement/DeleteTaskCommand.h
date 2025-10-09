/**
 * @file DeleteTaskCommand.h
 * @author trung.la
 * @date 09-14-2025
 * @brief DeleteTaskCommand class definition
 */

#pragma once

#include <QNetworkReply>

#include "command/IApiCommand.h"

#include <OAITask_managementDeleteTaskResponse.h>
#include <OAITaskManagementServiceApi.h>

class DeleteTaskCommand : public IApiCommand
{
	Q_OBJECT

public:
	using OAITask_managementDeleteTaskResponse = OpenAPI::OAITask_managementDeleteTaskResponse;
	DeleteTaskCommand(const QString &taskId, const QString &baseUrl, QObject *parent = nullptr);
	~DeleteTaskCommand() override = default;

	void execute() override;
	void setResponseHandler(IResponseHandlerPtr handler) override;
	IResponseHandlerPtr getResponseHandler() const override;

	bool isDeleted() const;

private slots:
	// Private slots to handle API responses
	void onTaskDeleted(const OAITask_managementDeleteTaskResponse &response);
	void onTaskError(
	    const OAITask_managementDeleteTaskResponse &response,
	    QNetworkReply::NetworkError errorType,
	    const QString &errorStr);

private:
	bool mDeleted;
	QString mTaskId;
	QString mBaseUrl;
	IResponseHandlerPtr mResponseHandler;
	std::unique_ptr<OpenAPI::OAITaskManagementServiceApi> mApiClient;
};
