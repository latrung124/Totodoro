/**
 * @file TaskGroupDeletedExtractStrategy.h
 * @author trung.la
 * @date 11-06-2025
 * @brief This file contains the declaration of the TaskGroupDeletedExtractStrategy class.
 */

#ifndef TASK_GROUP_DELETED_EXTRACT_STRATEGY_H
#define TASK_GROUP_DELETED_EXTRACT_STRATEGY_H

#include "core/services/strategies/IStrategy.h"

class TaskGroupDeletedMessage;

class TaskGroupDeletedExtractStrategy : public IStrategy<TaskGroupDeletedMessage>
{
public:
	~TaskGroupDeletedExtractStrategy();
	void execute(const TaskGroupDeletedMessage &message) override;

private:
	void extract(const TaskGroupDeletedMessage &message);
};

#endif // TASK_GROUP_DELETED_EXTRACT_STRATEGY_H
