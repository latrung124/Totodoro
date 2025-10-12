/**
 * @file TaskManagementRouteHandler.h
 * @author trung.la
 * @date 09-21-2025
 * @brief Route handler for task management-related endpoints.
 */

#pragma once

#include <functional>
#include <regex>
#include <string>
#include <vector>

#include "IRouteHandler.h"
#include "AsyncRequestProcessor.h"

class TaskManagementRouteHandler : public IRouteHandler
{
public:
    using AsyncRequestProcessorPtr = std::shared_ptr<AsyncRequestProcessor>;
    using HandlerFn = std::function<void(const httplib::Request&, httplib::Response&)>;

    struct RoutePattern {
        std::regex pattern;
        std::string method;
        HandlerFn handler;
        RoutePattern(std::regex p, std::string m, HandlerFn h)
            : pattern(std::move(p)), method(std::move(m)), handler(std::move(h)) {}
    };

    TaskManagementRouteHandler(AsyncRequestProcessorPtr requestProcessor,
                               const std::string& baseUrl);

    bool canHandle(const std::string& path, const std::string& method) const override;
    void handleRequest(const httplib::Request& req, httplib::Response& res) override;

    std::shared_ptr<IResponseHandler> createResponseHandler() const override;

private:
    void initializeRoutes();

    void handleCreateTask(const httplib::Request& req, httplib::Response& res);
    void handleGetTasks(const httplib::Request& req, httplib::Response& res);
    void handleUpdateTask(const httplib::Request& req, httplib::Response& res);
    void handleDeleteTask(const httplib::Request& req, httplib::Response& res);
    void handleCreateTaskGroup(const httplib::Request& req, httplib::Response& res);
    void handleGetTaskGroups(const httplib::Request& req, httplib::Response& res);
    void handleUpdateTaskGroup(const httplib::Request& req, httplib::Response& res);
    void handleDeleteTaskGroup(const httplib::Request& req, httplib::Response& res);

    std::string extractPathParam(const httplib::Request& req, size_t index) const;
    std::vector<RoutePattern> mRoutePatterns;
};
