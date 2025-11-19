/**
 * @file RequestCreateTaskAsyncMessage.h
 * @author trung.la
 * @date 11-19-2025
 * @brief This file contains the declaration of the RequestCreateTaskAsyncMessage class.
 */

#ifndef REQUEST_CREATE_TASK_ASYNC_MESSAGE_H
#define REQUEST_CREATE_TASK_ASYNC_MESSAGE_H

#include "core/services/messages/Message.h"
#include "core/services/strategies/IStrategy.h"

#include <ApiGatewayServiceUtils.h>

class RequestCreateTaskAsyncMessage : public Message
{
public:
	using Task = apigateway_service::utils::task_management::Task;
	using CompressStrategyUPtr = std::unique_ptr<IStrategy<RequestCreateTaskAsyncMessage>>;

	RequestCreateTaskAsyncMessage(CompressStrategyUPtr strategy);
	~RequestCreateTaskAsyncMessage();

	void setTask(const Task &task);
	Task getTask() const;

	void execute() override;

private:
	CompressStrategyUPtr m_strategy;
	Task m_task;
};

#endif // REQUEST_CREATE_TASK_ASYNC_MESSAGE_H
