/**
 * @file TaskGroupModel.h
 * @author trung.la
 * @date 11-01-2025
 * @brief Declaration of the TaskGroupModel class for representing task group data.
 */

#ifndef TASKGROUPMODEL_H
#define TASKGROUPMODEL_H

#include "models/DatabaseModel.h"

#include <mutex>
#include <stdint.h>
#include <string>

class TaskGroupModel : public DatabaseModel
{
public:
	enum class TaskGroupStatus : uint8_t
	{
		idle = 0,
		pending,
		in_progress,
		completed
	};

	enum class TaskGroupPriority : uint8_t
	{
		low = 0,
		medium,
		high
	};

	TaskGroupModel();
	~TaskGroupModel() override;

	// move constructor
	TaskGroupModel(TaskGroupModel &&other) noexcept;
	// move assignment operator
	TaskGroupModel &operator=(TaskGroupModel &&other) noexcept;

	std::string getGroupId() const;
	void setGroupId(const std::string &groupId);

	std::string getUserId() const;
	void setUserId(const std::string &userId);

	std::string getName() const;
	void setName(const std::string &name);

	std::string icon() const;
	void setIcon(const std::string &icon);

	std::string getDescription() const;
	void setDescription(const std::string &description);

	uint16_t getCompletedTasks() const;
	void setCompletedTasks(uint16_t completedTasks);

	uint16_t getTotalTasks() const;
	void setTotalTasks(uint16_t totalTasks);

	TaskGroupPriority getPriority() const;
	void setPriority(TaskGroupPriority priority);

	TaskGroupStatus getStatus() const;
	void setStatus(TaskGroupStatus status);

private:
	mutable std::mutex m_mutex;
	std::string m_groupId;
	std::string m_userId;
	std::string m_name;
	std::string m_icon;
	std::string m_description;
	uint16_t m_completedTasks;
	uint16_t m_totalTasks;
	TaskGroupPriority m_priority;
	TaskGroupStatus m_status;
};

#endif // TASKGROUPMODEL_H
