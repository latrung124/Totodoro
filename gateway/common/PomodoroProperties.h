/**
 * @file PomodoroProperties.h
 * @author trung.la
 * @date 09-24-2025
 * @brief This file contains the declaration of the PomodoroProperties struct.
 */

#pragma once

#include <string>
#include <cstdint>
#include <chrono>

namespace gateway
{
    enum class PomodoroSessionStatus : uint8_t
    {
        idle,
        inprogress,
        pending,
        completed
    };

    enum class PomodoroSessionType : uint8_t
    {
        short_break,
        long_break
    };

    struct PomodoroSessionProperties
    {
        std::string sessionId;
        std::string userId;
        std::string taskId;
        PomodoroSessionType type;
        PomodoroSessionStatus status;
        uint16_t progress;
        uint16_t numberInCycle;
        std::chrono::system_clock::time_point startTime;
        std::chrono::system_clock::time_point endTime;
        std::chrono::system_clock::time_point lastUpdatedTime;
    };
}