/*
 * File: TaskGroupViewModel.cpp
 * Author: trung.la
 * Date: 05-01-2025
 * Description: View Model for TaskGroup.
 */

#include "TaskGroupViewModel.h"

#include "view-models/taskmanagement/TasksViewModel.h"

TaskGroupViewModel::TaskGroupViewModel(QObject *parent)
    : QObject(parent)
{
}

TaskGroupViewModel::~TaskGroupViewModel()
{
}

void TaskGroupViewModel::setTaskGroupId(const QString &taskGroupId)
{
	if (m_taskGroupId != taskGroupId) {
		m_taskGroupId = taskGroupId;
		emit taskGroupIdChanged();
	}
}

QString TaskGroupViewModel::taskGroupId() const
{
	return m_taskGroupId;
}

void TaskGroupViewModel::setIcon(const QString &icon)
{
	if (m_icon != icon) {
		m_icon = icon;
		emit iconChanged();
	}
}

QString TaskGroupViewModel::icon() const
{
	return m_icon;
}

void TaskGroupViewModel::setName(const QString &name)
{
	if (m_name != name) {
		m_name = name;
		emit nameChanged();
	}
}

QString TaskGroupViewModel::name() const
{
	return m_name;
}

void TaskGroupViewModel::setDeadline(const QString &deadline)
{
	if (m_deadline != deadline) {
		m_deadline = deadline;
		emit deadlineChanged();
	}
}

QString TaskGroupViewModel::deadline() const
{
	return m_deadline;
}

void TaskGroupViewModel::setPriority(const PriorityType &priority)
{
	if (m_priority != priority) {
		m_priority = priority;
		emit priorityChanged();
	}
}

PriorityType TaskGroupViewModel::priority() const
{
	return m_priority;
}

void TaskGroupViewModel::setStatus(const QString &status)
{
	if (m_status != status) {
		m_status = status;
		emit statusChanged();
	}
}

QString TaskGroupViewModel::status() const
{
	return m_status;
}

void TaskGroupViewModel::setDescription(const QString &description)
{
	if (m_description != description) {
		m_description = description;
		emit descriptionChanged();
	}
}

QString TaskGroupViewModel::description() const
{
	return m_description;
}

int TaskGroupViewModel::completedTasks() const
{
	return m_completedTasks;
}

void TaskGroupViewModel::setCompletedTasks(int completedTasks)
{
	if (m_completedTasks != completedTasks) {
		m_completedTasks = completedTasks;
		emit completedTasksChanged();
	}
}

int TaskGroupViewModel::totalTasks() const
{
	return m_totalTasks;
}

void TaskGroupViewModel::setTotalTasks(int totalTasks)
{
	if (m_totalTasks != totalTasks) {
		m_totalTasks = totalTasks;
		emit totalTasksChanged();
	}
}

void TaskGroupViewModel::setTasks(const QObject *tasks)
{
	if (m_tasks.get() != tasks) {
		m_tasks.reset(static_cast<TasksViewModel *>(const_cast<QObject *>(tasks)));
		emit tasksChanged();
	}
}

QObject *TaskGroupViewModel::tasks() const
{
	return m_tasks.get();
}

void TaskGroupViewModel::onIconChanged(const QString &icon)
{
	setIcon(icon);
}

void TaskGroupViewModel::onNameChanged(const QString &name)
{
	setName(name);
}

void TaskGroupViewModel::onDeadlineChanged(const QString &deadline)
{
	setDeadline(deadline);
}

void TaskGroupViewModel::onPriorityChanged(const PriorityType &priority)
{
	setPriority(priority);
}

void TaskGroupViewModel::onStatusChanged(const QString &status)
{
	setStatus(status);
}

void TaskGroupViewModel::onDescriptionChanged(const QString &description)
{
	setDescription(description);
}

void TaskGroupViewModel::onCompletedTasksChanged(int completedTasks)
{
	setCompletedTasks(completedTasks);
}

void TaskGroupViewModel::onTotalTasksChanged(int totalTasks)
{
	setTotalTasks(totalTasks);
}

void TaskGroupViewModel::updateFromModel(
    const QString &taskGroupId,
    const QString &icon,
    const QString &name,
    const QString &deadline,
    const PriorityType &priority,
    const QString &status,
    const QString &description,
    int completedTasks,
    int totalTasks,
    const TasksViewModelPtr &tasks)
{
	setTaskGroupId(taskGroupId);
	setIcon(icon);
	setName(name);
	setDeadline(deadline);
	setPriority(priority);
	setStatus(status);
	setDescription(description);
	setCompletedTasks(completedTasks);
	setTotalTasks(totalTasks);
	setTasks(tasks.get());
}
