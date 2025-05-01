/*
* File: TaskGroupsViewModel.cpp
* Author: trung.la
* Date: 04-30-2025
* Description: View Model for TaskGroups.
*/

#include "TaskGroupsViewModel.h"

#include <QVariant>

#include "view-models/taskmanagement/TaskGroupViewModel.h"

TaskGroupsViewModel::TaskGroupsViewModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

TaskGroupsViewModel::~TaskGroupsViewModel()
{
}

int TaskGroupsViewModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_taskGroups.size();
}

QVariant TaskGroupsViewModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() < 0 || index.row() >= m_taskGroups.size()) {
        return QVariant();
    }

    const auto &taskGroup = m_taskGroups[index.row()];
    switch (role) {
        case TaskGroupIdRole:
            return taskGroup->taskGroupId();
        case IconRole:
            return taskGroup->icon();
        case NameRole:
            return taskGroup->name();
        case DeadlineRole:
            return taskGroup->deadline();
        case PriorityRole:
            return static_cast<int>(taskGroup->priority());
        case StatusRole:
            return taskGroup->status();
        case DescriptionRole:
            return taskGroup->description();
        case TaskCompletedRole:
            return taskGroup->taskCompleted();
        case TotalTaskRole:
            return taskGroup->totalTask();
        case TasksRole:
            return QVariant::fromValue(taskGroup->tasks());
        default:
            return QVariant();
    }
}

QHash<int, QByteArray> TaskGroupsViewModel::roleNames() const
{
    return {
        {TaskGroupIdRole, "taskGroupId"},
        {IconRole, "icon"},
        {NameRole, "name"},
        {DeadlineRole, "deadline"},
        {PriorityRole, "priority"},
        {StatusRole, "status"},
        {DescriptionRole, "description"},
        {TaskCompletedRole, "taskCompleted"},
        {TotalTaskRole, "totalTask"},
        {TasksRole, "tasks"}
    };
}
