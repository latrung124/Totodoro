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
    inprogress,
    completed
};

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
};

}