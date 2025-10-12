/**
 * @file TaskProperties.h
 * @author trung.la
 * @date 09-23-2025
 * @brief This file contains the definition of the TaskProperties struct.
 */

#pragma once

#include <string>
#include <stdint.h>
#include <chrono>

namespace gateway
{

// ================================= Task Properties =================================
enum class TaskPriority : uint8_t
{
    low,
    medium,
    high
};

enum class TaskStatus : uint8_t
{
    idle,
    pending,
    in_progress,
    completed
};

static std::string taskPriorityToString(TaskPriority priority)
{
    switch (priority)
    {
        case TaskPriority::low:
            return "TASK_PRIORITY_LOW";
        case TaskPriority::medium:
            return "TASK_PRIORITY_MEDIUM";
        case TaskPriority::high:
            return "TASK_PRIORITY_HIGH";
        default:
            return "TASK_PRIORITY_UNSPECIFIED";
    }
}

static std::string taskStatusToString(TaskStatus status)
{
    switch (status)
    {
        case TaskStatus::idle:
            return "TASK_STATUS_IDLE";
        case TaskStatus::pending:
            return "TASK_STATUS_PENDING";
        case TaskStatus::in_progress:
            return "TASK_STATUS_IN_PROGRESS";
        case TaskStatus::completed:
            return "TASK_STATUS_COMPLETED";
        default:
            return "TASK_STATUS_UNSPECIFIED";
    }
}

static TaskPriority stringToTaskPriority(const std::string& priorityStr)
{
    if (priorityStr == "TASK_PRIORITY_LOW")
        return TaskPriority::low;
    else if (priorityStr == "TASK_PRIORITY_MEDIUM")
        return TaskPriority::medium;
    else if (priorityStr == "TASK_PRIORITY_HIGH")
        return TaskPriority::high;
    else
        return TaskPriority::medium; // Default to medium if unspecified
}

static TaskStatus stringToTaskStatus(const std::string& statusStr)
{
    if (statusStr == "TASK_STATUS_IDLE")
        return TaskStatus::idle;
    else if (statusStr == "TASK_STATUS_PENDING")
        return TaskStatus::pending;
    else if (statusStr == "TASK_STATUS_IN_PROGRESS")
        return TaskStatus::in_progress;
    else if (statusStr == "TASK_STATUS_COMPLETED")
        return TaskStatus::completed;
    else
        return TaskStatus::idle; // Default to idle if unspecified
}

struct TaskProperties {
    uint16_t totalPomodoros;
    uint16_t completedPomodoros;
    uint16_t progress;
    std::string taskId;
    std::string userId;
    std::string groupId;
    std::string name;
    std::string description;
    TaskPriority priority;
    TaskStatus status;
    std::chrono::system_clock::time_point deadline;
    std::chrono::system_clock::time_point createdTime;
    std::chrono::system_clock::time_point lastUpdatedTime;


    TaskProperties()
        : totalPomodoros(0)
        , completedPomodoros(0)
        , progress(0)
        , priority(TaskPriority::medium)
        , status(TaskStatus::idle)
        , deadline(std::chrono::system_clock::time_point::max())
        , createdTime(std::chrono::system_clock::now())
        , lastUpdatedTime(std::chrono::system_clock::now())
    {
    }

    std::string toJsonString() const;
    std::string toCreateTaskBodyJsonString() const;
    std::string toUpdateTaskBodyJsonString() const;
};

// ================================= Task Group Properties =================================

enum TaskGroupPriority : uint8_t
{
    low,
    medium,
    high
};

enum TaskGroupStatus : uint8_t
{
    idle,
    pending,
    inprogress,
    completed
};

static std::string taskGroupPriorityToString(TaskGroupPriority priority)
{
    switch (priority)
    {
        case TaskGroupPriority::low:
            return "TASK_GROUP_PRIORITY_LOW";
        case TaskGroupPriority::medium:
            return "TASK_GROUP_PRIORITY_MEDIUM";
        case TaskGroupPriority::high:
            return "TASK_GROUP_PRIORITY_HIGH";
        default:
            return "TASK_GROUP_PRIORITY_UNSPECIFIED";
    }
}

static std::string taskGroupStatusToString(TaskGroupStatus status)
{
    switch (status)
    {
        case TaskGroupStatus::idle:
            return "TASK_GROUP_STATUS_IDLE";
        case TaskGroupStatus::pending:
            return "TASK_GROUP_STATUS_PENDING";
        case TaskGroupStatus::inprogress:
            return "TASK_GROUP_STATUS_IN_PROGRESS";
        case TaskGroupStatus::completed:
            return "TASK_GROUP_STATUS_COMPLETED";
        default:
            return "TASK_GROUP_STATUS_UNSPECIFIED";
    }
}

static TaskGroupPriority stringToTaskGroupPriority(const std::string& priorityStr)
{
    if (priorityStr == "TASK_GROUP_PRIORITY_LOW")
        return TaskGroupPriority::low;
    else if (priorityStr == "TASK_GROUP_PRIORITY_MEDIUM")
        return TaskGroupPriority::medium;
    else if (priorityStr == "TASK_GROUP_PRIORITY_HIGH")
        return TaskGroupPriority::high;
    else
        return TaskGroupPriority::medium; // Default to medium if unspecified
}

static TaskGroupStatus stringToTaskGroupStatus(const std::string& statusStr)
{
    if (statusStr == "TASK_GROUP_STATUS_IDLE")
        return TaskGroupStatus::idle;
    else if (statusStr == "TASK_GROUP_STATUS_PENDING")
        return TaskGroupStatus::pending;
    else if (statusStr == "TASK_GROUP_STATUS_IN_PROGRESS")
        return TaskGroupStatus::inprogress;
    else if (statusStr == "TASK_GROUP_STATUS_COMPLETED")
        return TaskGroupStatus::completed;
    else
        return TaskGroupStatus::idle; // Default to idle if unspecified
}

struct TaskGroupProperties {
    std::string groupId;
    std::string userId;
    std::string name;
    std::string icon;
    std::string description;
    uint16_t completedTasks;
    uint16_t totalTasks;
    TaskGroupPriority priority;
    TaskGroupStatus status;
    std::chrono::system_clock::time_point deadline;
    std::chrono::system_clock::time_point createdTime;
    std::chrono::system_clock::time_point lastUpdatedTime;

    TaskGroupProperties()
        : priority(TaskGroupPriority::medium)
        , status(TaskGroupStatus::idle)
        , deadline(std::chrono::system_clock::time_point::max())
        , createdTime(std::chrono::system_clock::now())
        , lastUpdatedTime(std::chrono::system_clock::now())
    {
    }

    std::string toJsonString() const;
    std::string toCreateTaskGroupBodyJsonString() const;
    std::string toUpdateTaskGroupBodyJsonString() const;
};

}