/**
 * @file TasksRetrievedMessage.h
 * @author trung.la
 * @date 11-05-2025
 * @brief This file contains the declaration of the TasksRetrievedMessage class.
 */

#ifndef TASKS_RETRIEVED_MESSAGE_H
#define TASKS_RETRIEVED_MESSAGE_H

#include <vector>

#include "core/services/messages/Message.h"
#include "core/services/strategies/IStrategy.h"

#include <ApiGatewayServiceUtils.h>

class TasksRetrievedMessage : public Message
{
public:
	using Task = apigateway_service::utils::task_management::Task;
	using Tasks = std::vector<Task>;
	using ExtractTasksStrategyUPtr = std::unique_ptr<IStrategy<TasksRetrievedMessage>>;

	TasksRetrievedMessage(ExtractTasksStrategyUPtr strategy);
	~TasksRetrievedMessage();

	void setTasks(const Tasks &tasks);
	Tasks getTasks() const;

	void execute() override;

private:
	Tasks m_tasks;
	ExtractTasksStrategyUPtr m_strategy;
};

#endif // TASKS_RETRIEVED_MESSAGE_H
