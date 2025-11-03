/**
 * @file TaskDeletedMessageCreator.h
 * @author trung.la
 * @date 11-03-2025
 * @brief This file contains the declaration of the TaskDeletedMessageCreator class.
 */

#ifndef TASK_DELETED_MESSAGE_CREATOR_H
#define TASK_DELETED_MESSAGE_CREATOR_H

#include "core/services/producer/ServiceMessageCreator.h"

class TaskDeletedMessageCreator : public ServiceMessageCreator
{
public:
	virtual ~TaskDeletedMessageCreator() = default;

	ServiceMessageUPtr create(ParamContainerBase *param) const override;
};

#endif // TASK_DELETED_MESSAGE_CREATOR_H
