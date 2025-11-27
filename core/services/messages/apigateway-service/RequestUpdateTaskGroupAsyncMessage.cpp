/**
 * @file RequestUpdateTaskGroupAsyncMessage.cpp
 * @author trung.la
 * @date 11-27-2025
 * @brief This file contains the implementation of the RequestUpdateTaskGroupAsyncMessage class.
 */

#include "RequestUpdateTaskGroupAsyncMessage.h"

RequestUpdateTaskGroupAsyncMessage::RequestUpdateTaskGroupAsyncMessage(CompressStrategyUPtr strategy)
    : Message(MessageId::RequestUpdateTaskGroupAsyncMessage)
    , m_strategy(std::move(strategy))
{
}

RequestUpdateTaskGroupAsyncMessage::~RequestUpdateTaskGroupAsyncMessage() = default;

void RequestUpdateTaskGroupAsyncMessage::setTaskGroup(const TaskGroup &taskGroup)
{
	m_taskGroup = taskGroup;
}

RequestUpdateTaskGroupAsyncMessage::TaskGroup RequestUpdateTaskGroupAsyncMessage::getTaskGroup() const
{
	return m_taskGroup;
}

void RequestUpdateTaskGroupAsyncMessage::execute()
{
	if (m_strategy) {
		m_strategy->execute(*this);
	}
}
