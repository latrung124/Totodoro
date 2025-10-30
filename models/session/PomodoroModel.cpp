/**
 * @file PomodoroModel.cpp
 * @author trung.la
 * @date 10-30-2025
 * @brief Implementation of the PomodoroModel class for managing Pomodoro session data.
 */

#include "models/session/PomodoroModel.h"

#include <QMetaObject>
#include <QString>

PomodoroModel::PomodoroModel() = default;
PomodoroModel::~PomodoroModel() = default;

std::string PomodoroModel::getSessionId() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_sessionId;
}

void PomodoroModel::setSessionId(const std::string &sessionId)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (m_sessionId != sessionId) {
		m_sessionId = sessionId;
	}
}

std::string PomodoroModel::getUserId() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_userId;
}

void PomodoroModel::setUserId(const std::string &userId)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (m_userId != userId) {
		m_userId = userId;
	}
}

uint32_t PomodoroModel::getDuration() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_duration;
}

void PomodoroModel::setDuration(uint32_t duration)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (m_duration != duration) {
		m_duration = duration;
	}
}

std::string PomodoroModel::getStatus() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_status;
}

void PomodoroModel::setStatus(const std::string &status)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (m_status != status) {
		m_status = status;
	}
}

std::string PomodoroModel::getType() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_type;
}

void PomodoroModel::setType(const std::string &type)
{
	if (m_type != type) {
		m_type = type;
	}
}

uint16_t PomodoroModel::getProgress() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_progress;
}

void PomodoroModel::setProgress(uint16_t progress)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (m_progress != progress) {
		m_progress = progress;
	}
}

uint16_t PomodoroModel::getNumberInCycle() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_numberInCycle;
}

void PomodoroModel::setNumberInCycle(uint16_t numberInCycle)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (m_numberInCycle != numberInCycle) {
		m_numberInCycle = numberInCycle;
	}
}
