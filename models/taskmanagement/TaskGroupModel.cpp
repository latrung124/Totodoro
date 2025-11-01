/**
 * @file TaskGroupModel.cpp
 * @author trung.la
 * @date 11-01-2025
 * @brief Implementation of the TaskGroupModel class for representing task group data.
 */

#include "models/taskmanagement/TaskGroupModel.h"

TaskGroupModel::TaskGroupModel()
    : DatabaseModel()
    , m_groupId("")
    , m_userId("")
    , m_name("")
    , m_icon("")
    , m_description("")
    , m_completedTasks(0)
    , m_totalTasks(0)
    , m_priority(TaskGroupPriority::medium)
    , m_status(TaskGroupStatus::idle)
{
}

TaskGroupModel::~TaskGroupModel()
{
}

std::string TaskGroupModel::getGroupId() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_groupId;
}

void TaskGroupModel::setGroupId(const std::string &groupId)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (m_groupId == groupId) {
		return;
	}
	m_groupId = groupId;
}

std::string TaskGroupModel::getUserId() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_userId;
}

void TaskGroupModel::setUserId(const std::string &userId)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (m_userId == userId) {
		return;
	}
	m_userId = userId;
}

std::string TaskGroupModel::getName() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_name;
}

void TaskGroupModel::setName(const std::string &name)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (m_name == name) {
		return;
	}
	m_name = name;
}

std::string TaskGroupModel::icon() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_icon;
}

void TaskGroupModel::setIcon(const std::string &icon)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (m_icon == icon) {
		return;
	}
	m_icon = icon;
}

std::string TaskGroupModel::getDescription() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_description;
}

void TaskGroupModel::setDescription(const std::string &description)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (m_description == description) {
		return;
	}
	m_description = description;
}

uint16_t TaskGroupModel::getCompletedTasks() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_completedTasks;
}

void TaskGroupModel::setCompletedTasks(uint16_t completedTasks)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (m_completedTasks == completedTasks) {
		return;
	}
	m_completedTasks = completedTasks;
}

uint16_t TaskGroupModel::getTotalTasks() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_totalTasks;
}

void TaskGroupModel::setTotalTasks(uint16_t totalTasks)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (m_totalTasks == totalTasks) {
		return;
	}
	m_totalTasks = totalTasks;
}

TaskGroupModel::TaskGroupPriority TaskGroupModel::getPriority() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_priority;
}

void TaskGroupModel::setPriority(TaskGroupPriority priority)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (m_priority == priority) {
		return;
	}
	m_priority = priority;
}

TaskGroupModel::TaskGroupStatus TaskGroupModel::getStatus() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_status;
}

void TaskGroupModel::setStatus(TaskGroupStatus status)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (m_status == status) {
		return;
	}
	m_status = status;
}
