/**
 * @file ApiGatewayServiceUtils.h
 * @author trung.la
 * @date 09-20-2025
 * @brief ApiGatewayServiceUtils interface
 */

#ifndef API_GATEWAY_SERVICE_UTILS_H
#define API_GATEWAY_SERVICE_UTILS_H

#include <chrono>
#include <stdint.h>
#include <string>

namespace apigateway_service { namespace utils {
namespace user {

struct Information
{
	std::string userId;
	std::string email;
	std::string username;
	std::chrono::system_clock::time_point createdTime;
	std::chrono::system_clock::time_point lastUpdatedTime;
};

struct Settings
{
	std::string userId;
	std::string theme;
	std::string language;
	uint32_t pomodoroDuration;
	uint32_t shortBreakDuration;
	uint32_t longBreakDuration;
	uint32_t longBreakInterval;
	bool autoStartShortBreak;
	bool autoStartLongBreak;
	bool autoStartPomodoro;
	bool shortBreakNotification;
	bool longBreakNotification;
	bool pomodoroNotification;
	bool autoStartMusic;
	bool autoStartNextTask;
};

} // namespace user

namespace task_management {

struct Task
{
	uint16_t totalPomodoros;
	uint16_t completedPomodoros;
	uint16_t progress;
	std::string taskId;
	std::string userId;
	std::string groupId;
	std::string name;
	std::string description;
	std::string priority;
	std::string status;
	std::chrono::system_clock::time_point deadline;
	std::chrono::system_clock::time_point createdTime;
	std::chrono::system_clock::time_point lastUpdatedTime;
};

struct TaskGroup
{
	std::string groupId;
	std::string userId;
	std::string name;
	std::string icon;
	std::string description;
	uint16_t completedTasks;
	uint16_t totalTasks;
	std::string priority;
	std::string status;
	std::chrono::system_clock::time_point deadline;
	std::chrono::system_clock::time_point createdTime;
	std::chrono::system_clock::time_point lastUpdatedTime;
};

} // namespace task_management
}} // namespace apigateway_service::utils

#endif // API_GATEWAY_SERVICE_UTILS_H
