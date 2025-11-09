/**
 * @file PomodoroMessageCreator.cpp
 * @author trung.la
 * @date 11-09-2025
 * @brief This file contains the implementation of the PomodoroMessageCreator class.
 */

#include "core/services/producer/apigateway-service/PomodoroMessageCreator.h"
#include "core/services/messages/apigateway-service/PomodoroMessage.h"
#include "core/services/strategies/apigateway-service/PomodoroExtractStrategy.h"

ServiceMessageUPtr PomodoroMessageCreator::create(ParamContainerBase *param) const
{
	auto *container = dynamic_cast<core::factories::ParamContainer<PomodoroMessage::Pomodoro> *>(
	    param);
	if (container == nullptr) {
		return std::make_unique<PomodoroMessage>(std::make_unique<PomodoroExtractStrategy>());
	}

	auto pomodoro = container->getParam();

	auto message = std::make_unique<PomodoroMessage>(std::make_unique<PomodoroExtractStrategy>());
	if (message) {
		message->setPomodoro(pomodoro);
	}
	return message;
}
