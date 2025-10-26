/**
 * @file ApiGatewayService.cpp
 * @author trung.la
 * @date 09-20-2025
 * @brief This file contains the implementation of the ApiGatewayService class.
 */

#include "ApiGatewayService.h"
#include "IApiGatewayServiceListener.h"

#include "Gateway.h"

#include "common/PomodoroProperties.h"
#include "common/Properties.h"
#include "common/TaskProperties.h"
#include "common/UserProperties.h"
#include "manager/TaskManagementApiGatewayManager.h"
#include "manager/UserApiGatewayManager.h"

namespace {
using Information = apigateway_service::utils::user::Information;
using Settings = apigateway_service::utils::user::Settings;
using Task = apigateway_service::utils::task_management::Task;
using TaskGroup = apigateway_service::utils::task_management::TaskGroup;
} // namespace

ApiGatewayService::ApiGatewayService()
    : m_gateway(std::make_unique<gateway::Gateway>())
{
}

ApiGatewayService::~ApiGatewayService()
{
}

void ApiGatewayService::registerListener(const IServiceListener *listener)
{
	if (!listener) {
		return;
	}

	for (const auto &l : m_listeners) {
		if (l == listener) {
			return;
		}
	}

	m_listeners.push_back(const_cast<IServiceListener *>(listener));
}

void ApiGatewayService::unregisterListener(const IServiceListener *listener)
{
	if (!listener) {
		return;
	}

	for (auto it = m_listeners.begin(); it != m_listeners.end(); ++it) {
		if (*it == listener) {
			m_listeners.erase(it);
			return;
		}
	}
}

void ApiGatewayService::start()
{
	// Initialize resources, connections, etc.
}

void ApiGatewayService::stop()
{
	// Clean up resources, connections, etc.
}

void ApiGatewayService::requestCreateUser(const Information &userInformation)
{
	if (!m_gateway) {
		return;
	}

	auto managerWeakPtr = m_gateway->getApiGatewayManager(gateway::RouteType::User);
	auto managerPtr = managerWeakPtr.lock();
	if (!managerPtr) {
		return;
	}

	gateway::Properties properties;
	gateway::UserProperties userProps;
	userProps.userId = userInformation.userId;
	userProps.email = userInformation.email;
	userProps.userName = userInformation.username;
	userProps.createdTime = userInformation.createdTime;
	userProps.lastUpdatedTime = userInformation.lastUpdatedTime;
	properties.property = userProps;
	managerPtr->trigger(gateway::RequestType::CreateUser, properties);
}

void ApiGatewayService::requestGetUserInformation(const std::string &userId)
{
	if (!m_gateway) {
		return;
	}

	auto managerWeakPtr = m_gateway->getApiGatewayManager(gateway::RouteType::User);
	auto managerPtr = managerWeakPtr.lock();
	if (!managerPtr) {
		return;
	}

	gateway::Properties properties;
	gateway::UserProperties userProps;
	userProps.userId = userId;
	properties.property = userProps;
	managerPtr->trigger(gateway::RequestType::GetUserProperties, properties);
}

void ApiGatewayService::requestGetUserSettings(const std::string &userId)
{
	if (!m_gateway) {
		return;
	}

	auto managerWeakPtr = m_gateway->getApiGatewayManager(gateway::RouteType::User);
	auto managerPtr = managerWeakPtr.lock();
	if (!managerPtr) {
		return;
	}

	gateway::Properties properties;
	gateway::UserSettings userSettings;
	userSettings.userId = userId;
	properties.property = userSettings;
	managerPtr->trigger(gateway::RequestType::GetUserSettings, properties);
}

void ApiGatewayService::requestUpdateUserInformation(const Information &info)
{
	if (!m_gateway) {
		return;
	}

	auto managerWeakPtr = m_gateway->getApiGatewayManager(gateway::RouteType::User);
	auto managerPtr = managerWeakPtr.lock();
	if (!managerPtr) {
		return;
	}

	gateway::Properties properties;
	gateway::UserProperties userProps;
	userProps.userId = info.userId;
	userProps.email = info.email;
	userProps.userName = info.username;
	userProps.createdTime = info.createdTime;
	userProps.lastUpdatedTime = info.lastUpdatedTime;
	properties.property = userProps;
	managerPtr->trigger(gateway::RequestType::UpdateUserProperties, properties);
}

