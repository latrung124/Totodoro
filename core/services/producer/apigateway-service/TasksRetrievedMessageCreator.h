/**
 * @file TasksRetrievedMessageCreator.h
 * @author trung.la
 * @date 11-05-2025
 * @brief This file contains the declaration of the TasksRetrievedMessageCreator class.
 */

#ifndef TASKS_RETRIEVED_MESSAGE_CREATOR_H
#define TASKS_RETRIEVED_MESSAGE_CREATOR_H

#include "core/services/producer/ServiceMessageCreator.h"

class TasksRetrievedMessageCreator : public ServiceMessageCreator
{
public:
	virtual ~TasksRetrievedMessageCreator() = default;

	ServiceMessageUPtr create(ParamContainerBase *param) const override;
};

#endif // TASKS_RETRIEVED_MESSAGE_CREATOR_H
