/**
 * @file IApiGatewayServiceListener.h
 * @author trung.la
 * @date 09-20-2025
 * @brief Interface for API Gateway service listener
 */

#ifndef IAPI_GATEWAY_SERVICE_LISTENER_H
#define IAPI_GATEWAY_SERVICE_LISTENER_H

#include "../IServiceListener.h"

class IApiGatewayServiceListener : public IServiceListener
{
public:
	IApiGatewayServiceListener() = default;
	virtual ~IApiGatewayServiceListener() = default;
};

#endif // IAPI_GATEWAY_SERVICE_LISTENER_H
