/**
 * @file TaskGroupMessageCreator.cpp
 * @author trung.la
 * @date 11-01-2025
 * @brief Implementation of the TaskGroupMessageCreator class.
 */

#include "core/services/producer/apigateway-service/TaskGroupMessageCreator.h"
#include "core/services/messages/apigateway-service/TaskGroupMessage.h"
#include "core/services/strategies/apigateway-service/TaskGroupExtractStrategy.h"

ServiceMessageUPtr TaskGroupMessageCreator::create(ParamContainerBase *param) const
{
	auto *container = dynamic_cast<core::factories::ParamContainer<TaskGroupMessage::TaskGroup> *>(
	    param);
	if (container == nullptr) {
		return std::make_unique<TaskGroupMessage>(std::make_unique<TaskGroupExtractStrategy>());
	}

	const auto &taskGroup = container->getParam();

	auto message = std::make_unique<TaskGroupMessage>(std::make_unique<TaskGroupExtractStrategy>());
	message->setTaskGroup(taskGroup);
	return message;
}
