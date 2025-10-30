/**
 * @file PomodoroMessage.h
 * @author trung.la
 * @date 10-30-2025
 * @brief This file contains the declaration of the PomodoroMessage class.
 */

#ifndef POMODORO_MESSAGE_H
#define POMODORO_MESSAGE_H

#include "core/services/messages/Message.h"
#include "core/services/strategies/IStrategy.h"

#include <ApiGatewayServiceUtils.h>

class PomodoroMessage : public Message
{
public:
	using Pomodoro = apigateway_service::utils::pomodoro::Session;
	using ExtractPomodoroStrategyUPtr = std::unique_ptr<IStrategy<PomodoroMessage>>;

	PomodoroMessage(ExtractPomodoroStrategyUPtr strategy);
	~PomodoroMessage();

	void setPomodoro(const Pomodoro &session);
	Pomodoro getPomodoro() const;

	void execute() override;

private:
	Pomodoro m_pomodoro;
	ExtractPomodoroStrategyUPtr m_strategy;
};

#endif // POMODORO_MESSAGE_H
