/**
 * @file UpdateSettingsCommand.cpp
 * @author trung.la
 * @date 09-18-2025
 * @brief Implementation of UpdateSettingsCommand class that handles updating user settings via the
 * OpenAPI client
 */

#include "UpdateSettingsCommand.h"

#include <QDebug>

#include "factory/ApiClientFactory.h"

UpdateSettingsCommand::UpdateSettingsCommand(
    const OAIUserServiceUpdateSettingsBody &updateSettingsBody,
    const QString &userId,
    const QString &baseUrl,
    QObject *parent)
    : IApiCommand(parent)
    , mUpdateSettingsBody(updateSettingsBody)
    , mUserId(userId)
    , mBaseUrl(baseUrl)
    , mResponseHandler(nullptr)
{
}

void UpdateSettingsCommand::execute()
{
	// Create as QObject then cast to the concrete API type and transfer ownership
	auto objClient = ApiClientFactory::createClient(gateway::RouteType::User, mBaseUrl);
	auto raw = qobject_cast<OpenAPI::OAIUserServiceApi *>(objClient.get());
	if (!raw) {
		qWarning() << "Failed to create Pomodoro API client (type mismatch).";
		return;
	}
	mApiClient.reset(raw);
	objClient.release(); // ownership moved to mApiClient

	// Connect signals for handling responses
	connect(
	    mApiClient.get(),
	    &OpenAPI::OAIUserServiceApi::userServiceUpdateSettingsSignal,
	    this,
	    &UpdateSettingsCommand::onSettingsUpdated);
	connect(
	    mApiClient.get(),
	    &OpenAPI::OAIUserServiceApi::userServiceUpdateSettingsSignalError,
	    this,
	    &UpdateSettingsCommand::onSettingsError);

	// Execute the update user API call
	mApiClient->userServiceUpdateSettings(mUserId, mUpdateSettingsBody);
}

void UpdateSettingsCommand::setResponseHandler(IResponseHandlerPtr handler)
{
	mResponseHandler = handler;
}

IResponseHandlerPtr UpdateSettingsCommand::getResponseHandler() const
{
	return mResponseHandler;
}

void UpdateSettingsCommand::onSettingsUpdated(const OAIUser_serviceUpdateSettingsResponse &response)
{
	if (!mResponseHandler) {
		qWarning() << "Response handler is not set.";
		emit completed();
		return;
	}

	const auto json = response.asJson();
	mResponseHandler->handleSuccess(json.toUtf8());
	QJsonDocument doc = QJsonDocument::fromJson(json.toUtf8());
	if (!doc.isObject() || doc.isNull()) {
		qWarning() << "Failed to parse JSON response or response is not an object.";
		emit completed();
		return;
	}

	if (doc.object().contains("settings") && doc.object()["settings"].isObject()) {
		mSettings = doc.object()["settings"].toObject();
	} else {
		qWarning() << "Response JSON does not contain 'settings' object";
	}

	emit completed();
}

void UpdateSettingsCommand::onSettingsError(
    const OAIUser_serviceUpdateSettingsResponse &response,
    QNetworkReply::NetworkError errorType,
    const QString &errorStr)
{
	if (!mResponseHandler) {
		qWarning() << "Response handler is not set.";
		emit completed();
		return;
	}

	QString errorMessage = errorStr;
	if (errorMessage.isEmpty()) {
		errorMessage = response.asJson();
	}

	mResponseHandler->handleError(errorType, errorMessage.toUtf8());
	emit completed();
}

QJsonObject UpdateSettingsCommand::getSettings() const
{
	return mSettings;
}
