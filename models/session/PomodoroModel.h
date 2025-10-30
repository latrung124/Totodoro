/**
 * @file PomodoroModel.h
 * @author trung.la
 * @date 10-30-2025
 * @brief Declaration of the PomodoroModel class for managing Pomodoro session data.
 */

#ifndef MODELS_SESSION_POMODOROMODEL_H
#define MODELS_SESSION_POMODOROMODEL_H

#include "models/DatabaseModel.h"

#include <mutex>
#include <string>

class PomodoroModel : public DatabaseModel
{
public:
	PomodoroModel();
	~PomodoroModel();

	enum class SessionType : uint8_t
	{
		ShortBreak = 0,
		LongBreak,
		Pomodoro
	};

	enum class SessionStatus : uint8_t
	{
		Idle = 0,
		InRunning,
		Paused,
		Completed
	};

	// Getters and setters for Pomodoro session properties
	std::string getSessionId() const;
	void setSessionId(const std::string &sessionId);

	std::string getUserId() const;
	void setUserId(const std::string &userId);

	std::string getTaskId() const;
	void setTaskId(const std::string &taskId);

	uint32_t getDuration() const;
	void setDuration(uint32_t duration);

	SessionStatus getStatus() const;
	void setStatus(const SessionStatus &status);

	SessionType getType() const;
	void setType(const SessionType &type);

	uint16_t getProgress() const;
	void setProgress(uint16_t progress);

	uint16_t getNumberInCycle() const;
	void setNumberInCycle(uint16_t numberInCycle);

private:
	std::string m_sessionId = "";
	std::string m_userId = "";
	std::string m_taskId = "";
	uint32_t m_duration = 0;
	SessionStatus m_status = SessionStatus::Idle;
	SessionType m_type = SessionType::Pomodoro;
	uint16_t m_progress = 0;
	uint16_t m_numberInCycle = 0;

	// Mutex for thread-safe access
	mutable std::mutex m_mutex;
};

#endif // MODELS_SESSION_POMODOROMODEL_H
