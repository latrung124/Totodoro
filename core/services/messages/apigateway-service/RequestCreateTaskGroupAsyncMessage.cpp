/**
 * @file RequestCreateTaskGroupAsyncMessage.cpp
 * @author trung.la
 * @date 11-26-2025
 * @brief This file contains the implementation of the RequestCreateTaskGroupAsyncMessage class.
 */

#include "core/services/messages/apigateway-service/RequestCreateTaskGroupAsyncMessage.h"

RequestCreateTaskGroupAsyncMessage::RequestCreateTaskGroupAsyncMessage(CompressStrategyUPtr strategy)
    : m_strategy(std::move(strategy))
{
}

RequestCreateTaskGroupAsyncMessage::~RequestCreateTaskGroupAsyncMessage() = default;

void RequestCreateTaskGroupAsyncMessage::setTaskGroup(const TaskGroup &taskGroup)
{
	m_taskGroup = taskGroup;
}

RequestCreateTaskGroupAsyncMessage::TaskGroup RequestCreateTaskGroupAsyncMessage::getTaskGroup() const
{
	return m_taskGroup;
}

void RequestCreateTaskGroupAsyncMessage::execute()
{
	if (m_strategy) {
		m_strategy->execute(*this);
	}
}
