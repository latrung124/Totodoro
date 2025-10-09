/**
 * @file CreateTaskCommand.h
 * @author trung.la
 * @date 09-13-2025
 * @brief Declaration of CreateTaskCommand class that handles creating tasks via the OpenAPI client.
 */

#pragma once

#pragma once

#include <memory>
#include <QJsonObject>
#include <QNetworkReply>

#include "command/IApiCommand.h"

// Generated client types
#include <OAITask_managementCreateTaskResponse.h>
#include <OAITaskManagementServiceApi.h>
#include <OAITaskManagementServiceCreateTaskBody.h>

class CreateTaskCommand : public IApiCommand
{
	Q_OBJECT

public:
	using OAIRequest = OpenAPI::OAITaskManagementServiceCreateTaskBody;
	using OAIResponse = OpenAPI::OAITask_managementCreateTaskResponse;
	using OAITaskManagementServiceApi = OpenAPI::OAITaskManagementServiceApi;

	CreateTaskCommand(
	    const QString &groupId,
	    const OAIRequest &body,
	    const QString &baseUrl,
	    QObject *parent = nullptr);

	void execute() override;

	void setResponseHandler(IResponseHandlerPtr handler) override;
	IResponseHandlerPtr getResponseHandler() const override;

	QJsonObject getTask() const;

private slots:
	void onCreated(const OAIResponse &response);
	void onError(
	    const OAIResponse &summary, QNetworkReply::NetworkError errorType, const QString &errorStr);

private:
	QString mGroupId;
	OAIRequest mBody;
	QJsonObject mTask;
	QString mBaseUrl;
	IResponseHandlerPtr mResponseHandler;
	std::unique_ptr<OAITaskManagementServiceApi> mApiClient;
};
