/**
 * @file TaskMessageCreator.h
 * @author trung.la
 * @date 10-31-2025
 * @brief This file contains the declaration of the TaskMessageCreator class.
 */

#ifndef TASK_MESSAGE_CREATOR_H
#define TASK_MESSAGE_CREATOR_H

#include "core/services/producer/ServiceMessageCreator.h"

class TaskMessageCreator : public ServiceMessageCreator
{
public:
	virtual ~TaskMessageCreator() = default;

	ServiceMessageUPtr create(ParamContainerBase *param) const override;
};

#endif // TASK_MESSAGE_CREATOR_H
