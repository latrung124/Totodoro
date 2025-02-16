/*
* File: ServiceFactory.h
* Author: trung.la
* Date: 02-10-2025
* Description: This file contains the declaration of the ServiceFactory class.
*/

#ifndef SERVICE_FACTORY_H
#define SERVICE_FACTORY_H

#include "../IServiceFactory.h"

class SERVICE_FACTORY_API ServiceFactory : public IServiceFactory
{
public:
    ServiceFactory() = default;
    virtual ~ServiceFactory() = default;
    virtual IService* factoryMethod(std::string_view serviceName) const override;
};

extern "C" SERVICE_FACTORY_API IServiceFactory* getServiceFactory() {
    static ServiceFactory serviceFactory;
    return &serviceFactory;
}

#endif // SERVICE_FACTORY_H
