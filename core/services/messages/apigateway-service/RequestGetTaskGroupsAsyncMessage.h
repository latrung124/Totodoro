/**
 * @file RequestGetTaskGroupsAsyncMessage.h
 * @author trung.la
 * @date 11-27-2025
 * @brief This file contains the declaration of the RequestGetTaskGroupsAsyncMessage class.
 */

#ifndef REQUEST_GET_TASK_GROUPS_ASYNC_MESSAGE_H
#define REQUEST_GET_TASK_GROUPS_ASYNC_MESSAGE_H

#include "core/services/messages/Message.h"
#include "core/services/strategies/IStrategy.h"

#include <ApiGatewayServiceUtils.h>

class RequestGetTaskGroupsAsyncMessage : public Message
{
public:
	using CompressStrategyUPtr = std::unique_ptr<IStrategy<RequestGetTaskGroupsAsyncMessage>>;

	RequestGetTaskGroupsAsyncMessage(CompressStrategyUPtr strategy);
	~RequestGetTaskGroupsAsyncMessage();

	void setUserId(const std::string &userId);
	std::string getUserId() const;

	void execute() override;

private:
	CompressStrategyUPtr m_strategy;
	std::string m_userId;
};

#endif // REQUEST_GET_TASK_GROUPS_ASYNC_MESSAGE_H
