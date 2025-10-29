/**
 * @file UserSettingsVMProducer.cpp
 * @author trung.la
 * @date 10-29-2025
 * @brief This file contains the implementation of the UserSettingsVMProducer class.
 */

#include "UserSettingsVMProducer.h"

#include "view-models/userprofile/UserSettingsViewModel.h"

std::unique_ptr<QObject> UserSettingsVMProducer::createViewModel(ParamContainerBase *params)
{
	return std::make_unique<UserSettingsViewModel>();
}
