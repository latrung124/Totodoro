/*
 * File: ViewModelProducer.h
 * Author: trung.la
 * Date: 04-26-2025
 * Description: ViewModelProducer class definition
 * This class is responsible for producing ViewModel instances based on the provided parameters.
 */

#ifndef VIEWMODELPRODUCER_H
#define VIEWMODELPRODUCER_H

#include <memory>

#include "core/factories/ParamContainer.h"
#include "view-models/ViewModel.h"

class ViewModelProducer
{
public:
	using ParamContainerBase = core::factories::ParamContainerBase;

	virtual ~ViewModelProducer() = default;

	/**
	 * @brief Creates a ViewModel instance based on the provided parameters.
	 * @param params A pointer to a tuple, ParamContainer containing the parameters for creating the
	 * ViewModel.
	 * @return A unique pointer to the created ViewModel instance.
	 */
	virtual std::unique_ptr<ViewModel> createViewModel(ParamContainerBase *params = nullptr) = 0;
};

#endif // VIEWMODELPRODUCER_H
