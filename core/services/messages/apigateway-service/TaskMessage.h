/**
 * @file TaskMessage.h
 * @author trung.la
 * @date 10-31-2025
 * @brief Declaration of the TaskMessage class for managing task-related messages.
 */

#ifndef TASKMESSAGE_H
#define TASKMESSAGE_H

#include "core/services/messages/Message.h"
#include "core/services/strategies/IStrategy.h"

#include <ApiGatewayServiceUtils.h>

class TaskMessage : public Message
{
public:
	using Task = apigateway_service::utils::task_management::Task;
	using ExtractTaskStrategyUPtr = std::unique_ptr<IStrategy<TaskMessage>>;

	TaskMessage(ExtractTaskStrategyUPtr strategy);
	~TaskMessage();

	void setTask(const Task &task);
	Task getTask() const;

	void execute() override;

private:
	Task m_task;
	ExtractTaskStrategyUPtr m_strategy;
};

#endif // TASKMESSAGE_H
