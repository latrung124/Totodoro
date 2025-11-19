/**
 * @file RequestCreateTaskAsyncMessage.cpp
 * @author trung.la
 * @date 11-19-2025
 * @brief This file contains the implementation of the RequestCreateTaskAsyncMessage class.
 */

#include "core/services/messages/apigateway-service/RequestCreateTaskAsyncMessage.h"

RequestCreateTaskAsyncMessage::RequestCreateTaskAsyncMessage(CompressStrategyUPtr strategy)
    : m_strategy(std::move(strategy))
{
}

RequestCreateTaskAsyncMessage::~RequestCreateTaskAsyncMessage() = default;

void RequestCreateTaskAsyncMessage::setTask(const Task &task)
{
	m_task = task;
}

RequestCreateTaskAsyncMessage::Task RequestCreateTaskAsyncMessage::getTask() const
{
	return m_task;
}

void RequestCreateTaskAsyncMessage::execute()
{
	if (m_strategy) {
		m_strategy->execute(*this);
	}
}
