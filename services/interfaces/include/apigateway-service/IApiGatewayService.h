/**
 * @file IApiGatewayService.h
 * @author trung.la
 * @date 09-20-2025
 * @brief This file contains the declaration of the IApiGatewayService interface.
 */

#ifndef IAPI_GATEWAY_SERVICE_H
#define IAPI_GATEWAY_SERVICE_H

#include "../IService.h"
#include <ApiGatewayServiceExport.h>
#include <ApiGatewayServiceUtils.h>

class APIGATEWAY_SERVICE_API IApiGatewayService : public IService
{
public:
	virtual ~IApiGatewayService() = default;

	virtual void requestCreateUser(
	    const apigateway_service::utils::user::Information &userInformation) = 0;
	virtual void requestGetUserInformation(const std::string &email) = 0;
	virtual void requestGetUserSettings(const std::string &userId) = 0;
	virtual void requestUpdateUserInformation(
	    const apigateway_service::utils::user::Information &info) = 0;
	virtual void requestUpdateUserSettings(
	    const apigateway_service::utils::user::Settings &settings) = 0;

	virtual void requestCreateTask(const apigateway_service::utils::task_management::Task &task) = 0;
	virtual void requestUpdateTask(const apigateway_service::utils::task_management::Task &task) = 0;
	virtual void requestDeleteTask(const std::string &taskId) = 0;
	virtual void requestGetTasks(const std::string &userId, const std::string &groupId) = 0;

	virtual void requestCreateTaskGroup(
	    const apigateway_service::utils::task_management::TaskGroup &group) = 0;
	virtual void requestUpdateTaskGroup(
	    const apigateway_service::utils::task_management::TaskGroup &group) = 0;
	virtual void requestDeleteTaskGroup(const std::string &groupId) = 0;
	virtual void requestGetTaskGroups(const std::string &userId) = 0;

	virtual void requestCreateSession(
	    const apigateway_service::utils::pomodoro::Session &session) = 0;

	virtual void requestUpdateSession(
	    const apigateway_service::utils::pomodoro::Session &session) = 0;
	virtual void requestDeleteSession(const std::string &sessionId) = 0;
	virtual void requestGetSessions(const std::string &userId, const std::string &taskId) = 0;
};

#endif // IAPI_GATEWAY_SERVICE_H
