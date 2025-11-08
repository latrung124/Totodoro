/**
 * @file TaskGroupsRetrievedMessageCreator.cpp
 * @author trung.la
 * @date 11-08-2025
 * @brief This file contains the implementation of the TaskGroupsRetrievedMessageCreator class.
 */

#include "core/services/producer/apigateway-service/TaskGroupsRetrievedMessageCreator.h"
#include "core/services/messages/apigateway-service/TaskGroupsRetrievedMessage.h"
#include "core/services/strategies/apigateway-service/TaskGroupsRetrievedExtractStrategy.h"

ServiceMessageUPtr TaskGroupsRetrievedMessageCreator::create(ParamContainerBase *param) const
{
	auto *container = dynamic_cast<
	    core::factories::ParamContainer<std::vector<TaskGroupsRetrievedMessage::TaskGroup>> *>(
	    param);
	if (container == nullptr) {
		return std::make_unique<TaskGroupsRetrievedMessage>(
		    std::make_unique<TaskGroupsRetrievedExtractStrategy>());
	}

	const auto &taskGroups = container->getParam();

	auto message = std::make_unique<TaskGroupsRetrievedMessage>(
	    std::make_unique<TaskGroupsRetrievedExtractStrategy>());
	message->setTaskGroups(taskGroups);
	return message;
}
