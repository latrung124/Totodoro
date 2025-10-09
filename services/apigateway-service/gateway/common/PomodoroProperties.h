/**
 * @file PomodoroProperties.h
 * @author trung.la
 * @date 09-24-2025
 * @brief This file contains the declaration of the PomodoroProperties struct.
 */

#pragma once

#include <chrono>
#include <cstdint>
#include <string>

namespace gateway {
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

static std::string pomodoroSessionStatusToString(PomodoroSessionStatus status)
{
	switch (status) {
	case PomodoroSessionStatus::idle:
		return "SESSION_STATUS_IDLE";
	case PomodoroSessionStatus::inprogress:
		return "SESSION_STATUS_INPROGRESS";
	case PomodoroSessionStatus::pending:
		return "SESSION_STATUS_PENDING";
	case PomodoroSessionStatus::completed:
		return "SESSION_STATUS_COMPLETED";
	default:
		return "SESSION_STATUS_UNSPECIFIED";
	}
}

static std::string pomodoroSessionTypeToString(PomodoroSessionType type)
{
	switch (type) {
	case PomodoroSessionType::short_break:
		return "SESSION_TYPE_SHORT_BREAK";
	case PomodoroSessionType::long_break:
		return "SESSION_TYPE_LONG_BREAK";
	default:
		return "SESSION_TYPE_UNSPECIFIED";
	}
}

static PomodoroSessionType stringToPomodoroSessionType(const std::string &typeStr)
{
	if (typeStr == "SESSION_TYPE_SHORT_BREAK") {
		return PomodoroSessionType::short_break;
	} else if (typeStr == "SESSION_TYPE_LONG_BREAK") {
		return PomodoroSessionType::long_break;
	} else {
		return PomodoroSessionType::short_break; // Default value
	}
}

static PomodoroSessionStatus stringToPomodoroSessionStatus(const std::string &statusStr)
{
	if (statusStr == "SESSION_STATUS_IDLE") {
		return PomodoroSessionStatus::idle;
	} else if (statusStr == "SESSION_STATUS_INPROGRESS") {
		return PomodoroSessionStatus::inprogress;
	} else if (statusStr == "SESSION_STATUS_PENDING") {
		return PomodoroSessionStatus::pending;
	} else if (statusStr == "SESSION_STATUS_COMPLETED") {
		return PomodoroSessionStatus::completed;
	} else {
		return PomodoroSessionStatus::idle; // Default value
	}
}

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

	std::string toJsonString() const;
	std::string toCreateSessionBodyJsonString() const;
	std::string toUpdateSessionBodyJsonString() const;
};
} // namespace gateway
