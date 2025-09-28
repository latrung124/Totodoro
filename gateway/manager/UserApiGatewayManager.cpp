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
    // Implementation for creating a user
    // This is a placeholder implementation
    return true;
}

bool UserApiGatewayManager::getUserProperties(const std::string& userId)
{
    // Implementation for retrieving user properties
    // This is a placeholder implementation
    qDebug() << "Retrieving properties for user ID:" << QString::fromStdString(userId);
    return true;
}

bool UserApiGatewayManager::updateUserProperties(const gateway::UserProperties& userProps)
{
    // Implementation for updating user properties
    // This is a placeholder implementation
    qDebug() << "Updating properties for user ID:" << QString::fromStdString(userProps.userId);
    return true;
}

bool UserApiGatewayManager::getUserSettings(const std::string& userId)
{
    // Implementation for retrieving user settings
    // This is a placeholder implementation
    qDebug() << "Retrieving settings for user ID:" << QString::fromStdString(userId);
    return true;
}

bool UserApiGatewayManager::updateUserSettings(const gateway::UserSettings& userSettings)
{
    // Implementation for updating user settings
    // This is a placeholder implementation
    qDebug() << "Updating settings for user ID:" << QString::fromStdString(userSettings.userId);
    return true;
}
