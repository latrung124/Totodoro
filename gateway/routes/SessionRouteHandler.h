/**
 * @file SessionRouteHandler.h
 * @author trung.la
 * @date 09-05-2025
 * @brief Route handler for Pomodoro session-related endpoints.
 */

#pragma once

#include <functional>
#include <regex>
#include <string>
#include <vector>

#include "IRouteHandler.h"

#include "AsyncRequestProcessor.h"
#include "ApiClientFactory.h"

class SessionRouteHandler : public IRouteHandler
{
public:
    using AsyncRequestProcessorPtr = std::shared_ptr<AsyncRequestProcessor>;
    using ApiClientFactoryPtr = std::shared_ptr<ApiClientFactory>;
    using HandlerFn = std::function<void(const httplib::Request&, httplib::Response&)>;

    struct RoutePattern {
        std::regex pattern;
        std::string method;
        HandlerFn handler;
        RoutePattern(std::regex p, std::string m, HandlerFn h)
            : pattern(std::move(p)), method(std::move(m)), handler(std::move(h)) {}
    };

    SessionRouteHandler(AsyncRequestProcessorPtr requestProcessor,
                        ApiClientFactoryPtr apiClientFactory,
                        const std::string& baseUrl);

    bool canHandle(const std::string& path, const std::string& method) const override;
    void handleRequest(const httplib::Request& req, httplib::Response& res) override;

    std::shared_ptr<IResponseHandler> createResponseHandler() const override;

private:
    void initializeRoutes();

    void handleCreateSession(const httplib::Request& req, httplib::Response& res);
    void handleGetSession(const httplib::Request& req, httplib::Response& res);
    void handleUpdateSession(const httplib::Request& req, httplib::Response& res);
    void handleDeleteSession(const httplib::Request& req, httplib::Response& res);
    void handleGetUserSessions(const httplib::Request& req, httplib::Response& res);

    std::string extractPathParam(const httplib::Request& req, size_t index) const;
    std::vector<RoutePattern> mRoutePatterns;
};
