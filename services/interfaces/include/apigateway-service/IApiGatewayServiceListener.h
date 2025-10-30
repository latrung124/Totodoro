/**
 * @file IApiGatewayServiceListener.h
 * @author trung.la
 * @date 09-20-2025
 * @brief Interface for API Gateway service listener
 */

#ifndef IAPI_GATEWAY_SERVICE_LISTENER_H
#define IAPI_GATEWAY_SERVICE_LISTENER_H

#include "../IServiceListener.h"
#include <ApiGatewayServiceUtils.h>

class IApiGatewayServiceListener : public IServiceListener
{
public:
	IApiGatewayServiceListener() = default;
	virtual ~IApiGatewayServiceListener() = default;

	virtual void onUserInformationChanged(
	    const apigateway_service::utils::user::Information &info) = 0;
	virtual void onUserSettingsChanged(
	    const apigateway_service::utils::user::Settings &settings) = 0;

	virtual void onTaskCreated(const apigateway_service::utils::task_management::Task &task) = 0;
	virtual void onTaskUpdated(const apigateway_service::utils::task_management::Task &task) = 0;
	virtual void onTaskDeleted(const std::string &taskId) = 0;
	virtual void onTasksRetrieved(
	    const std::vector<apigateway_service::utils::task_management::Task> &tasks) = 0;

	virtual void onTaskGroupCreated(
	    const apigateway_service::utils::task_management::TaskGroup &taskGroup) = 0;
	virtual void onTaskGroupUpdated(
	    const apigateway_service::utils::task_management::TaskGroup &taskGroup) = 0;
	virtual void onTaskGroupDeleted(const std::string &groupId) = 0;
	virtual void onTaskGroupsRetrieved(
	    const std::vector<apigateway_service::utils::task_management::TaskGroup> &taskGroups) = 0;

	virtual void onSessionChanged(const apigateway_service::utils::pomodoro::Session &session) = 0;
};

#endif // IAPI_GATEWAY_SERVICE_LISTENER_H
