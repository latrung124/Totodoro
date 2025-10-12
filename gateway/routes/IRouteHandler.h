/**
 * @file routes/routes/IRouteHandler.h
 * @author trung.la
 * @date 09-05-2025
 * @brief Interface for route handlers in the gateway module.
 */

#pragma once

#include <string>
#include <memory>

#include <httplib.h>

class AsyncRequestProcessor;
class ApiClientFactory;
class IResponseHandler;

class IRouteHandler {
public:
    virtual ~IRouteHandler() = default;

    virtual void handleRequest(const httplib::Request& req, httplib::Response& res) = 0;
    virtual bool canHandle(const std::string& path, const std::string& method) const = 0;

    virtual std::shared_ptr<IResponseHandler> createResponseHandler() const = 0;

protected:
    std::shared_ptr<AsyncRequestProcessor> mRequestProcessor;
    std::shared_ptr<ApiClientFactory> mApiClientFactory;
    std::string mBaseUrl;
};
