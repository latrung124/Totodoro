/*
* File: IServiceDiscovery.h
* Author: trung.la
* Date: 05-26-2025
* Description: This file defines the IServiceDiscovery interface for service discovery in a microservices architecture.
*/

#ifndef ISERVICEDISCOVERY_H
#define ISERVICEDISCOVERY_H

#include <string>
#include <vector>

namespace microservices {

namespace service_discovery {

class IServiceDiscovery
{
public:
    virtual ~IServiceDiscovery() = default;

    virtual std::vector<std::string> discover(std::string serviceName) = 0;
    virtual void registerService(const std::string &name, const std::string &url, int port) = 0;
    virtual void unregisterService(const std::string &name, const std::string &url, int port) = 0;
};

} // namespace service_discovery

} // namespace microservices

#endif // ISERVICEDISCOVERY_H
