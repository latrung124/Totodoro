/*
 * File: IServiceFactory.h
 * Author: trung.la
 * Date: 02-10-2025
 * Description: This file contains the declaration of the IServiceFactory class.
 */

#ifndef I_SERVICE_FACTORY_H
#define I_SERVICE_FACTORY_H

#include <ServiceFactoryExport.h>

#include <string_view>

#include "IService.h"

class SERVICE_FACTORY_API IServiceFactory
{
public:
	virtual ~IServiceFactory() = default;
	virtual IService *factoryMethod(std::string_view serviceName) const = 0;
};

extern "C" SERVICE_FACTORY_API IServiceFactory *getServiceFactory();

#endif // I_SERVICE_FACTORY_H
