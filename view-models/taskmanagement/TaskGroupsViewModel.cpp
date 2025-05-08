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
	auto taskGroup = std::make_shared<TaskGroupViewModel>();
	taskGroup->setTaskGroupId("1");
	taskGroup->setIcon("icon.png");
	taskGroup->setName("Default Task Group");
	taskGroup->setDeadline("2025-12-31");
	taskGroup->setPriority(PriorityType::Medium);
	taskGroup->setStatus("In Progress");
	taskGroup->setDescription("This is a description of Default Task Group.");

	m_taskGroups.push_back(taskGroup);
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
