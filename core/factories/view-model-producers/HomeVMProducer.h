/*
 * File: HomeVMProducer.h
 * Author: trung.la
 * Date: 05-05-2025
 * Description: HomeVMProducer class definition
 * This class is responsible for creating HomeViewModel instances.
 */

#ifndef HOMEVMPRODUCER_H
#define HOMEVMPRODUCER_H

#include "core/factories/view-model-producers/ViewModelProducer.h"

class HomeVMProducer : public ViewModelProducer
{
public:
	HomeVMProducer() = default;
	~HomeVMProducer() = default;

	std::unique_ptr<QObject> createViewModel(ParamContainerBase *params = nullptr) override;
};

#endif // HOMEVMPRODUCER_H
