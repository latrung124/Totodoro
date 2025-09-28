/**
 * @file TaskManagementApiGatewayManager.cpp
 * @author trung.la
 * @date 09-23-2025
 * @brief This file contains the implementation of the TaskManagementApiGatewayManager class.
 */

#include "TaskManagementApiGatewayManager.h"

#include <QDebug>

#include "CommonDefine.h"
#include "TaskProperties.h"
#include "ApiResponse.h"

bool TaskManagementApiGatewayManager::registerResponseCallback(gateway::RequestType requestType, const ResponseCallback& callback)
{
    if (m_responseCallbacks.find(requestType) != m_responseCallbacks.end())
    {
        qDebug() << "Callback for request type" << static_cast<int>(requestType) << "is already registered.";
        return false; // Callback for this request type already registered
    }

    m_responseCallbacks[requestType] = callback;
    return true;
}

bool TaskManagementApiGatewayManager::unregisterResponseCallback(gateway::RequestType requestType)
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

bool TaskManagementApiGatewayManager::createTask(const gateway::TaskProperties& taskProperties)
{
    // Implementation for creating a task
    // This is a placeholder implementation
    return true;
}

bool TaskManagementApiGatewayManager::getTasks(const std::string& groupId)
{
    // Implementation for retrieving tasks for a group
    // This is a placeholder implementation
    qDebug() << "Retrieving tasks for group ID:" << QString::fromStdString(groupId);
    return true;
}

bool TaskManagementApiGatewayManager::updateTask(const gateway::TaskProperties& taskProperties)
{
    // Implementation for updating a task
    // This is a placeholder implementation
    qDebug() << "Updating task ID:" << QString::fromStdString(taskProperties.taskId);
    return true;
}

bool TaskManagementApiGatewayManager::deleteTask(const std::string& taskId)
{
    // Implementation for deleting a task
    // This is a placeholder implementation
    qDebug() << "Deleting task ID:" << QString::fromStdString(taskId);
    return true;
}

bool TaskManagementApiGatewayManager::createTaskGroup(const gateway::TaskGroupProperties& groupProperties)
{
    // Implementation for creating a task group
    // This is a placeholder implementation
    qDebug() << "Creating task group:" << QString::fromStdString(groupProperties.name);
    return true;
}

bool TaskManagementApiGatewayManager::getTaskGroups(const std::string& userId)
{
    // Implementation for retrieving task groups for a user
    // This is a placeholder implementation
    qDebug() << "Retrieving task groups for user ID:" << QString::fromStdString(userId);
    return true;
}

bool TaskManagementApiGatewayManager::updateTaskGroup(const gateway::TaskGroupProperties& groupProperties)
{
    // Implementation for updating a task group
    // This is a placeholder implementation
    qDebug() << "Updating task group ID:" << QString::fromStdString(groupProperties.groupId);
    return true;
}

bool TaskManagementApiGatewayManager::deleteTaskGroup(const std::string& groupId)
{
    // Implementation for deleting a task group
    // This is a placeholder implementation
    qDebug() << "Deleting task group ID:" << QString::fromStdString(groupId);
    return true;
}
