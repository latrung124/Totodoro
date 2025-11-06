/**
 * @file TaskGroupDeletedMessage.cpp
 * @author trung.la
 * @date 11-06-2025
 * @brief Implementation of the TaskGroupDeletedMessage class for handling task group deletion messages.
 */

#include "core/services/producer/apigateway-service/TaskGroupDeletedMessageCreator.h"
#include "core/services/messages/apigateway-service/TaskGroupDeletedMessage.h"
#include "core/services/strategies/apigateway-service/TaskGroupDeletedExtractStrategy.h"

ServiceMessageUPtr TaskGroupDeletedMessageCreator::create(ParamContainerBase *param) const
{
	auto *container = dynamic_cast<core::factories::ParamContainer<std::string> *>(param);
	if (container == nullptr) {
		return std::make_unique<TaskGroupDeletedMessage>(
		    std::make_unique<TaskGroupDeletedExtractStrategy>());
	}

	auto paramTuple = container->getParams();
	auto taskGroupId = std::get<0>(paramTuple);

	auto message = std::make_unique<TaskGroupDeletedMessage>(
	    std::make_unique<TaskGroupDeletedExtractStrategy>());
	if (message) {
		message->setGroupId(taskGroupId);
	}
	return message;
}
