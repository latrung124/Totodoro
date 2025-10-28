/**
 * @file UserInformationMessageCreator.h
 * @author trung.la
 * @date 10-28-2025
 * @brief This file contains the declaration of the UserInformationMessageCreator class.
 */

#ifndef USER_INFORMATION_MESSAGE_CREATOR_H
#define USER_INFORMATION_MESSAGE_CREATOR_H

#include "core/services/producer/ServiceMessageCreator.h"

class UserInformationMessageCreator : public ServiceMessageCreator
{
public:
	virtual ~UserInformationMessageCreator() = default;

	ServiceMessageUPtr create(ParamContainerBase *param) const override;
};

#endif // USER_INFORMATION_MESSAGE_CREATOR_H
