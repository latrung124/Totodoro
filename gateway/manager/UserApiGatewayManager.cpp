/**
 * @file UserApiGatewayManager.cpp
 * @author trung.la
 * @date 09-22-2025
 * @brief This file contains the implementation of the UserApiGatewayManager class.
 */

#include "UserApiGatewayManager.h"

#include <QDebug>

#include "CommonDefine.h"
#include "UserProperties.h"
#include "ApiResponse.h"
#include "ApiCommandFactory.h"
#include "JsonResponseHandler.h"
#include "CreateUserCommand.h"
#include "GetUserCommand.h"
#include "UpdateUserCommand.h"
#include "GetSettingsCommand.h"
#include "UpdateSettingsCommand.h"

UserApiGatewayManager::UserApiGatewayManager(QObject* parent)
    : IApiGatewayManager(parent), m_responseHandler(std::make_shared<JsonResponseHandler>())
{
}

bool UserApiGatewayManager::registerResponseCallback(gateway::RequestType requestType, const ResponseCallback& callback)
{
    if (m_responseCallbacks.find(requestType) != m_responseCallbacks.end())
    {
        qDebug() << "Callback for request type" << static_cast<int>(requestType) << "is already registered.";
        return false; // Callback for this request type already registered
    }

    m_responseCallbacks[requestType] = callback;
    return true;
}

bool UserApiGatewayManager::unregisterResponseCallback(gateway::RequestType requestType)
{
    auto it = m_responseCallbacks.find(requestType);
    if (it == m_responseCallbacks.end())
    {
        qDebug() << "No callback found for request type" << static_cast<int>(requestType) << "to unregister.";
        return false; // No callback found for this request type
    }

    m_responseCallbacks.erase(it);
    return true;
}

bool UserApiGatewayManager::createUser(const gateway::UserProperties& userProps)
{
    qDebug() << "Creating user with username:" << QString::fromStdString(userProps.userName);
    QString createUserBodyQStr = QString::fromStdString(userProps.toCreateUserBodyJsonString());
    ApiCommandFactory& factory = ApiCommandFactory::instance();
    auto command = factory.createTyped<CreateUserCommand>(
        OpenAPI::OAIUser_serviceCreateUserRequest(createUserBodyQStr),
        gateway::kBaseUrl.data(),
        nullptr // Set parent to this manager for QObject hierarchy
    );

    if (!command)
    {
        qDebug() << "Failed to create CreateUserCommand.";
        return false;
    }

    command->setResponseHandler(m_responseHandler);
    command->execute();

    return true;
}

bool UserApiGatewayManager::getUserProperties(const std::string& userId)
{
    qDebug() << "Retrieving properties for user ID:" << QString::fromStdString(userId);
    ApiCommandFactory& factory = ApiCommandFactory::instance();
    auto command = factory.createTyped<GetUserCommand>(
        QString::fromStdString(userId),
        gateway::kBaseUrl.data(),
        nullptr // Set parent to this manager for QObject hierarchy
    );

    if (!command)
    {
        qDebug() << "Failed to create GetUserCommand.";
        return false;
    }

    command->setResponseHandler(m_responseHandler);
    command->execute();

    return true;
}

bool UserApiGatewayManager::updateUserProperties(const gateway::UserProperties& userProps)
{
    qDebug() << "Updating properties for user ID:" << QString::fromStdString(userProps.userId);
    ApiCommandFactory& factory = ApiCommandFactory::instance();
    QString updateUserBodyQStr = QString::fromStdString(userProps.toUpdateUserBodyJsonString());
    auto command = factory.createTyped<UpdateUserCommand>(
        OpenAPI::OAIUserServiceUpdateUserBody(updateUserBodyQStr),
        QString::fromStdString(userProps.userId),
        gateway::kBaseUrl.data(),
        nullptr // Set parent to this manager for QObject hierarchy
    );

    if (!command)
    {
        qDebug() << "Failed to create UpdateUserCommand.";
        return false;
    }

    command->setResponseHandler(m_responseHandler);
    command->execute();

    return true;
}

bool UserApiGatewayManager::getUserSettings(const std::string& userId)
{
    qDebug() << "Retrieving settings for user ID:" << QString::fromStdString(userId);
    ApiCommandFactory& factory = ApiCommandFactory::instance();
    auto command = factory.createTyped<GetSettingsCommand>(
        QString::fromStdString(userId),
        gateway::kBaseUrl.data(),
        nullptr // Set parent to this manager for QObject hierarchy
    );

    if (!command)
    {
        qDebug() << "Failed to create GetSettingsCommand.";
        return false;
    }

    command->setResponseHandler(m_responseHandler);
    command->execute();

    return true;
}

bool UserApiGatewayManager::updateUserSettings(const gateway::UserSettings& userSettings)
{
    qDebug() << "Updating settings for user ID:" << QString::fromStdString(userSettings.userId);
    ApiCommandFactory& factory = ApiCommandFactory::instance();
    auto command = factory.createTyped<UpdateSettingsCommand>(
        OpenAPI::OAIUserServiceUpdateSettingsBody(QString::fromStdString(userSettings.toJsonString())),
        QString::fromStdString(userSettings.userId),
        gateway::kBaseUrl.data(),
        nullptr // Set parent to this manager for QObject hierarchy
    );

    if (!command)
    {
        qDebug() << "Failed to create UpdateSettingsCommand.";
        return false;
    }

    command->setResponseHandler(m_responseHandler);
    command->execute();

    return true;
}
