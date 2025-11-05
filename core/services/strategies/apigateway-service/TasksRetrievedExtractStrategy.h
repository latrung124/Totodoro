/**
 * @file TasksRetrievedExtractStrategy.h
 * @author trung.la
 * @date 11-05-2025
 * @brief This file contains the declaration of the TasksRetrievedExtractStrategy class.
 */

#ifndef TASKS_RETRIEVED_EXTRACT_STRATEGY_H
#define TASKS_RETRIEVED_EXTRACT_STRATEGY_H

#include "core/services/strategies/IStrategy.h"

class TasksRetrievedMessage;

class TasksRetrievedExtractStrategy : public IStrategy<TasksRetrievedMessage>
{
public:
	~TasksRetrievedExtractStrategy();
	void execute(const TasksRetrievedMessage &message) override;

private:
	void extract(const TasksRetrievedMessage &message);
};

#endif // TASKS_RETRIEVED_EXTRACT_STRATEGY_H
