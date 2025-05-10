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
	initDummyData();
}

TasksViewModel::~TasksViewModel()
{
}

void TasksViewModel::initDummyData()
{
	for (int i = 0; i < 10; ++i) {
		auto task = std::make_shared<TaskViewModel>();
		task->setId(i);
		task->setName(QString("Task %1").arg(i));
		task->setIcon("");
		task->setTotalPomodoros(5);
		task->setCompletedPomodoros(2);
		task->setPriority(PriorityType::Medium);
		task->setDescription(QString("Description of the task %1").arg(i));
		task->setDueDate("2025-01-01");

		m_tasks.push_back(task);
	}
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
	case IdRole:
		return task->id();
	case NameRole:
		return task->name();
	case IconRole:
		return task->icon();
	case TotalPomodorosRole:
		return task->totalPomodoros();
	case CompletedPomodorosRole:
		return task->completedPomodoros();
	case PriorityRole:
		return static_cast<int>(task->priority());
	case DescriptionRole:
		return task->description();
	case DueDateRole:
		return task->dueDate();
	default:
		return QVariant();
	}
}

QHash<int, QByteArray> TasksViewModel::roleNames() const
{
	return {
	    {IdRole, "id"},
	    {NameRole, "name"},
	    {IconRole, "icon"},
	    {TotalPomodorosRole, "totalPomodoros"},
	    {CompletedPomodorosRole, "completedPomodoros"},
	    {PriorityRole, "priority"},
	    {DescriptionRole, "description"},
	    {DueDateRole, "dueDate"},
	};
}
