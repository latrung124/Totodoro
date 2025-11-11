/**
 * @file TaskGroupsModel.cpp
 * @author trung.la
 * @date 11-10-2025
 * @brief Implementation of the TaskGroupsModel class for managing multiple task groups.
 */

#include "TaskGroupsModel.h"

#include <QMetaObject>
#include <QString>

#include "TaskGroupModel.h"
#include "view-models/taskmanagement/TaskGroupsViewModel.h"
#include "view-models/taskmanagement/TaskGroupViewModel.h"

#include "core/controllers/ViewModelController.h"

TaskGroupsModel::TaskGroupsModel()
{
}

bool TaskGroupsModel::appendTaskGroup(const TaskGroupModelPtr &taskGroup)
{
	if (!taskGroup) {
		return false;
	}

	std::lock_guard<std::mutex> lock(m_mutex);
	for (const auto &existingGroup : m_taskGroups) {
		if (existingGroup->getGroupId() == taskGroup->getGroupId()) {
			return false; // Task group with the same ID already exists
		}
	}
	m_taskGroups.push_back(taskGroup);

	auto viewModel = ViewModelController::getInstance().taskGroupsViewModel();
	if (viewModel) {
		QMetaObject::invokeMethod(
		    viewModel,
		    "onTaskGroupAppended",
		    Q_ARG(QString, QString::fromStdString(taskGroup->getGroupId())));
	}
	return true;
}

bool TaskGroupsModel::removeTaskGroup(const std::string &groupId)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	auto it = std::remove_if(
	    m_taskGroups.begin(), m_taskGroups.end(), [&groupId](const TaskGroupModelPtr &group) {
		    return group->getGroupId() == groupId;
	    });
	if (it != m_taskGroups.end()) {
		m_taskGroups.erase(it, m_taskGroups.end());

		auto viewModel = ViewModelController::getInstance().taskGroupsViewModel();
		if (viewModel) {
			QMetaObject::invokeMethod(
			    viewModel, "onTaskGroupRemoved", Q_ARG(QString, QString::fromStdString(groupId)));
		}
		return true;
	} else {
		return false; // Task group with the specified ID not found
	}
}

bool TaskGroupsModel::updateTaskGroup(const TaskGroupModelPtr &taskGroup)
{
	if (!taskGroup) {
		return false;
	}

	std::lock_guard<std::mutex> lock(m_mutex);
	for (auto &existingGroup : m_taskGroups) {
		if (existingGroup->getGroupId() == taskGroup->getGroupId()) {
			existingGroup = std::move(taskGroup);

			auto viewModel = ViewModelController::getInstance().taskGroupsViewModel();
			if (viewModel) {
				QMetaObject::invokeMethod(
				    viewModel,
				    "onTaskGroupUpdated",
				    Q_ARG(QString, QString::fromStdString(taskGroup->getGroupId())));
			}
			return true;
		}
	}
	return false; // Task group with the specified ID not found
}

void TaskGroupsModel::clearTaskGroups()
{
	std::lock_guard<std::mutex> lock(m_mutex);
	m_taskGroups.clear();

	auto viewModel = ViewModelController::getInstance().taskGroupsViewModel();
	if (viewModel) {
		QMetaObject::invokeMethod(viewModel, "onTaskGroupsCleared");
	}
}
