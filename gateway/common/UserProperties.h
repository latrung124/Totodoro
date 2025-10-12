/**
 * @file UserProperties.h
 * @author trung.la
 * @date 09-22-2025
 * @brief This file contains the declaration of the UserProperties struct.
 */

#pragma once

#include <string>
#include <chrono>

namespace gateway
{

struct UserProperties
{
    std::string userId;
    std::string email;
    std::string userName;
	std::chrono::system_clock::time_point createdTime;
	std::chrono::system_clock::time_point lastUpdatedTime;
    
    std::string toJsonString() const;
    std::string toCreateUserBodyJsonString() const;
    std::string toUpdateUserBodyJsonString() const;
};

struct UserSettings
{
    std::string userId;
    std::string theme;
    std::string language;
    uint32_t pomodoroDuration;      // in minutes
    uint32_t shortBreakDuration;    // in minutes
    uint32_t longBreakDuration;     // in minutes
    uint32_t longBreakInterval;     // number of pomodoros before a long break
    bool autoStartShortBreak;
    bool autoStartLongBreak;
    bool autoStartPomodoro;
    bool shortBreakNotification;
    bool longBreakNotification;
    bool pomodoroNotification;
    bool autoStartMusic;
    bool autoStartNextTask;

    std::string toJsonString() const;
    std::string toUpdateSettingsBodyJsonString() const;
};

} // namespace gateway