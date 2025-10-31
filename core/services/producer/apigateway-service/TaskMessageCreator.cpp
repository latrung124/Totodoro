/**
 * @file TaskMessageCreator.cpp
 * @author trung.la
 * @date 10-31-2025
 * @brief This file contains the implementation of the TaskMessageCreator class.
 */

#include "core/services/producer/apigateway-service/TaskMessageCreator.h"
#include "core/services/messages/apigateway-service/TaskMessage.h"
#include "core/services/strategies/apigateway-service/TaskExtractStrategy.h"

ServiceMessageUPtr TaskMessageCreator::create(ParamContainerBase *param) const
{
	auto *container = dynamic_cast<core::factories::ParamContainer<TaskMessage::Task> *>(param);
	if (container == nullptr) {
		return std::make_unique<TaskMessage>(std::make_unique<TaskExtractStrategy>());
	}

	auto paramTuple = container->getParams();
	auto task = std::get<0>(paramTuple);

	auto message = std::make_unique<TaskMessage>(std::make_unique<TaskExtractStrategy>());
	message->setTask(task);
	return message;
}
