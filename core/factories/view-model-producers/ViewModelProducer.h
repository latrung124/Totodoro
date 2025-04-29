/*
 * File: ViewModelProducer.h
 * Author: trung.la
 * Date: 04-26-2025
 * Description: ViewModelProducer class definition
 * This class is responsible for producing View Model instances based on the provided parameters.
 */

#ifndef VIEWMODELPRODUCER_H
#define VIEWMODELPRODUCER_H

#include <QObject>

#include <memory>

#include "core/factories/ParamContainer.h"

class ViewModelProducer
{
public:
	using ParamContainerBase = core::factories::ParamContainerBase;

	virtual ~ViewModelProducer() = default;

	/**
	 * @brief Creates a View Model instance based on the provided parameters.
	 * @param params A pointer to a tuple, ParamContainer containing the parameters for creating the
	 * View Model.
	 * @return A unique pointer to the created View Model instance.
	 */
	virtual std::unique_ptr<QObject> createViewModel(ParamContainerBase *params = nullptr) = 0;
};

#endif // VIEWMODELPRODUCER_H
