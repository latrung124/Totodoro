/**
 * @file TaskGroupsRetrievedCompressStrategy.h
 * @author trung.la
 * @date 11-27-2025
 * @brief This file contains the declaration of the TaskGroupsRetrievedCompressStrategy class.
 */

#ifndef TASK_GROUPS_RETRIEVED_COMPRESS_STRATEGY_H
#define TASK_GROUPS_RETRIEVED_COMPRESS_STRATEGY_H

#include "core/services/strategies/IStrategy.h"

class RequestGetTaskGroupsAsyncMessage;

class TaskGroupsRetrievedCompressStrategy : public IStrategy<RequestGetTaskGroupsAsyncMessage>
{
public:
	~TaskGroupsRetrievedCompressStrategy();
	void execute(const RequestGetTaskGroupsAsyncMessage &message) override;

private:
	void compress(const RequestGetTaskGroupsAsyncMessage &message);
};

#endif // TASK_GROUPS_RETRIEVED_COMPRESS_STRATEGY_H
