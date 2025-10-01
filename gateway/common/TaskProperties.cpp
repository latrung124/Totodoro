/**
 * @file TaskProperties.cpp
 * @author trung.la
 * @date 10-01-2025
 * @brief This file contains the implementation of the TaskProperties struct methods.
 */

#include "TaskProperties.h"

#include <nlohmann/json.hpp>

namespace gateway
{

    std::string TaskProperties::toJsonString() const
    {
        nlohmann::json j;
        j["totalPomodoros"] = totalPomodoros;
        j["completedPomodoros"] = completedPomodoros;
        j["progress"] = progress;
        j["taskId"] = taskId;
        j["userId"] = userId;
        j["groupId"] = groupId;
        j["name"] = name;
        j["description"] = description;
        j["priority"] = taskPriorityToString(priority);
        j["status"] = taskStatusToString(status);
        j["deadline"] = std::chrono::duration_cast<std::chrono::milliseconds>(deadline.time_since_epoch()).count();
        j["createdTime"] = std::chrono::duration_cast<std::chrono::milliseconds>(
            createdTime.time_since_epoch()).count();
        j["lastUpdatedTime"] = std::chrono::duration_cast<std::chrono::milliseconds>(
            lastUpdatedTime.time_since_epoch()).count();
        return j.dump();
    }

//  Example JSON body for creating a task:
//  {
//   "userId": "user-123-xyz",
//   "icon": "🚀",
//   "name": "Develop Authentication API",
//   "description": "Implement JWT-based authentication for the user service.",
//   "deadline": "2025-10-15T23:59:59Z",
//   "priority": "TASK_PRIORITY_HIGH",
//   "status": "TASK_STATUS_PENDING",
//   "totalPomodoros": 8
//  }
    std::string TaskProperties::toCreateTaskBodyJsonString() const
    {
        nlohmann::json j;
        j["userId"] = userId;
        j["name"] = name;
        j["description"] = description;
        j["priority"] = taskPriorityToString(priority);
        j["status"] = taskStatusToString(status);
        j["totalPomodoros"] = totalPomodoros;
        if (deadline != std::chrono::system_clock::time_point::max())
        {
            j["deadline"] = std::chrono::duration_cast<std::chrono::milliseconds>(deadline.time_since_epoch()).count();
        }
        return j.dump();
    }

//  Example JSON body for updating a task:
// {
//   "icon": "✅",
//   "name": "Deploy Authentication API to Staging",
//   "description": "Deploy the latest version of the auth API to the staging environment for testing.",
//   "deadline": "2025-10-16T18:00:00Z",
//   "priority": "TASK_PRIORITY_HIGH",
//   "status": "TASK_STATUS_IN_PROGRESS",
//   "completedPomodoros": 4,
//   "totalPomodoros": 8,
//   "progress": 50
// }
    std::string TaskProperties::toUpdateTaskBodyJsonString() const
    {
        nlohmann::json j;
        j["name"] = name;
        j["description"] = description;
        j["priority"] = taskPriorityToString(priority);
        j["status"] = taskStatusToString(status);
        j["totalPomodoros"] = totalPomodoros;
        j["completedPomodoros"] = completedPomodoros;
        j["progress"] = progress;
        if (deadline != std::chrono::system_clock::time_point::max())
        {
            j["deadline"] = std::chrono::duration_cast<std::chrono::milliseconds>(deadline.time_since_epoch()).count();
        }
        return j.dump();
    }

// ================================= Task Group Properties =================================

    std::string TaskGroupProperties::toJsonString() const
    {
        nlohmann::json j;
        j["groupId"] = groupId;
        j["userId"] = userId;
        j["name"] = name;
        j["icon"] = icon;
        j["description"] = description;
        j["completedTasks"] = completedTasks;
        j["totalTasks"] = totalTasks;
        j["priority"] = static_cast<uint8_t>(priority);
        j["status"] = static_cast<uint8_t>(status);
        j["deadline"] = std::chrono::duration_cast<std::chrono::milliseconds>(deadline.time_since_epoch()).count();
        j["createdTime"] = std::chrono::duration_cast<std::chrono::milliseconds>(
            createdTime.time_since_epoch()).count();
        j["lastUpdatedTime"] = std::chrono::duration_cast<std::chrono::milliseconds>(
            lastUpdatedTime.time_since_epoch()).count();
        return j.dump();
    }

// Example JSON body for creating a task group:
// {
//   "userId": "user-123-xyz",
//   "icon": "📚",
//   "name": "Q4 Marketing Campaign",
//   "description": "All tasks related to the Q4 holiday marketing campaign.",
//   "deadline": "2025-12-20T23:59:59Z",
//   "priority": "TASK_GROUP_PRIORITY_MEDIUM",
//   "status": "TASK_GROUP_STATUS_PENDING",
//   "totalTasks": 15
// }
    std::string TaskGroupProperties::toCreateTaskGroupBodyJsonString() const
    {
        nlohmann::json j;
        j["userId"] = userId;
        j["name"] = name;
        j["icon"] = icon;
        j["description"] = description;
        j["priority"] = static_cast<uint8_t>(priority);
        j["status"] = static_cast<uint8_t>(status);
        j["totalTasks"] = totalTasks;
        if (deadline != std::chrono::system_clock::time_point::max())
        {
            j["deadline"] = std::chrono::duration_cast<std::chrono::milliseconds>(deadline.time_since_epoch()).count();
        }
        return j.dump();
    }

// Example JSON body for updating a task group:
// {
//   "icon": "🎉",
//   "name": "Q4 Marketing Campaign Launch",
//   "description": "All tasks for the final launch phase of the Q4 holiday campaign.",
//   "status": "TASK_GROUP_STATUS_IN_PROGRESS",
//   "priority": "TASK_GROUP_PRIORITY_HIGH",
//   "completedTasks": 5,
//   "totalTasks": 15,
//   "deadline": "2025-12-18T23:59:59Z"
// }

    std::string TaskGroupProperties::toUpdateTaskGroupBodyJsonString() const
    {
        nlohmann::json j;
        j["name"] = name;
        j["icon"] = icon;
        j["description"] = description;
        j["priority"] = static_cast<uint8_t>(priority);
        j["status"] = static_cast<uint8_t>(status);
        j["completedTasks"] = completedTasks;
        j["totalTasks"] = totalTasks;
        if (deadline != std::chrono::system_clock::time_point::max())
        {
            j["deadline"] = std::chrono::duration_cast<std::chrono::milliseconds>(deadline.time_since_epoch()).count();
        }
        return j.dump();
    }

} // namespace gateway