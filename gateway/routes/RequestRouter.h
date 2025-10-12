/**
 * @file RequestRouter.h
 * @author trung.la
 * @date 09-07-2025
 * @brief Header file for RequestRouter class that manages the registration of all API routes.
 */

#pragma once

#include <memory>
#include <vector>

#include <httplib.h>

class IRouteHandler;

class RequestRouter
{
public:
    using IRouteHandlerPtr = std::shared_ptr<IRouteHandler>;

    RequestRouter() = default;
    ~RequestRouter() = default;

    void addHandler(IRouteHandlerPtr handler);
    void handleRequest(const httplib::Request& req, httplib::Response& res) const;

private:
    std::vector<IRouteHandlerPtr> mHandlers;
};