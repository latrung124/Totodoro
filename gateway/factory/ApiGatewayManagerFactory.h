/**
 * @file ApiGatewayManagerFactory.h
 * @author trung.la
 * @date 09-25-2025
 * @brief This file contains the declaration of the ApiGatewayManagerFactory class.
 */

#pragma once

#include <memory>

namespace gateway {
    enum class RouteType : uint8_t;
}

class IApiGatewayManager;

class ApiGatewayManagerFactory {
public:
    static std::shared_ptr<IApiGatewayManager> createManager(gateway::RouteType managerType);
};
