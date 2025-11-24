/**
 * @file RequestUpdateTaskAsyncMessage.h
 * @author trung.la
 * @date 11-24-2025
 * @brief This file contains the declaration of the RequestUpdateTaskAsyncMessage class.
 */

#ifndef REQUEST_UPDATE_TASK_ASYNC_MESSAGE_H
#define REQUEST_UPDATE_TASK_ASYNC_MESSAGE_H

#include "core/services/messages/Message.h"
#include "core/services/strategies/IStrategy.h"

#include <ApiGatewayServiceUtils.h>

class RequestUpdateTaskAsyncMessage : public Message
{
public:
	using CompressStrategyUPtr = std::unique_ptr<IStrategy<RequestUpdateTaskAsyncMessage>>;
	using Task = apigateway_service::utils::task_management::Task;

	RequestUpdateTaskAsyncMessage(CompressStrategyUPtr strategy);
	~RequestUpdateTaskAsyncMessage();

	void setTask(const Task &task);
	Task getTask() const;

	void execute() override;

private:
	CompressStrategyUPtr m_strategy;
	Task m_task;
};

#endif // REQUEST_UPDATE_TASK_ASYNC_MESSAGE_H
