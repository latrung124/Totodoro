/**
 * @file RequestRouter.cpp
 * @author trung.la
 * @date 09-07-2025
 * @brief Implementation file for RequestRouter class that manages the registration of all API routes.
 */

#include "routes/RequestRouter.h"

#include "routes/IRouteHandler.h"

void RequestRouter::addHandler(IRouteHandlerPtr handler)
{
    mHandlers.push_back(std::move(handler));
}

void RequestRouter::handleRequest(const httplib::Request& req, httplib::Response& res) const
{
    for (const auto& handler : mHandlers)
    {
        if (handler->canHandle(req.path, req.method))
        {
            handler->handleRequest(req, res);
            return;
        }
    }

    res.status = 404;
    res.set_content(R"({"error": "Not found"})", "application/json");
}

