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

void TaskGroupViewModel::setTaskCompleted(int taskCompleted)
{
	if (m_taskCompleted != taskCompleted) {
		m_taskCompleted = taskCompleted;
		emit taskCompletedChanged();
	}
}

int TaskGroupViewModel::taskCompleted() const
{
	return m_taskCompleted;
}

void TaskGroupViewModel::setTotalTask(int totalTask)
{
	if (m_totalTask != totalTask) {
		m_totalTask = totalTask;
		emit totalTaskChanged();
	}
}

int TaskGroupViewModel::totalTask() const
{
	return m_totalTask;
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
