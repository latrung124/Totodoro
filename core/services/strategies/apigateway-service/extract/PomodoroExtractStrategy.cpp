/**
 * @file PomodoroExtractStrategy.cpp
 * @author trung.la
 * @date 10-30-2025
 * @brief This file contains the implementation of the PomodoroExtractStrategy class.
 */

#include "core/services/strategies/apigateway-service/extract/PomodoroExtractStrategy.h"

#include <QDebug>

#include "core/controllers/ModelController.h"
#include "models/session/PomodoroModel.h"

#include "core/services/messages/apigateway-service/PomodoroMessage.h"

PomodoroExtractStrategy::~PomodoroExtractStrategy()
{
}

void PomodoroExtractStrategy::execute(const PomodoroMessage &message)
{
	extract(message);
}

void PomodoroExtractStrategy::extract(const PomodoroMessage &message)
{
	qDebug() << "PomodoroExtractStrategy::extract";
	auto sessionInfo = message.getPomodoro();
	auto model = ModelController::getInstance().getPomodoroModel(); // still in worker thread
	if (auto modelPtr = model.lock()) {
		modelPtr->setSessionId(sessionInfo.sessionId);
		modelPtr->setUserId(sessionInfo.userId);
		modelPtr->setTaskId(sessionInfo.taskId);
		modelPtr->setType(static_cast<PomodoroModel::SessionType>(sessionInfo.type));
		modelPtr->setStatus(static_cast<PomodoroModel::SessionStatus>(sessionInfo.status));
		modelPtr->setProgress(sessionInfo.progress);
		modelPtr->setNumberInCycle(sessionInfo.numberInCycle);
	} else {
		qDebug() << "Failed to lock PomodoroModel";
	}
}
