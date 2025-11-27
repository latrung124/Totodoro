/**
 * @file TaskGroupUpdatedCompressStrategy.h
 * @author trung.la
 * @date 11-27-2025
 * @brief This file contains the declaration of the TaskGroupUpdatedCompressStrategy class.
 */

#ifndef TASK_GROUP_UPDATED_COMPRESS_STRATEGY_H
#define TASK_GROUP_UPDATED_COMPRESS_STRATEGY_H

#include "core/services/strategies/IStrategy.h"

class RequestUpdateTaskGroupAsyncMessage;

class TaskGroupUpdatedCompressStrategy : public IStrategy<RequestUpdateTaskGroupAsyncMessage>
{
public:
	~TaskGroupUpdatedCompressStrategy();
	void execute(const RequestUpdateTaskGroupAsyncMessage &message) override;

private:
	void compress(const RequestUpdateTaskGroupAsyncMessage &message);
};

#endif // TASK_GROUP_UPDATED_COMPRESS_STRATEGY_H
