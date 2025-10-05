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

#include "ApiCommandFactory.h"
#include "CreateTaskCommand.h"
#include "GetTasksCommand.h"
#include "UpdateTaskCommand.h"
#include "DeleteTaskCommand.h"
#include "CreateTaskGroupCommand.h"
#include "GetTaskGroupsCommand.h"
#include "UpdateTaskGroupCommand.h"
#include "DeleteTaskGroupCommand.h"

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
    qDebug() << "Creating task:" << QString::fromStdString(taskProperties.name);
    QString createTaskBodyQStr = QString::fromStdString(taskProperties.toCreateTaskBodyJsonString());
    ApiCommandFactory& factory = ApiCommandFactory::instance();
    auto command = factory.createTyped<CreateTaskCommand>(
        QString::fromStdString(taskProperties.groupId),
        OpenAPI::OAITaskManagementServiceCreateTaskBody(createTaskBodyQStr),
        gateway::kBaseUrl.data(),
        nullptr // Set parent to this manager for QObject hierarchy
    );

    if (!command)
    {
        qDebug() << "Failed to create CreateTaskCommand.";
        return false;
    }

    //TODO: Set up response handler and connect signals/slots as needed
    // And handle the result appropriately
    return true;
}

bool TaskManagementApiGatewayManager::getTasks(const std::string& groupId, const std::string& userId)
{
    qDebug() << "Retrieving tasks for group ID:" << QString::fromStdString(groupId);
    ApiCommandFactory& factory = ApiCommandFactory::instance();
    auto command = factory.createTyped<GetTasksCommand>(
        QString::fromStdString(groupId),
        QString::fromStdString(userId),
        gateway::kBaseUrl.data(),
        nullptr // Set parent to this manager for QObject hierarchy
    );

    if (!command)
    {
        qDebug() << "Failed to create GetTasksCommand.";
        return false;
    }

    //TODO: Set up response handler and connect signals/slots as needed
    // And handle the result appropriately
    return true;
}

bool TaskManagementApiGatewayManager::updateTask(const gateway::TaskProperties& taskProperties)
{
    qDebug() << "Updating task ID:" << QString::fromStdString(taskProperties.taskId)
            << "with name:" << QString::fromStdString(taskProperties.name);
    QString updateTaskBodyQStr = QString::fromStdString(taskProperties.toUpdateTaskBodyJsonString());
    ApiCommandFactory& factory = ApiCommandFactory::instance();
    auto command = factory.createTyped<UpdateTaskCommand>(
        OpenAPI::OAITaskManagementServiceUpdateTaskBody(updateTaskBodyQStr),
        QString::fromStdString(taskProperties.taskId),
        gateway::kBaseUrl.data(),
        nullptr // Set parent to this manager for QObject hierarchy
    );

    if (!command)
    {
        qDebug() << "Failed to create UpdateTaskCommand.";
        return false;
    }

    //TODO: Set up response handler and connect signals/slots as needed
    // And handle the result appropriately
    return true;
}

bool TaskManagementApiGatewayManager::deleteTask(const std::string& taskId)
{
    qDebug() << "Deleting task ID:" << QString::fromStdString(taskId);
    ApiCommandFactory& factory = ApiCommandFactory::instance();
    auto command = factory.createTyped<DeleteTaskCommand>(
        QString::fromStdString(taskId),
        gateway::kBaseUrl.data(),
        nullptr // Set parent to this manager for QObject hierarchy
    );

    if (!command)
    {
        qDebug() << "Failed to create DeleteTaskCommand.";
        return false;
    }

    //TODO: Set up response handler and connect signals/slots as needed
    // And handle the result appropriately
    return true;
}

bool TaskManagementApiGatewayManager::createTaskGroup(const gateway::TaskGroupProperties& groupProperties)
{
    qDebug() << "Creating task group:" << QString::fromStdString(groupProperties.name);
    QString createGroupBodyQStr = QString::fromStdString(groupProperties.toCreateTaskGroupBodyJsonString());
    ApiCommandFactory& factory = ApiCommandFactory::instance();
    auto command = factory.createTyped<CreateTaskGroupCommand>(
        OpenAPI::OAITask_managementCreateTaskGroupRequest(createGroupBodyQStr),
        gateway::kBaseUrl.data(),
        nullptr // Set parent to this manager for QObject hierarchy
    );

    if (!command)
    {
        qDebug() << "Failed to create CreateTaskGroupCommand.";
        return false;
    }

    //TODO: Set up response handler and connect signals/slots as needed
    // And handle the result appropriately
    return true;
}

bool TaskManagementApiGatewayManager::getTaskGroups(const std::string& userId)
{
    qDebug() << "Retrieving task groups for user ID:" << QString::fromStdString(userId);
    ApiCommandFactory& factory = ApiCommandFactory::instance();
    auto command = factory.createTyped<GetTaskGroupsCommand>(
        QString::fromStdString(userId),
        gateway::kBaseUrl.data(),
        nullptr // Set parent to this manager for QObject hierarchy
    );

    if (!command)
    {
        qDebug() << "Failed to create GetTaskGroupsCommand.";
        return false;
    }

    //TODO: Set up response handler and connect signals/slots as needed
    // And handle the result appropriately
    return true;
}

bool TaskManagementApiGatewayManager::updateTaskGroup(const gateway::TaskGroupProperties& groupProperties)
{
    qDebug() << "Updating task group ID:" << QString::fromStdString(groupProperties.groupId);
    QString updateGroupBodyQStr = QString::fromStdString(groupProperties.toUpdateTaskGroupBodyJsonString());
    ApiCommandFactory& factory = ApiCommandFactory::instance();
    auto command = factory.createTyped<UpdateTaskGroupCommand>(
        OpenAPI::OAITaskManagementServiceUpdateTaskGroupBody(updateGroupBodyQStr),
        QString::fromStdString(groupProperties.groupId),
        gateway::kBaseUrl.data(),
        nullptr // Set parent to this manager for QObject hierarchy
    );

    if (!command)
    {
        qDebug() << "Failed to create UpdateTaskGroupCommand.";
        return false;
    }

    //TODO: Set up response handler and connect signals/slots as needed
    // And handle the result appropriately
    return true;
}

bool TaskManagementApiGatewayManager::deleteTaskGroup(const std::string& groupId)
{
    qDebug() << "Deleting task group ID:" << QString::fromStdString(groupId);
    ApiCommandFactory& factory = ApiCommandFactory::instance();
    auto command = factory.createTyped<DeleteTaskGroupCommand>(
        QString::fromStdString(groupId),
        gateway::kBaseUrl.data(),
        nullptr // Set parent to this manager for QObject hierarchy
    );

    if (!command)
    {
        qDebug() << "Failed to create DeleteTaskGroupCommand.";
        return false;
    }

    //TODO: Set up response handler and connect signals/slots as needed
    // And handle the result appropriately
    return true;
}
