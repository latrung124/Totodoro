/**
 * @file ApiGatewayService.h
 * @author trung.la
 * @date 09-20-2025
 * @brief This file contains the declaration of the ApiGatewayService class.
 */

#ifndef API_GATEWAY_SERVICE_H
#define API_GATEWAY_SERVICE_H

#include <memory>
#include <vector>

#include <ApiGatewayServiceUtils.h>
#include <IApiGatewayService.h>

namespace gateway {
class Gateway;
} // namespace gateway

class APIGATEWAY_SERVICE_API ApiGatewayService : public IApiGatewayService
{
public:
	using Information = apigateway_service::utils::user::Information;
	using Settings = apigateway_service::utils::user::Settings;
	using Task = apigateway_service::utils::task_management::Task;
	using TaskGroup = apigateway_service::utils::task_management::TaskGroup;
	using Session = apigateway_service::utils::pomodoro::Session;
	using GatewayUPtr = std::unique_ptr<gateway::Gateway>;

	ApiGatewayService();
	~ApiGatewayService() override;

	ApiGatewayService(const ApiGatewayService &) = delete;
	ApiGatewayService &operator=(const ApiGatewayService &) = delete;

	ApiGatewayService(ApiGatewayService &&) = delete;
	ApiGatewayService &operator=(ApiGatewayService &&) = delete;

	void registerListener(const IServiceListener *listener) override;
	void unregisterListener(const IServiceListener *listener) override;

	void start() override;
	void stop() override;

	void requestCreateUser(const Information &userInformation) override;
	void requestGetUserInformation(const std::string &email) override;
	void requestGetUserSettings(const std::string &userId) override;
	void requestUpdateUserInformation(const Information &info) override;
	void requestUpdateUserSettings(const Settings &settings) override;

	void onResponseCreateUser(const Information &userInformation);
	void onResponseGetUserInformation(const Information &userInformation);
	void onResponseGetUserSettings(const Settings &settings);
	void onResponseUpdateUserInformation(const Information &userInformation);
	void onResponseUpdateUserSettings(const Settings &settings);

	void requestCreateTask(const Task &task) override;
	void requestUpdateTask(const Task &task) override;
	void requestDeleteTask(const std::string &taskId) override;
	void requestGetTasks(const std::string &userId, const std::string &groupId) override;

	void onResponseCreateTask(const Task &task);
	void onResponseUpdateTask(const Task &task);
	void onResponseDeleteTask(const std::string &taskId);
	void onResponseGetTasks(const std::vector<Task> &tasks);

	void requestCreateTaskGroup(const TaskGroup &taskGroup) override;
	void requestUpdateTaskGroup(const TaskGroup &taskGroup) override;
	void requestDeleteTaskGroup(const std::string &groupId) override;
	void requestGetTaskGroups(const std::string &userId) override;

	void onResponseCreateTaskGroup(const TaskGroup &taskGroup);
	void onResponseUpdateTaskGroup(const TaskGroup &taskGroup);
	void onResponseDeleteTaskGroup(const std::string &groupId);
	void onResponseGetTaskGroups(const std::vector<TaskGroup> &taskGroups);

	void requestCreateSession(const Session &session) override;
	void requestUpdateSession(const Session &session) override;
	void requestDeleteSession(const std::string &sessionId) override;
	void requestGetSessions(const std::string &userId, const std::string &taskId) override;

	void onResponseCreateSession(const Session &session);
	void onResponseUpdateSession(const Session &session);
	void onResponseDeleteSession(const std::string &sessionId);
	void onResponseGetSessions(const std::vector<Session> &sessions);

private:
	std::vector<IServiceListener *> m_listeners; // TODO: change to map for faster access the listener
	GatewayUPtr m_gateway;
};

#endif // API_GATEWAY_SERVICE_H
