/**
 * @file ApiGatewayServiceListener.h
 * @author trung.la
 * @date 10-27-2025
 * @brief This file contains the implementation of the ApiGatewayServiceListener class.
 */

#include "ApiGatewayServiceListener.h"

#include "core/services/producer/apigateway-service/TaskDeletedMessageCreator.h"
#include "core/services/producer/apigateway-service/TaskMessageCreator.h"
#include "core/services/producer/apigateway-service/TasksRetrievedMessageCreator.h"
#include "core/services/producer/apigateway-service/UserInformationMessageCreator.h"
#include "core/services/producer/apigateway-service/UserSettingsMessageCreator.h"
#include "core/services/producer/ServiceMessageProducer.h"
#include "core/services/queue/MessageQueue.h"

void ApiGatewayServiceListener::onUserInformationChanged(
    const apigateway_service::utils::user::Information &info)
{
	auto message = ServiceMessageProducer::getInstance().produce<UserInformationMessageCreator>(
	    info);
	if (message) {
		MessageQueue::getInstance().push(std::move(message));
	}
}

void ApiGatewayServiceListener::onUserSettingsChanged(
    const apigateway_service::utils::user::Settings &settings)
{
	auto message = ServiceMessageProducer::getInstance().produce<UserSettingsMessageCreator>(
	    settings);
	if (message) {
		MessageQueue::getInstance().push(std::move(message));
	}
}

void ApiGatewayServiceListener::onTaskCreated(
    const apigateway_service::utils::task_management::Task &task)
{
	auto message = ServiceMessageProducer::getInstance().produce<TaskMessageCreator>(task);
	if (message) {
		MessageQueue::getInstance().push(std::move(message));
	}
}

void ApiGatewayServiceListener::onTaskUpdated(
    const apigateway_service::utils::task_management::Task &task)
{
	auto message = ServiceMessageProducer::getInstance().produce<TaskMessageCreator>(task);
	if (message) {
		MessageQueue::getInstance().push(std::move(message));
	}
}

void ApiGatewayServiceListener::onTaskDeleted(const std::string &taskId)
{
	auto message = ServiceMessageProducer::getInstance().produce<TaskDeletedMessageCreator>(taskId);
	if (message) {
		MessageQueue::getInstance().push(std::move(message));
	}
}

void ApiGatewayServiceListener::onTasksRetrieved(
    const std::vector<apigateway_service::utils::task_management::Task> &tasks)
{
	auto message = ServiceMessageProducer::getInstance().produce<TasksRetrievedMessageCreator>(
	    tasks);
	if (message) {
		MessageQueue::getInstance().push(std::move(message));
	}
}

void ApiGatewayServiceListener::onTaskGroupCreated(
    const apigateway_service::utils::task_management::TaskGroup &taskGroup)
{
	auto message = ServiceMessageProducer::getInstance().produce<TaskMessageCreator>(taskGroup);
	if (message) {
		MessageQueue::getInstance().push(std::move(message));
	}
}

void ApiGatewayServiceListener::onTaskGroupUpdated(
    const apigateway_service::utils::task_management::TaskGroup &taskGroup)
{
	auto message = ServiceMessageProducer::getInstance().produce<TaskMessageCreator>(taskGroup);
	if (message) {
		MessageQueue::getInstance().push(std::move(message));
	}
}

void ApiGatewayServiceListener::onTaskGroupDeleted(const std::string &groupId)
{
	auto message = ServiceMessageProducer::getInstance().produce<TaskDeletedMessageCreator>(groupId);
	if (message) {
		MessageQueue::getInstance().push(std::move(message));
	}
}

void ApiGatewayServiceListener::onTaskGroupsRetrieved(
    const std::vector<apigateway_service::utils::task_management::TaskGroup> &taskGroups)
{
	// Implementation goes here
}

void ApiGatewayServiceListener::onSessionChanged(
    const apigateway_service::utils::pomodoro::Session &session)
{
	// Implementation goes here
}
