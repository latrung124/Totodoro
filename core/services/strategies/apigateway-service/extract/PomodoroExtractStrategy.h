/**
 * @file PomodoroExtractStrategy.h
 * @author trung.la
 * @date 10-30-2025
 * @brief This file contains the declaration of the PomodoroExtractStrategy class.
 */

#ifndef POMODORO_EXTRACT_STRATEGY_H
#define POMODORO_EXTRACT_STRATEGY_H

#include "core/services/strategies/IStrategy.h"

class PomodoroMessage;

class PomodoroExtractStrategy : public IStrategy<PomodoroMessage>
{
public:
	~PomodoroExtractStrategy();
	void execute(const PomodoroMessage &message) override;

private:
	void extract(const PomodoroMessage &message);
};

#endif // POMODORO_EXTRACT_STRATEGY_H
