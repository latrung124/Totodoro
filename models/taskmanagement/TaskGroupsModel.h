/**
 * @file TaskGroupsModel.h
 * @author trung.la
 * @date 11-10-2025
 * @brief Declaration of the TaskGroupsModel class for representing multiple task groups.
 */

#ifndef TASKGROUPSMODEL_H
#define TASKGROUPSMODEL_H

#include "models/DatabaseModel.h"

#include <memory>
#include <mutex>
#include <string>
#include <vector>

class TaskGroupModel;

class TaskGroupsModel : public DatabaseModel
{
public:
	using TaskGroupModelPtr = std::shared_ptr<TaskGroupModel>;

	explicit TaskGroupsModel();
	~TaskGroupsModel() = default;

	bool appendTaskGroup(const TaskGroupModelPtr &taskGroup);
	bool removeTaskGroup(const std::string &groupId);
	bool updateTaskGroup(const TaskGroupModelPtr &taskGroup);
	void clearTaskGroups();

	std::vector<TaskGroupModelPtr> getAllTaskGroups() const;

private:
	mutable std::mutex m_mutex;
	std::vector<TaskGroupModelPtr> m_taskGroups;
};
#endif // TASKGROUPSMODEL_H
