/*
* File: TasksViewModel.cpp
* Author: trung.la
* Date: 05-01-2025
* Description: View Model for Tasks.
*/

#include "TasksViewModel.h"

#include "view-models/taskmanagement/TaskViewModel.h"

TasksViewModel::TasksViewModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

TasksViewModel::~TasksViewModel()
{
}

int TasksViewModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_tasks.size();
}

QVariant TasksViewModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() < 0 || index.row() >= m_tasks.size()) {
        return QVariant();
    }

    const TaskViewModelPtr &task = m_tasks[index.row()];
    switch (role) {
    case TaskIdRole:
        return task->taskId();
    case TaskNameRole:
        return task->taskName();
    case IconRole:
        return task->icon();
    case TotalPomodorosRole:
        return task->totalPomodoros();
    case CompletedPomodorosRole:
        return task->completedPomodoros();
    case PriorityTypeRole:
        return static_cast<int>(task->priorityType());
    case DescriptionRole:
        return task->description();
    case DeadlineRole:
        return task->deadline();
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> TasksViewModel::roleNames() const
{
    return {
        {TaskIdRole, "taskId"},
        {TaskNameRole, "taskName"},
        {IconRole, "icon"},
        {TotalPomodorosRole, "totalPomodoros"},
        {CompletedPomodorosRole, "completedPomodoros"},
        {PriorityTypeRole, "priorityType"},
        {DescriptionRole, "description"},
        {DeadlineRole, "deadline"}
    };
}