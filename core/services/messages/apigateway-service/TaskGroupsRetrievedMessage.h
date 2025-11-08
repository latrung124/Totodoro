/**
 * @file TaskGroupsRetrievedMessage.h
 * @author trung.la
 * @date 11-08-2025
 * @brief This file contains the declaration of the TaskGroupsRetrievedMessage class.
 */

#ifndef TASK_GROUPS_RETRIEVED_MESSAGE_H
#define TASK_GROUPS_RETRIEVED_MESSAGE_H

#include <vector>

#include "core/services/messages/Message.h"
#include "core/services/strategies/IStrategy.h"

#include <ApiGatewayServiceUtils.h>

class TaskGroupsRetrievedMessage : public Message
{
public:
	using TaskGroup = apigateway_service::utils::task_management::TaskGroup;
	using TaskGroups = std::vector<TaskGroup>;
	using ExtractTaskGroupsStrategyUPtr = std::unique_ptr<IStrategy<TaskGroupsRetrievedMessage>>;

	TaskGroupsRetrievedMessage(ExtractTaskGroupsStrategyUPtr strategy);
	~TaskGroupsRetrievedMessage();

	void setTaskGroups(const TaskGroups &taskGroups);
	TaskGroups getTaskGroups() const;

	void execute() override;

private:
	TaskGroups m_taskGroups;
	ExtractTaskGroupsStrategyUPtr m_strategy;
};

#endif // TASK_GROUPS_RETRIEVED_MESSAGE_H
