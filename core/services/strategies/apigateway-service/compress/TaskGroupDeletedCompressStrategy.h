/**
 * @file TaskGroupDeletedCompressStrategy.h
 * @author trung.la
 * @date 11-26-2025
 * @brief This file contains the declaration of the TaskGroupDeletedCompressStrategy class.
 */

#ifndef TASK_GROUP_DELETED_COMPRESS_STRATEGY_H
#define TASK_GROUP_DELETED_COMPRESS_STRATEGY_H

#include "core/services/strategies/IStrategy.h"

class RequestDeleteTaskGroupAsyncMessage;

class TaskGroupDeletedCompressStrategy : public IStrategy<RequestDeleteTaskGroupAsyncMessage>
{
public:
	~TaskGroupDeletedCompressStrategy();
	void execute(const RequestDeleteTaskGroupAsyncMessage &message) override;

private:
	void compress(const RequestDeleteTaskGroupAsyncMessage &message);
};

#endif // TASK_GROUP_DELETED_COMPRESS_STRATEGY_H
