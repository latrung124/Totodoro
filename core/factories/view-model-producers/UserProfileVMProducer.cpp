/**
 * @file UserProfileVMProducer.cpp
 * @author trung.la
 * @date 10-28-2025
 * @brief This file contains the implementation of the UserProfileVMProducer class.
 */

#include "UserProfileVMProducer.h"

#include "view-models/userprofile/UserProfileViewModel.h"

std::unique_ptr<QObject> UserProfileVMProducer::createViewModel(ParamContainerBase *params)
{
	return std::make_unique<UserProfileViewModel>();
}
