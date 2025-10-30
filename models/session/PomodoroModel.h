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

	// Getters and setters for Pomodoro session properties
	std::string getSessionId() const;
	void setSessionId(const std::string &sessionId);

	std::string getUserId() const;
	void setUserId(const std::string &userId);

	uint32_t getDuration() const;
	void setDuration(uint32_t duration);

	std::string getStatus() const;
	void setStatus(const std::string &status);

	std::string getType() const;
	void setType(const std::string &type);

	uint16_t getProgress() const;
	void setProgress(uint16_t progress);

	uint16_t getNumberInCycle() const;
	void setNumberInCycle(uint16_t numberInCycle);

private:
	std::string m_sessionId = "";
	std::string m_userId = "";
	uint32_t m_duration = 0;
	std::string m_status = "";
	std::string m_type = "";
	uint16_t m_progress = 0;
	uint16_t m_numberInCycle = 0;

	// Mutex for thread-safe access
	mutable std::mutex m_mutex;
};

#endif // MODELS_SESSION_POMODOROMODEL_H
