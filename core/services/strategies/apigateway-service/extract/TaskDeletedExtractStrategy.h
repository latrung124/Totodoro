/**
 * @file TaskDeletedExtractStrategy.h
 * @author trung.la
 * @date 11-03-2025
 * @brief This file contains the declaration of the TaskDeletedExtractStrategy class.
 */

#ifndef TASK_DELETED_EXTRACT_STRATEGY_H
#define TASK_DELETED_EXTRACT_STRATEGY_H

#include "core/services/strategies/IStrategy.h"

class TaskDeletedMessage;

class TaskDeletedExtractStrategy : public IStrategy<TaskDeletedMessage>
{
public:
	~TaskDeletedExtractStrategy();
	void execute(const TaskDeletedMessage &message) override;

private:
	void extract(const TaskDeletedMessage &message);
};

#endif // TASK_DELETED_EXTRACT_STRATEGY_H
