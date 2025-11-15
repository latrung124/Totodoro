/**
 * @file TaskExtractStrategy.h
 * @author trung.la
 * @date 10-31-2025
 * @brief Declaration of the TaskExtractStrategy class for extracting task data.
 */

#ifndef TASKEXTRACTSTRATEGY_H
#define TASKEXTRACTSTRATEGY_H

#include "core/services/strategies/IStrategy.h"

class TaskMessage;

class TaskExtractStrategy : public IStrategy<TaskMessage>
{
public:
	~TaskExtractStrategy();
	void execute(const TaskMessage &message) override;

private:
	void extract(const TaskMessage &message);
};

#endif // TASKEXTRACTSTRATEGY_H
