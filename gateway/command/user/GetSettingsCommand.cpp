/**
 * @file GetSettingsCommand.cpp
 * @author trung.la
 * @date 09-18-2025
 * @brief Implementation of GetSettingsCommand class that handles fetching user settings via the OpenAPI client
 */

#include "GetSettingsCommand.h"

#include "ApiClientFactory.h"

GetSettingsCommand::GetSettingsCommand(
    const QString& userId,
    const QString& baseUrl,
    QObject* parent)
    : IApiCommand(parent),
      mUserId(userId),
      mBaseUrl(baseUrl),
      mResponseHandler(nullptr),
      mApiClient(nullptr)
{
}

void GetSettingsCommand::execute()
{
    if (mApiClient) {
        qWarning() << "API client is already created.";
        return; // Already executing
    }
    
    // Create as QObject then cast to the concrete API type and transfer ownership
    auto objClient = ApiClientFactory::createClient(gateway::RouteType::User, mBaseUrl);
    auto raw = qobject_cast<OpenAPI::OAIUserServiceApi*>(objClient.get());
    if (!raw) {
        qWarning() << "Failed to create Pomodoro API client (type mismatch).";
        return;
    }
    mApiClient.reset(raw);
    objClient.release(); // ownership moved to mApiClient

    connect(mApiClient.get(), &OpenAPI::OAIUserServiceApi::userServiceGetSettingsSignal,
            this, &GetSettingsCommand::onSettingsRetrieved);
    connect(mApiClient.get(), &OpenAPI::OAIUserServiceApi::userServiceGetSettingsSignalError,
            this, &GetSettingsCommand::onSettingsError);

    mApiClient->userServiceGetSettings(mUserId);
}

void GetSettingsCommand::setResponseHandler(IResponseHandlerPtr handler)
{
    mResponseHandler = handler;
}

IResponseHandlerPtr GetSettingsCommand::getResponseHandler() const
{
    return mResponseHandler;
}

void GetSettingsCommand::onSettingsRetrieved(const OAIUser_serviceGetSettingsResponse& response)
{
    if (!mResponseHandler) {
        qWarning() << "Response handler is not set.";
        emit completed();
        return;
    }

    auto const json = response.asJson();
    mResponseHandler->handleSuccess(json.toUtf8());
    QJsonDocument doc = QJsonDocument::fromJson(json.toUtf8());
    if (!doc.isObject() || doc.isNull()) {
        qWarning() << "Failed to parse response JSON or it is not an object";
        emit completed();
        return;
    }

    QJsonObject obj = doc.object();
    if (obj.contains("settings") && obj["settings"].isObject()) {
        mSettings = obj["settings"].toObject();
    } else {
        qWarning() << "Response JSON does not contain 'user' object";
    }
    
    emit completed();
}

void GetSettingsCommand::onSettingsError(const OAIUser_serviceGetSettingsResponse& response,
                                          QNetworkReply::NetworkError errorType, const QString& errorStr)
{
    if (!mResponseHandler) {
        qWarning() << "Response handler is not set.";
        emit completed();
        return;
    }

    auto errorMessage = errorStr;
    if (errorMessage.isEmpty()) {
        auto const json = response.asJson();
        if (!json.isEmpty()) {
            errorMessage = json;
        } else {
            errorMessage = "Unknown error occurred";
        }
    }

    mResponseHandler->handleError(errorType, errorMessage.toUtf8());
    emit completed();
}

QJsonObject GetSettingsCommand::getSettings() const
{
    return mSettings;
}
