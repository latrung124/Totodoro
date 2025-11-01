/**
 * @file TaskGroupMessage.h
 * @author trung.la
 * @date 11-01-2025
 * @brief Declaration of the TaskGroupMessage class for managing task group-related messages.
 */

#ifndef TASKGROUPMESSAGE_H
#define TASKGROUPMESSAGE_H

#include "core/services/messages/Message.h"
#include "core/services/strategies/IStrategy.h"

#include <ApiGatewayServiceUtils.h>

class TaskGroupMessage : public Message
{
public:
	using TaskGroup = apigateway_service::utils::task_management::TaskGroup;
	using ExtractTaskGroupStrategyUPtr = std::unique_ptr<IStrategy<TaskGroupMessage>>;

	TaskGroupMessage(ExtractTaskGroupStrategyUPtr strategy);
	~TaskGroupMessage();

	void setTaskGroup(const TaskGroup &taskGroup);
	TaskGroup getTaskGroup() const;

	void execute() override;

private:
	TaskGroup m_taskGroup;
	ExtractTaskGroupStrategyUPtr m_strategy;
};

#endif // TASKGROUPMESSAGE_H
