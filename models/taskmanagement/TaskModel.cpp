/**
 * @file TaskModel.cpp
 * @author trung.la
 * @date 10-31-2025
 * @brief Implementation of the TaskModel class for managing task data.
 */

#include "models/taskmanagement/TaskModel.h"

#include <QMetaObject>

#include "core/controllers/ViewModelController.h"
#include "view-models/taskmanagement/TasksViewModel.h"
#include "view-models/taskmanagement/TaskViewModel.h"

TaskModel::TaskModel() = default;
TaskModel::~TaskModel() = default;

TaskModel::TaskModel(TaskModel &&other) noexcept
{
	// setTaskId(other.m_taskId);
	setTotalPomodoros(other.m_totalPomodoros);
	setCompletedPomodoros(other.m_completedPomodoros);
	setProgress(other.m_progress);
	setUserId(other.m_userId);
	setGroupId(other.m_groupId);
	setName(other.m_name);
	setDescription(other.m_description);
	setPriority(other.m_priority);
	setStatus(other.m_status);
}

TaskModel &TaskModel::operator=(TaskModel &&other) noexcept
{
	if (this != &other) {
		setTotalPomodoros(other.m_totalPomodoros);
		setCompletedPomodoros(other.m_completedPomodoros);
		setProgress(other.m_progress);
		setUserId(other.m_userId);
		setGroupId(other.m_groupId);
		setName(other.m_name);
		setDescription(other.m_description);
		setPriority(other.m_priority);
		setStatus(other.m_status);
	}
	return *this;
}

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

	auto model = ViewModelController::getInstance().tasksViewModel();
	if (!model) {
		return;
	}
	if (auto taskVM = model->getTaskById(QString::fromStdString(m_taskId))) {
		QMetaObject::invokeMethod(
		    taskVM.get(), "onTotalPomodorosChanged", Q_ARG(uint16_t, totalPomodoros));
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

	auto model = ViewModelController::getInstance().tasksViewModel();
	if (!model) {
		return;
	}
	if (auto taskVM = model->getTaskById(QString::fromStdString(m_taskId))) {
		QMetaObject::invokeMethod(
		    taskVM.get(), "onCompletedPomodorosChanged", Q_ARG(uint16_t, completedPomodoros));
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

	auto model = ViewModelController::getInstance().tasksViewModel();
	if (!model) {
		return;
	}
	if (auto taskVM = model->getTaskById(QString::fromStdString(m_taskId))) {
		QMetaObject::invokeMethod(taskVM.get(), "onProgressChanged", Q_ARG(uint16_t, progress));
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

	auto model = ViewModelController::getInstance().tasksViewModel();
	if (!model) {
		return;
	}
	if (auto taskVM = model->getTaskById(QString::fromStdString(m_taskId))) {
		QMetaObject::invokeMethod(taskVM.get(), "onTaskIdChanged", Q_ARG(std::string, taskId));
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

	auto model = ViewModelController::getInstance().tasksViewModel();
	if (!model) {
		return;
	}
	if (auto taskVM = model->getTaskById(QString::fromStdString(m_taskId))) {
		QMetaObject::invokeMethod(taskVM.get(), "onUserIdChanged", Q_ARG(std::string, userId));
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

	auto model = ViewModelController::getInstance().tasksViewModel();
	if (!model) {
		return;
	}
	if (auto taskVM = model->getTaskById(QString::fromStdString(m_taskId))) {
		QMetaObject::invokeMethod(taskVM.get(), "onGroupIdChanged", Q_ARG(std::string, groupId));
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

	auto model = ViewModelController::getInstance().tasksViewModel();
	if (!model) {
		return;
	}
	if (auto taskVM = model->getTaskById(QString::fromStdString(m_taskId))) {
		QMetaObject::invokeMethod(taskVM.get(), "onNameChanged", Q_ARG(std::string, name));
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

	auto model = ViewModelController::getInstance().tasksViewModel();
	if (!model) {
		return;
	}
	if (auto taskVM = model->getTaskById(QString::fromStdString(m_taskId))) {
		QMetaObject::invokeMethod(
		    taskVM.get(), "onDescriptionChanged", Q_ARG(std::string, description));
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

	auto model = ViewModelController::getInstance().tasksViewModel();
	if (!model) {
		return;
	}
	if (auto taskVM = model->getTaskById(QString::fromStdString(m_taskId))) {
		QMetaObject::invokeMethod(taskVM.get(), "onPriorityChanged", Q_ARG(TaskPriority, priority));
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

	auto model = ViewModelController::getInstance().tasksViewModel();
	if (!model) {
		return;
	}
	if (auto taskVM = model->getTaskById(QString::fromStdString(m_taskId))) {
		QMetaObject::invokeMethod(taskVM.get(), "onStatusChanged", Q_ARG(TaskStatus, status));
	}
}
