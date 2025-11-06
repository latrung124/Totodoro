/**
 * @file TaskGroupDeletedMessage.cpp
 * @author trung.la
 * @date 11-06-2025
 * @brief Implementation of the TaskGroupDeletedMessage class for handling task group deletion messages.
 */

#include "TaskGroupDeletedMessage.h"

TaskGroupDeletedMessage::TaskGroupDeletedMessage(ExtractGroupIdStrategyUPtr strategy)
    : Message(MessageId::TaskGroupDeletedMessage)
    , m_strategy(std::move(strategy))
{
}

TaskGroupDeletedMessage::~TaskGroupDeletedMessage() = default;

void TaskGroupDeletedMessage::setGroupId(const std::string &groupId)
{
	m_groupId = groupId;
}

std::string TaskGroupDeletedMessage::getGroupId() const
{
	return m_groupId;
}

void TaskGroupDeletedMessage::execute()
{
	if (m_strategy) {
		m_strategy->execute(*this);
	}
}
