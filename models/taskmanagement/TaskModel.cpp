/**
 * @file TaskModel.cpp
 * @author trung.la
 * @date 10-31-2025
 * @brief Implementation of the TaskModel class for managing task data.
 */

#include "models/taskmanagement/TaskModel.h"

TaskModel::TaskModel() = default;
TaskModel::~TaskModel() = default;

uint16_t TaskModel::getTotalPomodoros() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_totalPomodoros;
}

void TaskModel::setTotalPomodoros(uint16_t totalPomodoros)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (totalPomodoros != m_totalPomodoros) {
		m_totalPomodoros = totalPomodoros;
	}
}

uint16_t TaskModel::getCompletedPomodoros() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_completedPomodoros;
}

void TaskModel::setCompletedPomodoros(uint16_t completedPomodoros)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (completedPomodoros != m_completedPomodoros) {
		m_completedPomodoros = completedPomodoros;
	}
}

uint16_t TaskModel::getProgress() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_progress;
}

void TaskModel::setProgress(uint16_t progress)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (progress != m_progress) {
		m_progress = progress;
	}
}

std::string TaskModel::getTaskId() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_taskId;
}

void TaskModel::setTaskId(const std::string &taskId)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (taskId != m_taskId) {
		m_taskId = taskId;
	}
}

std::string TaskModel::getUserId() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_userId;
}

void TaskModel::setUserId(const std::string &userId)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (userId != m_userId) {
		m_userId = userId;
	}
}

std::string TaskModel::getGroupId() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_groupId;
}

void TaskModel::setGroupId(const std::string &groupId)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (groupId != m_groupId) {
		m_groupId = groupId;
	}
}

std::string TaskModel::getName() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_name;
}

void TaskModel::setName(const std::string &name)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (name != m_name) {
		m_name = name;
	}
}

std::string TaskModel::getDescription() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_description;
}

void TaskModel::setDescription(const std::string &description)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (description != m_description) {
		m_description = description;
	}
}

TaskModel::TaskPriority TaskModel::getPriority() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_priority;
}

void TaskModel::setPriority(TaskPriority priority)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (priority != m_priority) {
		m_priority = priority;
	}
}

TaskModel::TaskStatus TaskModel::getStatus() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_status;
}

void TaskModel::setStatus(TaskStatus status)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (status != m_status) {
		m_status = status;
	}
}
