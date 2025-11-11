/**
 * @file TaskGroupModel.cpp
 * @author trung.la
 * @date 11-01-2025
 * @brief Implementation of the TaskGroupModel class for representing task group data.
 */

#include "models/taskmanagement/TaskGroupModel.h"

#include <QMetaObject>

#include "core/controllers/ViewModelController.h"
#include "view-models/taskmanagement/TaskGroupsViewModel.h"
#include "view-models/taskmanagement/TaskGroupViewModel.h"

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

TaskGroupModel::TaskGroupModel(TaskGroupModel &&other) noexcept
{
	setUserId(other.m_userId);
	setName(other.m_name);
	setIcon(other.m_icon);
	setDescription(other.m_description);
	setCompletedTasks(other.m_completedTasks);
	setTotalTasks(other.m_totalTasks);
	setPriority(other.m_priority);
	setStatus(other.m_status);
}

TaskGroupModel &TaskGroupModel::operator=(TaskGroupModel &&other) noexcept
{
	if (this != &other) {
		setUserId(other.m_userId);
		setName(other.m_name);
		setIcon(other.m_icon);
		setDescription(other.m_description);
		setCompletedTasks(other.m_completedTasks);
		setTotalTasks(other.m_totalTasks);
		setPriority(other.m_priority);
		setStatus(other.m_status);
	}
	return *this;
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

	auto model = ViewModelController::getInstance().taskGroupsViewModel();
	if (!model) {
		return;
	}

	if (auto taskGroupVM = model->getTaskGroupById(QString::fromStdString(groupId))) {
		QMetaObject::invokeMethod(
		    taskGroupVM.get(), "onGroupIdChanged", Q_ARG(std::string, m_groupId));
	}
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

	auto model = ViewModelController::getInstance().taskGroupsViewModel();
	if (!model) {
		return;
	}
	if (auto taskGroupVM = model->getTaskGroupById(QString::fromStdString(m_groupId))) {
		QMetaObject::invokeMethod(taskGroupVM.get(), "onUserIdChanged", Q_ARG(std::string, userId));
	}
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

	auto model = ViewModelController::getInstance().taskGroupsViewModel();
	if (!model) {
		return;
	}

	if (auto taskGroupVM = model->getTaskGroupById(QString::fromStdString(m_groupId))) {
		QMetaObject::invokeMethod(taskGroupVM.get(), "onNameChanged", Q_ARG(std::string, name));
	}
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

	auto model = ViewModelController::getInstance().taskGroupsViewModel();
	if (!model) {
		return;
	}

	if (auto taskGroupVM = model->getTaskGroupById(QString::fromStdString(m_groupId))) {
		QMetaObject::invokeMethod(taskGroupVM.get(), "onIconChanged", Q_ARG(std::string, icon));
	}
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

	auto model = ViewModelController::getInstance().taskGroupsViewModel();
	if (!model) {
		return;
	}

	if (auto taskGroupVM = model->getTaskGroupById(QString::fromStdString(m_groupId))) {
		QMetaObject::invokeMethod(
		    taskGroupVM.get(), "onDescriptionChanged", Q_ARG(std::string, description));
	}
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

	auto model = ViewModelController::getInstance().taskGroupsViewModel();
	if (!model) {
		return;
	}

	if (auto taskGroupVM = model->getTaskGroupById(QString::fromStdString(m_groupId))) {
		QMetaObject::invokeMethod(
		    taskGroupVM.get(), "onCompletedTasksChanged", Q_ARG(uint16_t, completedTasks));
	}
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

	auto model = ViewModelController::getInstance().taskGroupsViewModel();
	if (!model) {
		return;
	}

	if (auto taskGroupVM = model->getTaskGroupById(QString::fromStdString(m_groupId))) {
		QMetaObject::invokeMethod(
		    taskGroupVM.get(), "onTotalTasksChanged", Q_ARG(uint16_t, totalTasks));
	}
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

	auto model = ViewModelController::getInstance().taskGroupsViewModel();
	if (!model) {
		return;
	}

	if (auto taskGroupVM = model->getTaskGroupById(QString::fromStdString(m_groupId))) {
		QMetaObject::invokeMethod(
		    taskGroupVM.get(), "onPriorityChanged", Q_ARG(TaskGroupPriority, priority));
	}
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

	auto model = ViewModelController::getInstance().taskGroupsViewModel();
	if (!model) {
		return;
	}

	if (auto taskGroupVM = model->getTaskGroupById(QString::fromStdString(m_groupId))) {
		QMetaObject::invokeMethod(
		    taskGroupVM.get(), "onStatusChanged", Q_ARG(TaskGroupStatus, status));
	}
}
