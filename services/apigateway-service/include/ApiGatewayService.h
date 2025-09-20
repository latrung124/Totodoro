/**
 * @file ApiGatewayService.h
 * @author trung.la
 * @date 09-20-2025
 * @brief This file contains the declaration of the ApiGatewayService class.
 */

#ifndef API_GATEWAY_SERVICE_H
#define API_GATEWAY_SERVICE_H

#include <ApiGatewayServiceUtils.h>
#include <IApiGatewayService.h>

class APIGATEWAY_SERVICE_API ApiGatewayService : public IApiGatewayService
{
public:
	ApiGatewayService();
};

#endif // API_GATEWAY_SERVICE_H
