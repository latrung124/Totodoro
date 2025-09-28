/**
 * @file IApiGatewayManager.h
 * @author trung.la
 * @date 09-22-2025
 * @brief This file contains the declaration of the IApiGatewayManager interface.
 */

#pragma once

#include <memory>
#include <functional>

#include <QObject>

namespace gateway
{
    struct ApiResponse;
    enum class RequestType : uint8_t;
}

class IApiGatewayManager : public QObject
{
    Q_OBJECT
public:
    using ApiResponsePtr = std::shared_ptr<gateway::ApiResponse>;
    using ResponseCallback = std::function<void(const ApiResponsePtr&)>;

    explicit IApiGatewayManager(QObject* parent = nullptr) : QObject(parent) {}
    virtual ~IApiGatewayManager() = default;

    virtual bool registerResponseCallback(gateway::RequestType requestType, const ResponseCallback& callback) = 0;
    virtual bool unregisterResponseCallback(gateway::RequestType requestType) = 0;
};
