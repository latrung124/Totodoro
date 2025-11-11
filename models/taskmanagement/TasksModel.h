/**
 * @file TasksModel.h
 * @author trung.la
 * @date 11-11-2025
 * @brief Declaration of the TasksModel class for representing the task list.
 */

#ifndef TASKSMODEL_H
#define TASKSMODEL_H

#include "models/DatabaseModel.h"

#include <memory>
#include <mutex>
#include <string>
#include <vector>

class TaskModel;

class TasksModel : public DatabaseModel
{
public:
	using TaskModelPtr = std::shared_ptr<TaskModel>;

	explicit TasksModel();
	~TasksModel() = default;

	bool appendTask(const TaskModelPtr &task);
	bool removeTask(const std::string &taskId);
	bool updateTask(const TaskModelPtr &task);
	void clearTasks();

	std::vector<TaskModelPtr> getAllTasks() const;

private:
	mutable std::mutex m_mutex;
	std::vector<TaskModelPtr> m_tasks;
};

#endif // TASKSMODEL_H
