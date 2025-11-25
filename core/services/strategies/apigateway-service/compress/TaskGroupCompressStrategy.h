/**
 * @file TaskGroupCompressStrategy.h
 * @author trung.la
 * @date 11-26-2025
 * @brief This file contains the declaration of the TaskGroupCompressStrategy class.
 */

#ifndef TASK_GROUP_COMPRESS_STRATEGY_H
#define TASK_GROUP_COMPRESS_STRATEGY_H

#include "core/services/strategies/IStrategy.h"

class RequestCreateTaskGroupAsyncMessage;

class TaskGroupCompressStrategy : public IStrategy<RequestCreateTaskGroupAsyncMessage>
{
public:
	~TaskGroupCompressStrategy();
	void execute(const RequestCreateTaskGroupAsyncMessage &message) override;

private:
	void compress(const RequestCreateTaskGroupAsyncMessage &message);
};

#endif // TASK_GROUP_COMPRESS_STRATEGY_H