void ApiGatewayService::requestUpdateUserSettings(const Settings &settings)
{
	if (!m_gateway) {
		return;
	}
	auto managerWeakPtr = m_gateway->getApiGatewayManager(gateway::RouteType::User);
	auto managerPtr = managerWeakPtr.lock();
	if (!managerPtr) {
		return;
	}

	gateway::Properties properties;
	gateway::UserSettings userSettings;
	userSettings.userId = settings.userId;
	userSettings.theme = settings.theme;
	userSettings.language = settings.language;
	userSettings.pomodoroDuration = settings.pomodoroDuration;
	userSettings.shortBreakDuration = settings.shortBreakDuration;
	userSettings.longBreakDuration = settings.longBreakDuration;
	userSettings.longBreakInterval = settings.longBreakInterval;
	userSettings.autoStartShortBreak = settings.autoStartShortBreak;
	userSettings.autoStartLongBreak = settings.autoStartLongBreak;
	userSettings.autoStartPomodoro = settings.autoStartPomodoro;
	userSettings.shortBreakNotification = settings.shortBreakNotification;
	userSettings.longBreakNotification = settings.longBreakNotification;
	userSettings.pomodoroNotification = settings.pomodoroNotification;
	userSettings.autoStartMusic = settings.autoStartMusic;
	userSettings.autoStartNextTask = settings.autoStartNextTask;
	properties.property = userSettings;
	managerPtr->trigger(gateway::RequestType::UpdateUserSettings, properties);
}

void ApiGatewayService::onResponseCreateUser(const Information &userInformation)
{
	for (const auto &listener : m_listeners) {
		auto apiListener = dynamic_cast<IApiGatewayServiceListener *>(listener);
		if (apiListener) {
			apiListener->onUserInformationChanged(userInformation);
		}
	}
}

void ApiGatewayService::onResponseGetUserInformation(const Information &userInformation)
{
	for (const auto &listener : m_listeners) {
		auto apiListener = dynamic_cast<IApiGatewayServiceListener *>(listener);
		if (apiListener) {
			apiListener->onUserInformationChanged(userInformation);
		}
	}
}

void ApiGatewayService::onResponseGetUserSettings(const Settings &settings)
{
	for (const auto &listener : m_listeners) {
		auto apiListener = dynamic_cast<IApiGatewayServiceListener *>(listener);
		if (apiListener) {
			apiListener->onUserSettingsChanged(settings);
		}
	}
}

void ApiGatewayService::onResponseUpdateUserInformation(const Information &userInformation)
{
	for (const auto &listener : m_listeners) {
		auto apiListener = dynamic_cast<IApiGatewayServiceListener *>(listener);
		if (apiListener) {
			apiListener->onUserInformationChanged(userInformation);
		}
	}
}

void ApiGatewayService::onResponseUpdateUserSettings(const Settings &settings)
{
	for (const auto &listener : m_listeners) {
		auto apiListener = dynamic_cast<IApiGatewayServiceListener *>(listener);
		if (apiListener) {
			apiListener->onUserSettingsChanged(settings);
		}
	}
}

void ApiGatewayService::requestCreateTask(const Task &task)
{
	if (!m_gateway) {
		return;
	}

	auto managerWeakPtr = m_gateway->getApiGatewayManager(gateway::RouteType::TaskManagement);
	auto managerPtr = managerWeakPtr.lock();
	if (!managerPtr) {
		return;
	}

	gateway::Properties properties;
	gateway::TaskProperties taskProps;
	taskProps.taskId = task.taskId;
	taskProps.userId = task.userId;
	taskProps.groupId = task.groupId;
	taskProps.name = task.name;
	taskProps.description = task.description;
	taskProps.priority = static_cast<gateway::TaskPriority>(task.priority);
	taskProps.status = static_cast<gateway::TaskStatus>(task.status);
	taskProps.deadline = task.deadline;
	taskProps.createdTime = task.createdTime;
	taskProps.lastUpdatedTime = task.lastUpdatedTime;
	taskProps.totalPomodoros = task.totalPomodoros;
	taskProps.completedPomodoros = task.completedPomodoros;
	taskProps.progress = task.progress;
	properties.property = taskProps;
	managerPtr->trigger(gateway::RequestType::CreateTask, properties);
}

