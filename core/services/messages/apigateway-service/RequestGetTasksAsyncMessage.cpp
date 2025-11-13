/**
 * @file RequestGetTasksAsyncMessage.cpp
 * @author trung.la
 * @date 11-13-2025
 * @brief This file contains the implementation of the RequestGetTasksAsyncMessage class.
 */

#include "RequestGetTasksAsyncMessage.h"

RequestGetTasksAsyncMessage::RequestGetTasksAsyncMessage(ExtractTasksStrategyUPtr strategy)
    : Message(MessageId::RequestGetTasksAsyncMessage)
    , m_strategy(std::move(strategy))
{
}

RequestGetTasksAsyncMessage::~RequestGetTasksAsyncMessage() = default;

void RequestGetTasksAsyncMessage::setUserId(const std::string &userId)
{
	m_userId = userId;
}

std::string RequestGetTasksAsyncMessage::getUserId() const
{
	return m_userId;
}

void RequestGetTasksAsyncMessage::setTaskGroupId(const std::string &taskGroupId)
{
	m_taskGroupId = taskGroupId;
}

std::string RequestGetTasksAsyncMessage::getTaskGroupId() const
{
	return m_taskGroupId;
}

void RequestGetTasksAsyncMessage::execute()
{
	if (m_strategy) {
		m_strategy->execute(*this);
	}
}
