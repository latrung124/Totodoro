/**
 * @file UserProperties.h
 * @author trung.la
 * @date 10-02-2025
 * @brief This file contains the declaration of the UserProperties struct.
 */

#include "UserProperties.h"

#include <nlohmann/json.hpp>

namespace gateway {
std::string UserProperties::toJsonString() const
{
	nlohmann::json j;
	j["userId"] = userId;
	j["email"] = email;
	j["userName"] = userName;
	j["createdTime"] =
	    std::chrono::duration_cast<std::chrono::milliseconds>(createdTime.time_since_epoch()).count();
	j["lastUpdatedTime"] =
	    std::chrono::duration_cast<std::chrono::milliseconds>(lastUpdatedTime.time_since_epoch())
	        .count();
	return j.dump();
}

std::string UserProperties::toCreateUserBodyJsonString() const
{
	nlohmann::json j;
	j["email"] = email;
	j["userName"] = userName;
	return j.dump();
}

std::string UserProperties::toUpdateUserBodyJsonString() const
{
	nlohmann::json j;
	j["email"] = email;
	j["userName"] = userName;
	return j.dump();
}

std::string UserSettings::toJsonString() const
{
	nlohmann::json j;
	j["userId"] = userId;
	j["theme"] = theme;
	j["language"] = language;
	j["pomodoroDuration"] = pomodoroDuration;
	j["shortBreakDuration"] = shortBreakDuration;
	j["longBreakDuration"] = longBreakDuration;
	j["longBreakInterval"] = longBreakInterval;
	j["autoStartShortBreak"] = autoStartShortBreak;
	j["autoStartLongBreak"] = autoStartLongBreak;
	j["autoStartPomodoro"] = autoStartPomodoro;
	j["shortBreakNotification"] = shortBreakNotification;
	j["longBreakNotification"] = longBreakNotification;
	j["pomodoroNotification"] = pomodoroNotification;
	j["autoStartMusic"] = autoStartMusic;
	j["autoStartNextTask"] = autoStartNextTask;
	return j.dump();
}

std::string UserSettings::toUpdateSettingsBodyJsonString() const
{
	nlohmann::json j;
	j["theme"] = theme;
	j["language"] = language;
	j["pomodoroDuration"] = pomodoroDuration;
	j["shortBreakDuration"] = shortBreakDuration;
	j["longBreakDuration"] = longBreakDuration;
	j["longBreakInterval"] = longBreakInterval;
	j["autoStartShortBreak"] = autoStartShortBreak;
	j["autoStartLongBreak"] = autoStartLongBreak;
	j["autoStartPomodoro"] = autoStartPomodoro;
	j["shortBreakNotification"] = shortBreakNotification;
	j["longBreakNotification"] = longBreakNotification;
	j["pomodoroNotification"] = pomodoroNotification;
	j["autoStartMusic"] = autoStartMusic;
	j["autoStartNextTask"] = autoStartNextTask;
	return j.dump();
}
} // namespace gateway