void ApiGatewayService::requestUpdateTask(const Task &task)
{
	if (!m_gateway) {
		return;
	}

	auto managerWeakPtr = m_gateway->getApiGatewayManager(gateway::RouteType::TaskManagement);
	auto managerPtr = managerWeakPtr.lock();
	if (!managerPtr) {
		return;
	}

	gateway::Properties properties;
	gateway::TaskProperties taskProps;
	taskProps.taskId = task.taskId;
	taskProps.userId = task.userId;
	taskProps.groupId = task.groupId;
	taskProps.name = task.name;
	taskProps.description = task.description;
	taskProps.priority = static_cast<gateway::TaskPriority>(task.priority);
	taskProps.status = static_cast<gateway::TaskStatus>(task.status);
	taskProps.deadline = task.deadline;
	taskProps.createdTime = task.createdTime;
	taskProps.lastUpdatedTime = task.lastUpdatedTime;
	taskProps.totalPomodoros = task.totalPomodoros;
	taskProps.completedPomodoros = task.completedPomodoros;
	taskProps.progress = task.progress;
	properties.property = taskProps;
	managerPtr->trigger(gateway::RequestType::UpdateTask, properties);
}

void ApiGatewayService::requestDeleteTask(const std::string &taskId)
{
	if (!m_gateway) {
		return;
	}

	auto managerWeakPtr = m_gateway->getApiGatewayManager(gateway::RouteType::TaskManagement);
	auto managerPtr = managerWeakPtr.lock();
	if (!managerPtr) {
		return;
	}

	gateway::Properties properties;
	gateway::TaskProperties taskProps;
	taskProps.taskId = taskId;
	properties.property = taskProps;
	managerPtr->trigger(gateway::RequestType::DeleteTask, properties);
}

void ApiGatewayService::requestGetTasks(const std::string &userId, const std::string &groupId)
{
	if (!m_gateway) {
		return;
	}

	auto managerWeakPtr = m_gateway->getApiGatewayManager(gateway::RouteType::TaskManagement);
	auto managerPtr = managerWeakPtr.lock();
	if (!managerPtr) {
		return;
	}

	gateway::Properties properties;
	gateway::TaskProperties taskProps;
	taskProps.userId = userId;
	taskProps.groupId = groupId;
	properties.property = taskProps;
	managerPtr->trigger(gateway::RequestType::GetTasks, properties);
}

void ApiGatewayService::onResponseCreateTask(const Task &task)
{
	for (const auto &listener : m_listeners) {
		auto apiListener = dynamic_cast<IApiGatewayServiceListener *>(listener);
		if (apiListener) {
			apiListener->onTaskCreated(task);
		}
	}
}

void ApiGatewayService::onResponseUpdateTask(const Task &task)
{
	for (const auto &listener : m_listeners) {
		auto apiListener = dynamic_cast<IApiGatewayServiceListener *>(listener);
		if (apiListener) {
			apiListener->onTaskUpdated(task);
		}
	}
}

void ApiGatewayService::onResponseDeleteTask(const std::string &taskId)
{
	for (const auto &listener : m_listeners) {
		auto apiListener = dynamic_cast<IApiGatewayServiceListener *>(listener);
		if (apiListener) {
			apiListener->onTaskDeleted(taskId);
		}
	}
}

void ApiGatewayService::onResponseGetTasks(const std::vector<Task> &tasks)
{
	for (const auto &listener : m_listeners) {
		auto apiListener = dynamic_cast<IApiGatewayServiceListener *>(listener);
		if (apiListener) {
			apiListener->onTasksRetrieved(tasks);
		}
	}
}

