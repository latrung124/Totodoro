/**
 * @file TaskDeletedCompressStrategy.h
 * @author trung.la
 * @date 11-23-2025
 * @brief This file contains the declaration of the TaskDeletedCompressStrategy class.
 */

#ifndef TASK_DELETED_COMPRESS_STRATEGY_H
#define TASK_DELETED_COMPRESS_STRATEGY_H

#include "core/services/strategies/IStrategy.h"

class RequestDeleteTaskAsyncMessage;

class TaskDeletedCompressStrategy : public IStrategy<RequestDeleteTaskAsyncMessage>
{
public:
	~TaskDeletedCompressStrategy();
	void execute(const RequestDeleteTaskAsyncMessage &message) override;

private:
	void compress(const RequestDeleteTaskAsyncMessage &message);
};

#endif // TASK_DELETED_COMPRESS_STRATEGY_H
