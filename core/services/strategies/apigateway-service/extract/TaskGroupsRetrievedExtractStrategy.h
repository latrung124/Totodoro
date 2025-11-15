/**
 * @file TaskGroupsRetrievedExtractStrategy.h
 * @author trung.la
 * @date 11-08-2025
 * @brief This file contains the declaration of the TaskGroupsRetrievedExtractStrategy class.
 */

#ifndef TASK_GROUPS_RETRIEVED_EXTRACT_STRATEGY_H
#define TASK_GROUPS_RETRIEVED_EXTRACT_STRATEGY_H

#include "core/services/strategies/IStrategy.h"

class TaskGroupsRetrievedMessage;

class TaskGroupsRetrievedExtractStrategy : public IStrategy<TaskGroupsRetrievedMessage>
{
public:
	~TaskGroupsRetrievedExtractStrategy();
	void execute(const TaskGroupsRetrievedMessage &message) override;

private:
	void extract(const TaskGroupsRetrievedMessage &message);
};

#endif // TASK_GROUPS_RETRIEVED_EXTRACT_STRATEGY_H
