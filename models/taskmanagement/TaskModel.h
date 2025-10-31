/**
 * @file TaskModel.h
 * @author trung.la
 * @date 10-31-2025
 * @brief Declaration of the TaskModel class for managing task data.
 */

#ifndef TASKMODEL_H
#define TASKMODEL_H

#include <mutex>
#include <stdint.h>
#include <string>

#include "models/DatabaseModel.h"

class TaskModel : public DatabaseModel
{
public:
	TaskModel();
	~TaskModel() override;

	enum class TaskStatus : uint8_t
	{
		idle = 0,
		pending,
		in_progress,
		completed
	};

	enum class TaskPriority : uint8_t
	{
		low = 0,
		medium,
		high,
	};

	uint16_t getTotalPomodoros() const;
	void setTotalPomodoros(uint16_t totalPomodoros);

	uint16_t getCompletedPomodoros() const;
	void setCompletedPomodoros(uint16_t completedPomodoros);

	uint16_t getProgress() const;
	void setProgress(uint16_t progress);

	std::string getTaskId() const;
	void setTaskId(const std::string &taskId);

	std::string getUserId() const;
	void setUserId(const std::string &userId);

	std::string getGroupId() const;
	void setGroupId(const std::string &groupId);

	std::string getName() const;
	void setName(const std::string &name);

	std::string getDescription() const;
	void setDescription(const std::string &description);

	TaskPriority getPriority() const;
	void setPriority(TaskPriority priority);

	TaskStatus getStatus() const;
	void setStatus(TaskStatus status);

private:
	mutable std::mutex m_mutex;

	uint16_t m_totalPomodoros = 0;
	uint16_t m_completedPomodoros = 0;
	uint16_t m_progress = 0;
	std::string m_taskId;
	std::string m_userId;
	std::string m_groupId;
	std::string m_name;
	std::string m_description;
	TaskPriority m_priority;
	TaskStatus m_status;
};

#endif // TASKMODEL_H
