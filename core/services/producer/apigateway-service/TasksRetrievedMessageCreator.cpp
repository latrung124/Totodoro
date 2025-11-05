/**
 * @file TasksRetrievedMessageCreator.cpp
 * @author trung.la
 * @date 11-05-2025
 * @brief This file contains the implementation of the TasksRetrievedMessageCreator class.
 */

#include "core/services/producer/apigateway-service/TasksRetrievedMessageCreator.h"
#include "core/services/messages/apigateway-service/TasksRetrievedMessage.h"
#include "core/services/strategies/apigateway-service/TasksRetrievedExtractStrategy.h"

ServiceMessageUPtr TasksRetrievedMessageCreator::create(ParamContainerBase *param) const
{
	auto *container =
	    dynamic_cast<core::factories::ParamContainer<std::vector<TasksRetrievedMessage::Task>> *>(
	        param);
	if (container == nullptr) {
		return std::make_unique<TasksRetrievedMessage>(
		    std::make_unique<TasksRetrievedExtractStrategy>());
	}

	auto paramTuple = container->getParams();
	auto tasks = std::get<0>(paramTuple);

	auto message = std::make_unique<TasksRetrievedMessage>(
	    std::make_unique<TasksRetrievedExtractStrategy>());
	message->setTasks(tasks);
	return message;
}
