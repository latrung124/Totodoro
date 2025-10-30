/**
 * @file ApiGatewayServiceListener.h
 * @author trung.la
 * @date 10-27-2025
 * @brief This file contains the declaration of the ApiGatewayServiceListener class.
 */

#ifndef API_GATEWAY_SERVICE_LISTENER_H
#define API_GATEWAY_SERVICE_LISTENER_H

#include <IApiGatewayServiceListener.h>

class ApiGatewayServiceListener : public IApiGatewayServiceListener
{
public:
	ApiGatewayServiceListener() = default;
	virtual ~ApiGatewayServiceListener() = default;

	void onUserInformationChanged(const apigateway_service::utils::user::Information &info) override;
	void onUserSettingsChanged(const apigateway_service::utils::user::Settings &settings) override;

	void onTaskCreated(const apigateway_service::utils::task_management::Task &task) override;
	void onTaskUpdated(const apigateway_service::utils::task_management::Task &task) override;
	void onTaskDeleted(const std::string &taskId) override;
	void onTasksRetrieved(
	    const std::vector<apigateway_service::utils::task_management::Task> &tasks) override;

	void onTaskGroupCreated(
	    const apigateway_service::utils::task_management::TaskGroup &taskGroup) override;
	void onTaskGroupUpdated(
	    const apigateway_service::utils::task_management::TaskGroup &taskGroup) override;
	void onTaskGroupDeleted(const std::string &groupId) override;
	void onTaskGroupsRetrieved(
	    const std::vector<apigateway_service::utils::task_management::TaskGroup> &taskGroups)
	    override;

	void onSessionChanged(const apigateway_service::utils::pomodoro::Session &session) override;
};

#endif // API_GATEWAY_SERVICE_LISTENER_H
