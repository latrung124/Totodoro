/*
* File: ConsulDiscovery.h
* Author: trung.la
* Date: 03-26-2025
* Description: Implementation of service discovery using Consul
* Consul is a distributed service mesh to connect, secure, and configure services across any runtime platform and public or private cloud
*/

#ifndef CONSULDISCOVERY_H_
#define CONSULDISCOVERY_H_

#include <string_view>

#include <httplib.h>

#include "service-discovery/IServiceDiscovery.h"

namespace microservices::service_discovery
{

class ConsulDiscovery : public IServiceDiscovery
{
public:
    ConsulDiscovery(std::string_view addr = "localhost", int port = 8500, bool enabledHealthCheck = true);
    virtual ~ConsulDiscovery();

    virtual std::vector<std::string> discover(std::string serviceName) override;
    virtual void registerService(const std::string &name, const std::string &url, int port) override;
    virtual void unregisterService(const std::string &name, const std::string &url, int port) override;

private:
    std::string getLocalIp();

    httplib::Client m_client;
    bool m_enabledHealthCheck = true;
};

} // namespace microservices::service_discovery

#endif // CONSULDISCOVERY_H_
