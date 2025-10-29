/**
 * @file UserSettingsMessageCreator.h
 * @author trung.la
 * @date 10-29-2025
 * @brief This file contains the declaration of the UserSettingsMessageCreator class.
 */

#ifndef USER_SETTINGS_MESSAGE_CREATOR_H
#define USER_SETTINGS_MESSAGE_CREATOR_H

#include "core/services/producer/ServiceMessageCreator.h"

class UserSettingsMessageCreator : public ServiceMessageCreator
{
public:
	virtual ~UserSettingsMessageCreator() = default;

	ServiceMessageUPtr create(ParamContainerBase *param) const override;
};

#endif // USER_SETTINGS_MESSAGE_CREATOR_H
