/**
 * @file CommonDefine.h
 * @author trung.la
 * @date 09-07-2025
 * @brief Common definitions and constants used across the gateway module.
 */

#pragma once

#include <stdint.h>
#include <string_view>

namespace gateway {

constexpr std::string_view kBaseUrl = "http://localhost:8081"; // Just for testing purpose, we will replace it later with actual URLs in env config

enum class RequestType : uint8_t
{
    CreatePomodoroSession = 0,
    GetPomodoroSessions,
    UpdatePomodoroSession,
    DeletePomodoroSession,
    CreateTask,
    GetTasks,
    UpdateTask,
    DeleteTask,
    CreateTaskGroup,
    GetTaskGroups,
    UpdateTaskGroup,
    DeleteTaskGroup,
    CreateUser,
    GetUserProperties,
    UpdateUserProperties,
    GetUserSettings,
    UpdateUserSettings,
    Unknown
};

enum class RouteType : uint8_t
{
    Pomodoro,
    TaskManagement,
    User,
    Notification
};

}