void ApiGatewayService::requestCreateTaskGroup(const TaskGroup &taskGroup)
{
	if (!m_gateway) {
		return;
	}

	auto managerWeakPtr = m_gateway->getApiGatewayManager(gateway::RouteType::TaskManagement);
	auto managerPtr = managerWeakPtr.lock();
	if (!managerPtr) {
		return;
	}

	gateway::Properties properties;
	gateway::TaskGroupProperties groupProps;
	groupProps.groupId = taskGroup.groupId;
	groupProps.userId = taskGroup.userId;
	groupProps.name = taskGroup.name;
	groupProps.icon = taskGroup.icon;
	groupProps.completedTasks = taskGroup.completedTasks;
	groupProps.totalTasks = taskGroup.totalTasks;
	groupProps.description = taskGroup.description;
	groupProps.deadline = taskGroup.deadline;
	groupProps.priority = static_cast<gateway::TaskGroupPriority>(taskGroup.priority);
	groupProps.status = static_cast<gateway::TaskGroupStatus>(taskGroup.status);
	groupProps.createdTime = taskGroup.createdTime;
	groupProps.lastUpdatedTime = taskGroup.lastUpdatedTime;
	properties.property = groupProps;
	managerPtr->trigger(gateway::RequestType::CreateTaskGroup, properties);
}

void ApiGatewayService::requestUpdateTaskGroup(const TaskGroup &taskGroup)
{
	if (!m_gateway) {
		return;
	}

	auto managerWeakPtr = m_gateway->getApiGatewayManager(gateway::RouteType::TaskManagement);
	auto managerPtr = managerWeakPtr.lock();
	if (!managerPtr) {
		return;
	}

	gateway::Properties properties;
	gateway::TaskGroupProperties groupProps;
	groupProps.groupId = taskGroup.groupId;
	groupProps.userId = taskGroup.userId;
	groupProps.name = taskGroup.name;
	groupProps.icon = taskGroup.icon;
	groupProps.completedTasks = taskGroup.completedTasks;
	groupProps.totalTasks = taskGroup.totalTasks;
	groupProps.description = taskGroup.description;
	groupProps.deadline = taskGroup.deadline;
	groupProps.priority = static_cast<gateway::TaskGroupPriority>(taskGroup.priority);
	groupProps.status = static_cast<gateway::TaskGroupStatus>(taskGroup.status);
	groupProps.createdTime = taskGroup.createdTime;
	groupProps.lastUpdatedTime = taskGroup.lastUpdatedTime;
	properties.property = groupProps;
	managerPtr->trigger(gateway::RequestType::UpdateTaskGroup, properties);
}

void ApiGatewayService::requestDeleteTaskGroup(const std::string &groupId)
{
	if (!m_gateway) {
		return;
	}

	auto managerWeakPtr = m_gateway->getApiGatewayManager(gateway::RouteType::TaskManagement);
	auto managerPtr = managerWeakPtr.lock();
	if (!managerPtr) {
		return;
	}

	gateway::Properties properties;
	gateway::TaskGroupProperties groupProps;
	groupProps.groupId = groupId;
	properties.property = groupProps;
	managerPtr->trigger(gateway::RequestType::DeleteTaskGroup, properties);
}

void ApiGatewayService::requestGetTaskGroups(const std::string &userId)
{
	if (!m_gateway) {
		return;
	}

	auto managerWeakPtr = m_gateway->getApiGatewayManager(gateway::RouteType::TaskManagement);
	auto managerPtr = managerWeakPtr.lock();
	if (!managerPtr) {
		return;
	}

	gateway::Properties properties;
	gateway::TaskGroupProperties groupProps;
	groupProps.userId = userId;
	properties.property = groupProps;
	managerPtr->trigger(gateway::RequestType::GetTaskGroups, properties);
}

void ApiGatewayService::onResponseCreateTaskGroup(const TaskGroup &taskGroup)
{
	for (const auto &listener : m_listeners) {
		auto apiListener = dynamic_cast<IApiGatewayServiceListener *>(listener);
		if (apiListener) {
			apiListener->onTaskGroupCreated(taskGroup);
		}
	}
}

void ApiGatewayService::onResponseUpdateTaskGroup(const TaskGroup &taskGroup)
{
	for (const auto &listener : m_listeners) {
		auto apiListener = dynamic_cast<IApiGatewayServiceListener *>(listener);
		if (apiListener) {
			apiListener->onTaskGroupUpdated(taskGroup);
		}
	}
}

