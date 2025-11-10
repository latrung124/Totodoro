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
	initDummyData();
}

TaskGroupsViewModel::~TaskGroupsViewModel()
{
}

void TaskGroupsViewModel::initDummyData()
{
	// Initialize dummy data here if needed
	for (int i = 0; i < 10; ++i) {
		auto taskGroup = std::make_shared<TaskGroupViewModel>();
		taskGroup->setTaskGroupId(QString::number(i));
		taskGroup->setIcon("default-task-icon.png");
		taskGroup->setName(QString("Task Group %1").arg(i));
		taskGroup->setDeadline("2025-12-31");
		taskGroup->setPriority(PriorityType::Medium);
		taskGroup->setStatus("In Progress");
		taskGroup->setDescription(QString("This is a description of Task Group %1.").arg(i));
		taskGroup->setCompletedTasks(i);
		taskGroup->setTotalTasks(10);

		m_taskGroups.push_back(taskGroup);
	}
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
	case CompletedTasksRole:
		return taskGroup->completedTasks();
	case TotalTasksRole:
		return taskGroup->totalTasks();
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
	    {CompletedTasksRole, "completedTasks"},
	    {TotalTasksRole, "totalTasks"},
	    {TasksRole, "tasks"}};
}

QVariantMap TaskGroupsViewModel::get(int index) const
{
	// Used for debug on qml
	if (index < 0 || index >= m_taskGroups.size()) {
		return QVariantMap();
	}
	const auto &taskGroup = m_taskGroups[index];
	QVariantMap taskGroupData;
	taskGroupData["taskGroupId"] = taskGroup->taskGroupId();
	taskGroupData["icon"] = taskGroup->icon();
	taskGroupData["name"] = taskGroup->name();
	taskGroupData["deadline"] = taskGroup->deadline();
	taskGroupData["priority"] = static_cast<int>(taskGroup->priority());
	taskGroupData["status"] = taskGroup->status();
	taskGroupData["description"] = taskGroup->description();
	taskGroupData["completedTasks"] = taskGroup->completedTasks();
	taskGroupData["totalTasks"] = taskGroup->totalTasks();
	taskGroupData["tasks"] = QVariant::fromValue(taskGroup->tasks());
	return taskGroupData;
}

void TaskGroupsViewModel::onTaskGroupAppended(const QString &taskGroupId)
{
	// Find the newly added task group from the model and append it to the view model
	// For simplicity, we will just create a new TaskGroupViewModel here
	auto taskGroup = std::make_shared<TaskGroupViewModel>();
	taskGroup->setTaskGroupId(taskGroupId);
	taskGroup->setIcon("default-task-icon.png");
	taskGroup->setName(QString("New Task Group %1").arg(taskGroupId));
	taskGroup->setDeadline("2025-12-31");
	taskGroup->setPriority(PriorityType::Medium);
	taskGroup->setStatus("Not Started");
	taskGroup->setDescription(
	    QString("This is a description of New Task Group %1.").arg(taskGroupId));
	taskGroup->setCompletedTasks(0);
	taskGroup->setTotalTasks(0);

	beginInsertRows(QModelIndex(), m_taskGroups.size(), m_taskGroups.size());
	m_taskGroups.push_back(taskGroup);
	endInsertRows();
}

void TaskGroupsViewModel::onTaskGroupRemoved(const QString &taskGroupId)
{
	// Find and remove the task group from the view model
	for (size_t i = 0; i < m_taskGroups.size(); ++i) {
		if (m_taskGroups[i]->taskGroupId() == taskGroupId) {
			beginRemoveRows(QModelIndex(), static_cast<int>(i), static_cast<int>(i));
			m_taskGroups.erase(m_taskGroups.begin() + i);
			endRemoveRows();
			break;
		}
	}
}

void TaskGroupsViewModel::onTaskGroupUpdated(const QString &taskGroupId)
{
	// TODO: update detail later
	// Find and update the task group in the view model
	for (size_t i = 0; i < m_taskGroups.size(); ++i) {
		if (m_taskGroups[i]->taskGroupId() == taskGroupId) {
			// For simplicity, we will just emit dataChanged for the entire row
			QModelIndex idx = index(static_cast<int>(i));
			emit dataChanged(idx, idx);
			break;
		}
	}
}

void TaskGroupsViewModel::onTaskGroupsCleared()
{
	beginResetModel();
	m_taskGroups.clear();
	endResetModel();
}

TaskGroupsViewModel::TaskGroupViewModelPtr TaskGroupsViewModel::getTaskGroupById(
    const QString &taskGroupId) const
{
	for (const auto &taskGroup : m_taskGroups) {
		if (taskGroup->taskGroupId() == taskGroupId) {
			return taskGroup;
		}
	}
	return nullptr;
}
