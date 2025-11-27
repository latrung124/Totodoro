/**
 * @file RequestUpdateTaskGroupAsyncMessage.h
 * @author trung.la
 * @date 11-27-2025
 * @brief This file contains the declaration of the RequestUpdateTaskGroupAsyncMessage class.
 */

#ifndef REQUEST_UPDATE_TASK_GROUP_ASYNC_MESSAGE_H
#define REQUEST_UPDATE_TASK_GROUP_ASYNC_MESSAGE_H

#include "core/services/messages/Message.h"
#include "core/services/strategies/IStrategy.h"

#include <ApiGatewayServiceUtils.h>

class RequestUpdateTaskGroupAsyncMessage : public Message
{
public:
	using CompressStrategyUPtr = std::unique_ptr<IStrategy<RequestUpdateTaskGroupAsyncMessage>>;
	using TaskGroup = apigateway_service::utils::task_management::TaskGroup;

	RequestUpdateTaskGroupAsyncMessage(CompressStrategyUPtr strategy);
	~RequestUpdateTaskGroupAsyncMessage();

	void setTaskGroup(const TaskGroup &taskGroup);
	TaskGroup getTaskGroup() const;

	void execute() override;

private:
	CompressStrategyUPtr m_strategy;
	TaskGroup m_taskGroup;
};

#endif // REQUEST_UPDATE_TASK_GROUP_ASYNC_MESSAGE_H
