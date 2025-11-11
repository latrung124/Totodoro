/**
 * @file TasksModel.cpp
 * @author trung.la
 * @date 11-11-2025
 * @brief Implementation of the TasksModel class for managing the task list.
 */

#include "TasksModel.h"

#include <QMetaObject>
#include <QString>

#include "TaskModel.h"
#include "view-models/taskmanagement/TasksViewModel.h"

#include "core/controllers/ViewModelController.h"

TasksModel::TasksModel()
{
}

bool TasksModel::appendTask(const TaskModelPtr &task)
{
	if (!task) {
		return false;
	}

	std::lock_guard<std::mutex> lock(m_mutex);
	for (const auto &existingTask : m_tasks) {
		if (existingTask->getTaskId() == task->getTaskId()) {
			return false; // Task with the same ID already exists
		}
	}
	m_tasks.push_back(task);

	auto viewModel = ViewModelController::getInstance().tasksViewModel();
	if (viewModel) {
		QMetaObject::invokeMethod(
		    viewModel, "onTaskAppended", Q_ARG(QString, QString::fromStdString(task->getTaskId())));
	}
	return true;
}

bool TasksModel::removeTask(const std::string &taskId)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	auto it = std::remove_if(m_tasks.begin(), m_tasks.end(), [&taskId](const TaskModelPtr &task) {
		return task->getTaskId() == taskId;
	});
	if (it != m_tasks.end()) {
		m_tasks.erase(it, m_tasks.end());

		auto viewModel = ViewModelController::getInstance().tasksViewModel();
		if (viewModel) {
			QMetaObject::invokeMethod(
			    viewModel, "onTaskRemoved", Q_ARG(QString, QString::fromStdString(taskId)));
		}
		return true;
	}
	return false;
}

bool TasksModel::updateTask(const TaskModelPtr &task)
{
	if (!task) {
		return false;
	}

	std::lock_guard<std::mutex> lock(m_mutex);
	for (auto &existingTask : m_tasks) {
		const auto &taskId = task->getTaskId();
		if (existingTask->getTaskId() == taskId) {
			existingTask = std::move(task);

			auto viewModel = ViewModelController::getInstance().tasksViewModel();
			if (viewModel) {
				QMetaObject::invokeMethod(
				    viewModel, "onTaskUpdated", Q_ARG(QString, QString::fromStdString(taskId)));
			}
			return true;
		} else {
			return false;
		}
	}
	return false; // Task with the specified ID not found
}

void TasksModel::clearTasks()
{
	std::lock_guard<std::mutex> lock(m_mutex);
	m_tasks.clear();

	auto viewModel = ViewModelController::getInstance().tasksViewModel();
	if (viewModel) {
		QMetaObject::invokeMethod(viewModel, "onTasksCleared");
	}
}

std::vector<TasksModel::TaskModelPtr> TasksModel::getAllTasks() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_tasks;
}
