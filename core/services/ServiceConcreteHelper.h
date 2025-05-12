/*
 * File: ServiceConcreteHelper.h
 * Author: trung.la
 * Date: 02-11-2025
 * Description: This file contains the declaration of the ServiceConcreteHelper class.
 */

#ifndef SERVICE_CONCRETE_HELPER_H
#define SERVICE_CONCRETE_HELPER_H

#include <IService.h>
#include <IServiceFactory.h>
#include <IWMediaService.h>

#include <concepts>
#include <memory>

namespace service_concrete_helper {
template<typename Interface> concept IServiceType = std::derived_from<Interface, IService>;

template<IServiceType Interface>
    requires IServiceType<Interface>
std::shared_ptr<IService> createConcreteService(IServiceFactory *serviceFactory)
{
	if constexpr (std::same_as<Interface, IService>) {
		return nullptr;
	} else if constexpr (std::same_as<Interface, IWMediaService>) {
		return std::shared_ptr<IService>(serviceFactory->factoryMethod("WindowMediaService"));
	} else {
		return nullptr;
	}
}

} // namespace service_concrete_helper

#endif // SERVICE_CONCRETE_HELPER_H
