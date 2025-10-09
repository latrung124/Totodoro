/**
 * @file RouteHandlerFactory.h
 * @author trung.la
 * @date 09-07-2025
 * @brief Header file for RouteHandlerFactory class that creates route handlers for the gateway module.
 */

#pragma once

#include <memory>
#include <string>

#include "common/CommonDefine.h"

class IRouteHandler;
class AsyncRequestProcessor;

class RouteHandlerFactory
{
public:
	static std::shared_ptr<IRouteHandler> createHandler(
	    gateway::RouteType handlerType,
	    std::shared_ptr<AsyncRequestProcessor> processor,
	    const std::string &baseUrl);
};
