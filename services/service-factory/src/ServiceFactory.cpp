/*
* File: ServiceFactory.cpp
* Author: trung.la
* Date: 02-10-2025
* Description: This file contains the implementation of the ServiceFactory class.
*/

#include "services/service-factory/include/ServiceFactory.h"
#include "services/window-services/media/include/WindowMediaService.h"

IService* ServiceFactory::factoryMethod(std::string_view serviceName) const
{
    if (serviceName == "WindowMediaService") {
        return new WindowMediaService();
    }

    return nullptr;
}
