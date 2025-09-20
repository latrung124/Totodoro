/**
 * @file IApiGatewayService.h
 * @author trung.la
 * @date 09-20-2025
 * @brief This file contains the declaration of the IApiGatewayService interface.
 */

#ifndef IAPI_GATEWAY_SERVICE_H
#define IAPI_GATEWAY_SERVICE_H

#include "../IService.h"
#include <ApiGatewayServiceExport.h>

class APIGATEWAY_SERVICE_API IApiGatewayService : public IService
{
public:
	virtual ~IApiGatewayService() = default;
};

#endif // IAPI_GATEWAY_SERVICE_H