void ApiGatewayService::onResponseDeleteTaskGroup(const std::string &groupId)
{
	for (const auto &listener : m_listeners) {
		auto apiListener = dynamic_cast<IApiGatewayServiceListener *>(listener);
		if (apiListener) {
			apiListener->onTaskGroupDeleted(groupId);
		}
	}
}

void ApiGatewayService::onResponseGetTaskGroups(const std::vector<TaskGroup> &taskGroups)
{
	for (const auto &listener : m_listeners) {
		auto apiListener = dynamic_cast<IApiGatewayServiceListener *>(listener);
		if (apiListener) {
			apiListener->onTaskGroupsRetrieved(taskGroups);
		}
	}
}

void ApiGatewayService::requestCreateSession(const Session &session)
{
	if (!m_gateway) {
		return;
	}

	auto managerWeakPtr = m_gateway->getApiGatewayManager(gateway::RouteType::Pomodoro);
	auto managerPtr = managerWeakPtr.lock();
	if (!managerPtr) {
		return;
	}

	gateway::Properties properties;
	gateway::PomodoroSessionProperties sessionProps;
	sessionProps.sessionId = session.sessionId;
	sessionProps.userId = session.userId;
	sessionProps.taskId = session.taskId;
	sessionProps.type = static_cast<gateway::PomodoroSessionType>(session.type);
	sessionProps.status = static_cast<gateway::PomodoroSessionStatus>(session.status);
	sessionProps.startTime = session.startTime;
	sessionProps.endTime = session.endTime;
	sessionProps.lastUpdatedTime = session.lastUpdatedTime;
	properties.property = sessionProps;
	managerPtr->trigger(gateway::RequestType::CreatePomodoroSession, properties);
}

void ApiGatewayService::requestUpdateSession(const Session &session)
{
	if (!m_gateway) {
		return;
	}

	auto managerWeakPtr = m_gateway->getApiGatewayManager(gateway::RouteType::Pomodoro);
	auto managerPtr = managerWeakPtr.lock();
	if (!managerPtr) {
		return;
	}

	gateway::Properties properties;
	gateway::PomodoroSessionProperties sessionProps;
	sessionProps.sessionId = session.sessionId;
	sessionProps.userId = session.userId;
	sessionProps.taskId = session.taskId;
	sessionProps.type = static_cast<gateway::PomodoroSessionType>(session.type);
	sessionProps.status = static_cast<gateway::PomodoroSessionStatus>(session.status);
	sessionProps.startTime = session.startTime;
	sessionProps.endTime = session.endTime;
	sessionProps.lastUpdatedTime = session.lastUpdatedTime;
	properties.property = sessionProps;
	managerPtr->trigger(gateway::RequestType::UpdatePomodoroSession, properties);
}

void ApiGatewayService::requestDeleteSession(const std::string &sessionId)
{
	if (!m_gateway) {
		return;
	}

	auto managerWeakPtr = m_gateway->getApiGatewayManager(gateway::RouteType::Pomodoro);
	auto managerPtr = managerWeakPtr.lock();
	if (!managerPtr) {
		return;
	}

	gateway::Properties properties;
	gateway::PomodoroSessionProperties sessionProps;
	sessionProps.sessionId = sessionId;
	properties.property = sessionProps;
	managerPtr->trigger(gateway::RequestType::DeletePomodoroSession, properties);
}

void ApiGatewayService::requestGetSessions(const std::string &userId, const std::string &taskId)
{
	if (!m_gateway) {
		return;
	}

	auto managerWeakPtr = m_gateway->getApiGatewayManager(gateway::RouteType::Pomodoro);
	auto managerPtr = managerWeakPtr.lock();
	if (!managerPtr) {
		return;
	}

	gateway::Properties properties;
	gateway::PomodoroSessionProperties sessionProps;
	sessionProps.userId = userId;
	sessionProps.taskId = taskId;
	properties.property = sessionProps;
	managerPtr->trigger(gateway::RequestType::GetPomodoroSessions, properties);
}
