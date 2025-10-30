/**
 * @file PomodoroMessage.cpp
 * @author trung.la
 * @date 10-30-2025
 * @brief This file contains the implementation of the PomodoroMessage class.
 */

#include "PomodoroMessage.h"

namespace {
using namespace apigateway_service::utils::pomodoro;
}

PomodoroMessage::PomodoroMessage(ExtractPomodoroStrategyUPtr strategy)
    : Message(MessageId::PomodoroMessage)
    , m_strategy(std::move(strategy))
{
}

PomodoroMessage::~PomodoroMessage() = default;

void PomodoroMessage::setPomodoro(const Pomodoro &session)
{
	m_pomodoro = session;
}

PomodoroMessage::Pomodoro PomodoroMessage::getPomodoro() const
{
	return m_pomodoro;
}

void PomodoroMessage::execute()
{
	if (m_strategy) {
		m_strategy->execute(*this);
	}
}
