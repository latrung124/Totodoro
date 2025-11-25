/**
 * @file RequestCreateTaskGroupAsyncMessage.h
 * @author trung.la
 * @date 11-26-2025
 * @brief This file contains the declaration of the RequestCreateTaskGroupAsyncMessage class.
 */

#ifndef REQUEST_CREATE_TASK_GROUP_ASYNC_MESSAGE_H
#define REQUEST_CREATE_TASK_GROUP_ASYNC_MESSAGE_H

#include "core/services/messages/Message.h"
#include "core/services/strategies/IStrategy.h"

#include <ApiGatewayServiceUtils.h>

class RequestCreateTaskGroupAsyncMessage : public Message
{
public:
	using TaskGroup = apigateway_service::utils::task_management::TaskGroup;
	using CompressStrategyUPtr = std::unique_ptr<IStrategy<RequestCreateTaskGroupAsyncMessage>>;

	RequestCreateTaskGroupAsyncMessage(CompressStrategyUPtr strategy);
	~RequestCreateTaskGroupAsyncMessage();

	void setTaskGroup(const TaskGroup &taskGroup);
	TaskGroup getTaskGroup() const;

	void execute() override;

private:
	CompressStrategyUPtr m_strategy;
	TaskGroup m_taskGroup;
};

#endif // REQUEST_CREATE_TASK_GROUP_ASYNC_MESSAGE_H
