/*
* File: IServiceDiscovery.h
* Author: trung.la
* Date: 05-26-2025
* Description: This file defines the IServiceDiscovery interface for service discovery in a microservices architecture.
*/

#ifndef ISERVICEDISCOVERY_H
#define ISERVICEDISCOVERY_H

#include <string_view>
#include <vector>

namespace microservices {

namespace service_discovery {

class IServiceDiscovery
{
public:
    virtual ~IServiceDiscovery() = default;

    virtual std::vector<std::string> discover(std::string_view &serviceName) = 0;
    virtual void registerService(std::string_view &name, std::string_view &endpoint) = 0;
    virtual void unregisterService(std::string_view &name, std::string_view &endpoint) = 0;
};

} // namespace service_discovery

} // namespace microservices

#endif // ISERVICEDISCOVERY_H