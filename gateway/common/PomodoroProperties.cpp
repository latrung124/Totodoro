/**
 * @file PomodoroProperties.cpp
 * @author trung.la
 * @date 09-29-2025
 * @brief This file contains the implementation of the PomodoroProperties struct.
 */

#include "PomodoroProperties.h"

#include <nlohmann/json.hpp>

namespace gateway
{
    std::string PomodoroSessionProperties::toJsonString() const
    {
        nlohmann::json j;
        j["sessionId"] = sessionId;
        j["userId"] = userId;
        j["taskId"] = taskId;
        j["type"] = static_cast<uint8_t>(type);
        j["status"] = static_cast<uint8_t>(status);
        j["progress"] = progress;
        j["numberInCycle"] = numberInCycle;
        j["startTime"] = std::chrono::duration_cast<std::chrono::milliseconds>(startTime.time_since_epoch()).count();
        j["endTime"] = std::chrono::duration_cast<std::chrono::milliseconds>(endTime.time_since_epoch()).count();
        j["lastUpdatedTime"] = std::chrono::duration_cast<std::chrono::milliseconds>(lastUpdatedTime.time_since_epoch()).count();
        return j.dump();
    }

    std::string PomodoroSessionProperties::toCreateSessionBodyJsonString() const
    {
        nlohmann::json j;
        j["taskId"] = taskId;
        j["sessionType"] = static_cast<uint8_t>(type);
        j["numberInCycle"] = 1;
        j["startTime"] = std::chrono::duration_cast<std::chrono::milliseconds>(startTime.time_since_epoch()).count();
        return j.dump();
    }

    std::string PomodoroSessionProperties::toUpdateSessionBodyJsonString() const
    {
        nlohmann::json j;
        j["endTime"] = std::chrono::duration_cast<std::chrono::milliseconds>(endTime.time_since_epoch()).count();
        j["progress"] = progress;
        j["status"] = pomodoroSessionStatusToString(status); 
        j["sessionType"] = pomodoroSessionTypeToString(type);
        j["numberInCycle"] = numberInCycle;
        j["lastUpdatedTime"] = std::chrono::duration_cast<std::chrono::milliseconds>(lastUpdatedTime.time_since_epoch()).count();
        return j.dump();
    }
}