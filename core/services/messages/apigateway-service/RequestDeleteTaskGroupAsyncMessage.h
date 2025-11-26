/**
 * @file RequestDeleteTaskGroupAsyncMessage.h
 * @author trung.la
 * @date 11-26-2025
 * @brief This file contains the declaration of the RequestDeleteTaskGroupAsyncMessage class.
 */

#ifndef REQUEST_DELETE_TASK_GROUP_ASYNC_MESSAGE_H
#define REQUEST_DELETE_TASK_GROUP_ASYNC_MESSAGE_H

#include "core/services/messages/Message.h"
#include "core/services/strategies/IStrategy.h"

#include <ApiGatewayServiceUtils.h>

class RequestDeleteTaskGroupAsyncMessage : public Message
{
public:
	using CompressStrategyUPtr = std::unique_ptr<IStrategy<RequestDeleteTaskGroupAsyncMessage>>;

	RequestDeleteTaskGroupAsyncMessage(CompressStrategyUPtr strategy);
	~RequestDeleteTaskGroupAsyncMessage();

	void setTaskGroupId(const std::string &taskGroupId);
	std::string getTaskGroupId() const;

	void execute() override;

private:
	CompressStrategyUPtr m_strategy;
	std::string m_taskGroupId;
};

#endif // REQUEST_DELETE_TASK_GROUP_ASYNC_MESSAGE_H
