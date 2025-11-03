/**
 * @file TaskDeletedMessage.h
 * @author trung.la
 * @date 11-03-2025
 * @brief This file contains the declaration of the TaskDeletedMessage class.
 */

#ifndef TASK_DELETED_MESSAGE_H
#define TASK_DELETED_MESSAGE_H

#include "core/services/messages/Message.h"
#include "core/services/strategies/IStrategy.h"

#include <ApiGatewayServiceUtils.h>

class TaskDeletedMessage : public Message
{
public:
	using ExtractTaskDeletedStrategyUPtr = std::unique_ptr<IStrategy<TaskDeletedMessage>>;

	TaskDeletedMessage(ExtractTaskDeletedStrategyUPtr strategy);
	~TaskDeletedMessage();

	void setTaskId(const std::string &taskId);
	std::string getTaskId() const;

	void execute() override;

private:
	std::string m_taskId;
	ExtractTaskDeletedStrategyUPtr m_strategy;
};

#endif // TASK_DELETED_MESSAGE_H
