/**
 * @file TaskDeletedMessageCreator.cpp
 * @author trung.la
 * @date 11-03-2025
 * @brief This file contains the implementation of the TaskDeletedMessageCreator class.
 */

#include "core/services/producer/apigateway-service/TaskDeletedMessageCreator.h"
#include "core/services/messages/apigateway-service/TaskDeletedMessage.h"
#include "core/services/strategies/apigateway-service/extract/TaskDeletedExtractStrategy.h"

ServiceMessageUPtr TaskDeletedMessageCreator::create(ParamContainerBase *param) const
{
	auto *container = dynamic_cast<core::factories::ParamContainer<std::string> *>(param);
	if (container == nullptr) {
		return std::make_unique<TaskDeletedMessage>(std::make_unique<TaskDeletedExtractStrategy>());
	}

	auto taskId = container->getParam();

	auto message = std::make_unique<TaskDeletedMessage>(
	    std::make_unique<TaskDeletedExtractStrategy>());
	if (message) {
		message->setTaskId(taskId);
	}
	return message;
}
