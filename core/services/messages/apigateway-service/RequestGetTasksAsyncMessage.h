/**
 * @file RequestGetTasksAsyncMessage.h
 * @author trung.la
 * @date 11-13-2025
 * @brief This file contains the declaration of the RequestGetTasksAsyncMessage class.
 */

#ifndef REQUEST_TASKS_ASYNC_MESSAGE_H
#define REQUEST_TASKS_ASYNC_MESSAGE_H

#include "core/services/messages/Message.h"
#include "core/services/strategies/IStrategy.h"

#include <ApiGatewayServiceUtils.h>

class RequestGetTasksAsyncMessage : public Message
{
public:
	using ExtractTasksStrategyUPtr = std::unique_ptr<IStrategy<RequestGetTasksAsyncMessage>>;

	RequestGetTasksAsyncMessage(ExtractTasksStrategyUPtr strategy);
	~RequestGetTasksAsyncMessage();

	void setUserId(const std::string &userId);
	std::string getUserId() const;

	void setTaskGroupId(const std::string &taskGroupId);
	std::string getTaskGroupId() const;

	void execute() override;

private:
	ExtractTasksStrategyUPtr m_strategy;
	std::string m_userId;
	std::string m_taskGroupId;
};

#endif // REQUEST_TASKS_ASYNC_MESSAGE_H
