/*
 * File: ServiceFactory.cpp
 * Author: trung.la
 * Date: 02-10-2025
 * Description: This file contains the implementation of the ServiceFactory class.
 */

#include <ApiGatewayService.h>
#include <ServiceFactory.h>
#include <WindowMediaService.h>

IService *ServiceFactory::factoryMethod(std::string_view serviceName) const
{
	if (serviceName == "WindowMediaService") {
		return new WindowMediaService();
	}

	if (serviceName == "ApiGatewayService") {
		return new ApiGatewayService();
	}

	return nullptr;
}
