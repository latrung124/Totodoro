/**
 * @file TaskDeletedMessage.cpp
 * @author trung.la
 * @date 11-03-2025
 * @brief This file contains the implementation of the TaskDeletedMessage class.
 */

#include "TaskDeletedMessage.h"

TaskDeletedMessage::TaskDeletedMessage(ExtractTaskDeletedStrategyUPtr strategy)
    : Message(MessageId::TaskDeletedMessage)
    , m_strategy(std::move(strategy))
{
}

TaskDeletedMessage::~TaskDeletedMessage() = default;

void TaskDeletedMessage::setTaskId(const std::string &taskId)
{
	m_taskId = taskId;
}

std::string TaskDeletedMessage::getTaskId() const
{
	return m_taskId;
}

void TaskDeletedMessage::execute()
{
	if (m_strategy) {
		m_strategy->execute(*this);
	}
}
