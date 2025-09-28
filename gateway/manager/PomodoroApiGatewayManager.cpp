/**
 * @file PomodoroApiGatewayManager.cpp
 * @author trung.la
 * @date 09-24-2025
 * @brief This file contains the implementation of the PomodoroApiGatewayManager class.
 */

#include "PomodoroApiGatewayManager.h"

#include <QDebug>

#include "CommonDefine.h"
#include "PomodoroProperties.h"
#include "ApiResponse.h"

bool PomodoroApiGatewayManager::registerResponseCallback(gateway::RequestType requestType, const ResponseCallback& callback)
{
    if (m_responseCallbacks.find(requestType) != m_responseCallbacks.end())
    {
        qDebug() << "Callback for request type" << static_cast<int>(requestType) << "is already registered.";
        return false; // Callback for this request type already registered
    }

    m_responseCallbacks[requestType] = callback;
    return true;
}

bool PomodoroApiGatewayManager::unregisterResponseCallback(gateway::RequestType requestType)
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

bool PomodoroApiGatewayManager::createPomodoroSession(const gateway::PomodoroSessionProperties& sessionProps)
{
    // Implementation for creating a Pomodoro session
    // This is a placeholder implementation
    qDebug() << "Creating Pomodoro session for user:" << QString::fromStdString(sessionProps.userId);
    return true;
}

bool PomodoroApiGatewayManager::getPomodoroSessions(const std::string& userId)
{
    // Implementation for retrieving Pomodoro sessions for a user
    // This is a placeholder implementation
    qDebug() << "Retrieving Pomodoro sessions for user:" << QString::fromStdString(userId);
    return true;
}

bool PomodoroApiGatewayManager::updatePomodoroSession(const gateway::PomodoroSessionProperties& sessionProps)
{
    // Implementation for updating a Pomodoro session
    // This is a placeholder implementation
    qDebug() << "Updating Pomodoro session:" << QString::fromStdString(sessionProps.sessionId);
    return true;
}

bool PomodoroApiGatewayManager::deletePomodoroSession(const std::string& sessionId)
{
    // Implementation for deleting a Pomodoro session
    // This is a placeholder implementation
    qDebug() << "Deleting Pomodoro session:" << QString::fromStdString(sessionId);
    return true;
}
