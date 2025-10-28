/**
 * @file UserProfileVMProducer.h
 * @author trung.la
 * @date 10-28-2025
 * @brief This file contains the declaration of the UserProfileVMProducer class.
 */

#ifndef USERPROFILEVMPRODUCER_H
#define USERPROFILEVMPRODUCER_H

#include "core/factories/view-model-producers/ViewModelProducer.h"

class UserProfileVMProducer : public ViewModelProducer
{
public:
	UserProfileVMProducer() = default;
	~UserProfileVMProducer() = default;

	std::unique_ptr<QObject> createViewModel(ParamContainerBase *params = nullptr) override;
};

#endif // USERPROFILEVMPRODUCER_H
