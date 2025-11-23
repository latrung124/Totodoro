/**
 * @file RequestDeleteTaskAsyncMessage.h
 * @author trung.la
 * @date 11-23-2025
 * @brief This file contains the declaration of the RequestDeleteTaskAsyncMessage class.
 */

#ifndef REQUEST_DELETE_TASK_ASYNC_MESSAGE_H
#define REQUEST_DELETE_TASK_ASYNC_MESSAGE_H

#include "core/services/messages/Message.h"
#include "core/services/strategies/IStrategy.h"

#include <ApiGatewayServiceUtils.h>

class RequestDeleteTaskAsyncMessage : public Message
{
public:
	using CompressStrategyUPtr = std::unique_ptr<IStrategy<RequestDeleteTaskAsyncMessage>>;

	RequestDeleteTaskAsyncMessage(CompressStrategyUPtr strategy);
	~RequestDeleteTaskAsyncMessage();

	void setTaskId(const std::string &taskId);
	std::string getTaskId() const;

	void execute() override;

private:
	CompressStrategyUPtr m_strategy;
	std::string m_taskId;
};

#endif // REQUEST_DELETE_TASK_ASYNC_MESSAGE_H
