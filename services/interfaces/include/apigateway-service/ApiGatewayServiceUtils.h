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

namespace apigateway_service { namespace utils { namespace user {

struct UserInfo
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

}}} // namespace apigateway_service::utils::user

#endif // API_GATEWAY_SERVICE_UTILS_H
