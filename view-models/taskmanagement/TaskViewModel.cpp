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

int TaskViewModel::taskId() const
{
    return m_taskId;
}

void TaskViewModel::setTaskId(int id)
{
    if (m_taskId != id) {
        m_taskId = id;
        emit taskIdChanged();
    }
}

QString TaskViewModel::taskName() const
{
    return m_taskName;
}

void TaskViewModel::setTaskName(const QString &name)
{
    if (m_taskName != name) {
        m_taskName = name;
        emit taskNameChanged();
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

PriorityType TaskViewModel::priorityType() const
{
    return m_priorityType;
}

void TaskViewModel::setPriorityType(PriorityType type)
{
    if (m_priorityType != type) {
        m_priorityType = type;
        emit priorityTypeChanged();
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

QString TaskViewModel::deadline() const
{
    return m_deadline;
}

void TaskViewModel::setDeadline(const QString &deadline)
{
    if (m_deadline != deadline) {
        m_deadline = deadline;
        emit deadlineChanged();
    }
}