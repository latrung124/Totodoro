/**
 * @file UserSettingsVMProducer.h
 * @author trung.la
 * @date 10-29-2025
 * @brief This file contains the declaration of the UserSettingsVMProducer class.
 */

#ifndef USERSETTINGSVMPRODUCER_H
#define USERSETTINGSVMPRODUCER_H

#include "core/factories/view-model-producers/ViewModelProducer.h"

class UserSettingsVMProducer : public ViewModelProducer
{
public:
	UserSettingsVMProducer() = default;
	~UserSettingsVMProducer() = default;

	std::unique_ptr<QObject> createViewModel(ParamContainerBase *params = nullptr) override;
};

#endif // USERSETTINGSVMPRODUCER_H
