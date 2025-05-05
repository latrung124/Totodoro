/*
 * File: HomeVMProducer.cpp
 * Author: trung.la
 * Date: 05-05-2025
 * Description: HomeVMProducer class implementation
 * This class is responsible for creating HomeViewModel instances.
 */

#include "HomeVMProducer.h"

#include "helpers/ParamContainerHelper.h"

#include "view-models/home/HomeViewModel.h"

std::unique_ptr<QObject> HomeVMProducer::createViewModel(ParamContainerBase *params)
{
	Q_UNUSED(params);
	return std::make_unique<HomeViewModel>();
}
