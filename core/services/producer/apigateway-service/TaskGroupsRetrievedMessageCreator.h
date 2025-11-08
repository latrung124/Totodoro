/**
 * @file TaskGroupsRetrievedMessageCreator.h
 * @author trung.la
 * @date 11-08-2025
 * @brief This file contains the declaration of the TaskGroupsRetrievedMessageCreator class.
 */

#ifndef TASK_GROUPS_RETRIEVED_MESSAGE_CREATOR_H
#define TASK_GROUPS_RETRIEVED_MESSAGE_CREATOR_H

#include "core/services/producer/ServiceMessageCreator.h"

class TaskGroupsRetrievedMessageCreator : public ServiceMessageCreator
{
public:
	virtual ~TaskGroupsRetrievedMessageCreator() = default;

	ServiceMessageUPtr create(ParamContainerBase *param) const override;
};

#endif // TASK_GROUPS_RETRIEVED_MESSAGE_CREATOR_H
