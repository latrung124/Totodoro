/**
 * @file GetSessionsCommand.h
 * @author trung.la
 * @date 09-04-2025
 * @brief Command to get all Pomodoro sessions for a user via the Pomodoro API.
 */

#pragma once

#include <QList>
#include <QVariantMap>

#include "command/IApiCommand.h"

#include "OAIPomodoro_serviceGetSessionsResponse.h"
#include <OAIPomodoroServiceApi.h>

class GetSessionsCommand : public IApiCommand
{
	Q_OBJECT

public:
	using OAIPomodoro_serviceGetSessionsResponse = OpenAPI::OAIPomodoro_serviceGetSessionsResponse;

	GetSessionsCommand(
	    const QString &userId,
	    const QString &taskId,
	    const QString &baseUrl,
	    QObject *parent = nullptr);
	~GetSessionsCommand() override = default;

	void execute() override;
	void setResponseHandler(IResponseHandlerPtr handler) override;
	IResponseHandlerPtr getResponseHandler() const override;

	QList<QVariantMap> getSessions() const;

private slots:
	void onSessionsRetrieved(const OAIPomodoro_serviceGetSessionsResponse &response);
	void onSessionsError(
	    const OAIPomodoro_serviceGetSessionsResponse &response,
	    QNetworkReply::NetworkError errorType,
	    const QString &errorStr);

private:
	QString mUserId;
	QString mTaskId;
	QString mBaseUrl;
	QList<QVariantMap> mSessions;
	IResponseHandlerPtr mResponseHandler;
	std::unique_ptr<OpenAPI::OAIPomodoroServiceApi> mApiClient;
};
