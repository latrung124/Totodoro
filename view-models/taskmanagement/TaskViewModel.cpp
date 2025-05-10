/*
 * File: TaskViewModel.cpp
 * Author: trung.la
 * Date: 05-02-2025
 * Description: View Model for Task.
 */

#include "TaskViewModel.h"

TaskViewModel::TaskViewModel(QObject *parent)
    : QObject(parent)
{
}

TaskViewModel::~TaskViewModel()
{
}

int TaskViewModel::id() const
{
	return m_id;
}

void TaskViewModel::setId(int id)
{
	if (m_id != id) {
		m_id = id;
		emit idChanged();
	}
}

QString TaskViewModel::name() const
{
	return m_name;
}

void TaskViewModel::setName(const QString &name)
{
	if (m_name != name) {
		m_name = name;
		emit nameChanged();
	}
}

QString TaskViewModel::icon() const
{
	return m_icon;
}

void TaskViewModel::setIcon(const QString &iconPath)
{
	if (m_icon != iconPath) {
		m_icon = iconPath;
		emit iconChanged();
	}
}

int TaskViewModel::totalPomodoros() const
{
	return m_totalPomodoros;
}

void TaskViewModel::setTotalPomodoros(int count)
{
	if (m_totalPomodoros != count) {
		m_totalPomodoros = count;
		emit totalPomodorosChanged();
	}
}

int TaskViewModel::completedPomodoros() const
{
	return m_completedPomodoros;
}

void TaskViewModel::setCompletedPomodoros(int count)
{
	if (m_completedPomodoros != count) {
		m_completedPomodoros = count;
		emit completedPomodorosChanged();
	}
}

PriorityType TaskViewModel::priority() const
{
	return m_priority;
}

void TaskViewModel::setPriority(PriorityType type)
{
	if (m_priority != type) {
		m_priority = type;
		emit priorityChanged();
	}
}

QString TaskViewModel::description() const
{
	return m_description;
}

void TaskViewModel::setDescription(const QString &description)
{
	if (m_description != description) {
		m_description = description;
		emit descriptionChanged();
	}
}

QString TaskViewModel::dueDate() const
{
	return m_dueDate;
}

void TaskViewModel::setDueDate(const QString &dueDate)
{
	if (m_dueDate != dueDate) {
		m_dueDate = dueDate;
		emit dueDateChanged();
	}
}
