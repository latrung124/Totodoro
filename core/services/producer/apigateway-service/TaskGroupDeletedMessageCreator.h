/**
 * @file TaskGroupDeletedMessage.h
 * @author trung.la
 * @date 11-06-2025
 * @brief This file contains the declaration of the TaskGroupDeletedMessageCreator class.
 */

#ifndef TASK_GROUP_DELETED_MESSAGE_CREATOR_H
#define TASK_GROUP_DELETED_MESSAGE_CREATOR_H

#include "core/services/producer/ServiceMessageCreator.h"

class TaskGroupDeletedMessageCreator : public ServiceMessageCreator
{
public:
	virtual ~TaskGroupDeletedMessageCreator() = default;

	ServiceMessageUPtr create(ParamContainerBase *param) const override;
};

#endif // TASK_GROUP_DELETED_MESSAGE_CREATOR_H
