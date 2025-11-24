/**
 * @file RequestUpdateTaskAsyncMessage.cpp
 * @author trung.la
 * @date 11-24-2025
 * @brief This file contains the implementation of the RequestUpdateTaskAsyncMessage class.
 */

#include "RequestUpdateTaskAsyncMessage.h"

RequestUpdateTaskAsyncMessage::RequestUpdateTaskAsyncMessage(CompressStrategyUPtr strategy)
    : Message(MessageId::RequestUpdateTaskAsyncMessage)
    , m_strategy(std::move(strategy))
{
}

RequestUpdateTaskAsyncMessage::~RequestUpdateTaskAsyncMessage() = default;

void RequestUpdateTaskAsyncMessage::setTask(const Task &task)
{
	m_task = task;
}

RequestUpdateTaskAsyncMessage::Task RequestUpdateTaskAsyncMessage::getTask() const
{
	return m_task;
}

void RequestUpdateTaskAsyncMessage::execute()
{
	if (m_strategy) {
		m_strategy->execute(*this);
	}
}
