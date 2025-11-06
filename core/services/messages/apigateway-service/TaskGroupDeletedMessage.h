/**
 * @file TaskGroupDeletedMessage.h
 * @author trung.la
 * @date 11-06-2025
 * @brief Declaration of the TaskGroupDeletedMessage class for handling task group deletion messages.
 */

#ifndef TASKGROUPDELETEDMESSAGE_H
#define TASKGROUPDELETEDMESSAGE_H

#include "core/services/messages/Message.h"
#include "core/services/strategies/IStrategy.h"

#include <ApiGatewayServiceUtils.h>

class TaskGroupDeletedMessage : public Message
{
public:
	using ExtractGroupIdStrategyUPtr = std::unique_ptr<IStrategy<TaskGroupDeletedMessage>>;

	TaskGroupDeletedMessage(ExtractGroupIdStrategyUPtr strategy);
	~TaskGroupDeletedMessage();

	void setGroupId(const std::string &groupId);
	std::string getGroupId() const;

	void execute() override;

private:
	std::string m_groupId;
	ExtractGroupIdStrategyUPtr m_strategy;
};

#endif // TASKGROUPDELETEDMESSAGE_H
