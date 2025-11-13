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

void TasksViewModel::init()
{
	// TODO: Request get tasks from BE
}

void TasksViewModel::initDummyData()
{
	for (int i = 0; i < 10; ++i) {
		auto task = std::make_shared<TaskViewModel>();
		task->setId(QString::fromStdString(std::to_string(i)));
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

TasksViewModel::TaskViewModelPtr TasksViewModel::getTaskById(const QString &taskId) const
{
	for (const auto &task : m_tasks) {
		if (task->id() == taskId) {
			return task;
		}
	}
	return nullptr;
}

QVariantMap TasksViewModel::get(int index) const
{
	QVariantMap taskData;
	if (index < 0 || index >= m_tasks.size()) {
		return taskData;
	}

	const auto &task = m_tasks[index];
	taskData["id"] = task->id();
	taskData["name"] = task->name();
	taskData["icon"] = task->icon();
	taskData["totalPomodoros"] = task->totalPomodoros();
	taskData["completedPomodoros"] = task->completedPomodoros();
	taskData["priority"] = static_cast<int>(task->priority());
	taskData["description"] = task->description();
	taskData["dueDate"] = task->dueDate();
	return taskData;
}

void TasksViewModel::onTaskAppended(const QString &taskId)
{
	// For simplicity, we will create a dummy task. In real scenario, fetch task details from model.
	auto task = std::make_shared<TaskViewModel>();
	task->setId(taskId);
	task->setName(QString("New Task %1").arg(taskId));
	task->setIcon("");
	task->setTotalPomodoros(3);
	task->setCompletedPomodoros(0);
	task->setPriority(PriorityType::Low);
	task->setDescription(QString("Description of the new task %1").arg(taskId));
	task->setDueDate("2025-12-31");

	beginInsertRows(QModelIndex(), m_tasks.size(), m_tasks.size());
	m_tasks.push_back(task);
	endInsertRows();
}

void TasksViewModel::onTaskRemoved(const QString &taskId)
{
	for (int i = 0; i < m_tasks.size(); ++i) {
		if (m_tasks[i]->id() == taskId) {
			beginRemoveRows(QModelIndex(), i, i);
			m_tasks.erase(m_tasks.begin() + i);
			endRemoveRows();
			return;
		}
	}
}

void TasksViewModel::onTaskUpdated(const QString &taskId)
{
	for (int i = 0; i < m_tasks.size(); ++i) {
		if (m_tasks[i]->id() == taskId) {
			QModelIndex modelIndex = index(i);
			emit dataChanged(modelIndex, modelIndex);
			return;
		}
	}
}

void TasksViewModel::onTasksCleared()
{
	beginResetModel();
	m_tasks.clear();
	endResetModel();
}
