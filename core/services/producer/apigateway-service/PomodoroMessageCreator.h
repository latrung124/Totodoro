/**
 * @file PomodoroMessageCreator.h
 * @author trung.la
 * @date 11-09-2025
 * @brief This file contains the declaration of the PomodoroMessageCreator class.
 */

#ifndef SESSION_MESSAGE_CREATOR_H
#define SESSION_MESSAGE_CREATOR_H

#include "core/services/producer/ServiceMessageCreator.h"

class PomodoroMessageCreator : public ServiceMessageCreator
{
public:
	virtual ~PomodoroMessageCreator() = default;

	ServiceMessageUPtr create(ParamContainerBase *param) const override;
};

#endif // SESSION_MESSAGE_CREATOR_H
