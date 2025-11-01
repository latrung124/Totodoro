/**
 * @file TaskGroupMessageCreator.h
 * @author trung.la
 * @date 11-01-2025
 * @brief This file contains the declaration of the TaskGroupMessageCreator class.
 */

#ifndef TASK_GROUP_MESSAGE_CREATOR_H
#define TASK_GROUP_MESSAGE_CREATOR_H

#include "core/services/producer/ServiceMessageCreator.h"

class TaskGroupMessageCreator : public ServiceMessageCreator
{
public:
	virtual ~TaskGroupMessageCreator() = default;

	ServiceMessageUPtr create(ParamContainerBase *param) const override;
};

#endif // TASK_GROUP_MESSAGE_CREATOR_H
