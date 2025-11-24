/**
 * @file TaskUpdatedCompressStrategy.h
 * @author trung.la
 * @date 11-24-2025
 * @brief This file contains the declaration of the TaskUpdatedCompressStrategy class.
 */

#ifndef TASK_UPDATED_COMPRESS_STRATEGY_H
#define TASK_UPDATED_COMPRESS_STRATEGY_H

#include "core/services/strategies/IStrategy.h"

class RequestUpdateTaskAsyncMessage;

class TaskUpdatedCompressStrategy : public IStrategy<RequestUpdateTaskAsyncMessage>
{
public:
	~TaskUpdatedCompressStrategy();
	void execute(const RequestUpdateTaskAsyncMessage &message) override;

private:
	void compress(const RequestUpdateTaskAsyncMessage &message);
};

#endif // TASK_UPDATED_COMPRESS_STRATEGY_H
