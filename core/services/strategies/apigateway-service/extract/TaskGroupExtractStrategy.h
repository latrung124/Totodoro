/**
 * @file TaskGroupExtractStrategy.h
 * @author trung.la
 * @date 11-01-2025
 * @brief Declaration of the TaskGroupExtractStrategy class for extracting task group data.
 */

#ifndef TASKGROUPEXTRACTSTRATEGY_H
#define TASKGROUPEXTRACTSTRATEGY_H

#include "core/services/strategies/IStrategy.h"

class TaskGroupMessage;

class TaskGroupExtractStrategy : public IStrategy<TaskGroupMessage>
{
public:
	~TaskGroupExtractStrategy();
	void execute(const TaskGroupMessage &message) override;

private:
	void extract(const TaskGroupMessage &message);
};

#endif // TASKGROUPEXTRACTSTRATEGY_H
