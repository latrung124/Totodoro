/**
 * @file ApiGatewayServiceListener.h
 * @author trung.la
 * @date 10-27-2025
 * @brief This file contains the implementation of the ApiGatewayServiceListener class.
 */

#include "ApiGatewayServiceListener.h"

void ApiGatewayServiceListener::onUserInformationChanged(
    const apigateway_service::utils::user::Information &info)
{
	// Implementation goes here
}

void ApiGatewayServiceListener::onUserSettingsChanged(
    const apigateway_service::utils::user::Settings &settings)
{
	// Implementation goes here
}

void ApiGatewayServiceListener::onTaskCreated(
    const apigateway_service::utils::task_management::Task &task)
{
	// Implementation goes here
}

void ApiGatewayServiceListener::onTaskUpdated(
    const apigateway_service::utils::task_management::Task &task)
{
	// Implementation goes here
}

void ApiGatewayServiceListener::onTaskDeleted(const std::string &taskId)
{
	// Implementation goes here
}

void ApiGatewayServiceListener::onTasksRetrieved(
    const std::vector<apigateway_service::utils::task_management::Task> &tasks)
{
	// Implementation goes here
}

void ApiGatewayServiceListener::onTaskGroupCreated(
    const apigateway_service::utils::task_management::TaskGroup &taskGroup)
{
	// Implementation goes here
}

void ApiGatewayServiceListener::onTaskGroupUpdated(
    const apigateway_service::utils::task_management::TaskGroup &taskGroup)
{
	// Implementation goes here
}

void ApiGatewayServiceListener::onTaskGroupDeleted(const std::string &groupId)
{
	// Implementation goes here
}

void ApiGatewayServiceListener::onTaskGroupsRetrieved(
    const std::vector<apigateway_service::utils::task_management::TaskGroup> &taskGroups)
{
	// Implementation goes here
}
