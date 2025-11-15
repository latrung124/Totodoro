/**
 * @file TasksRetrievedCompressStrategy.h
 * @author trung.la
 * @date 11-13-2025
 * @brief This file contains the declaration of the TasksRetrievedCompressStrategy class.
 */

#ifndef REQUEST_GET_TASKS_ASYNC_EXTRACT_STRATEGY_H
#define REQUEST_GET_TASKS_ASYNC_EXTRACT_STRATEGY_H

#include "core/services/strategies/IStrategy.h"

class RequestGetTasksAsyncMessage;

class TasksRetrievedCompressStrategy : public IStrategy<RequestGetTasksAsyncMessage>
{
public:
	~TasksRetrievedCompressStrategy();
	void execute(const RequestGetTasksAsyncMessage &message) override;

private:
	void extract(const RequestGetTasksAsyncMessage &message);
};

#endif // REQUEST_GET_TASKS_ASYNC_EXTRACT_STRATEGY_H
