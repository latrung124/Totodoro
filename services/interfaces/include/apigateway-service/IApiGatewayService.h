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
#include <ApiGatewayServiceUtils.h>

class APIGATEWAY_SERVICE_API IApiGatewayService : public IService
{
public:
	virtual ~IApiGatewayService() = default;

	virtual void requestCreateUser(
	    const apigateway_service::utils::user::Information &userInformation) = 0;
	virtual void requestGetUserInformation(const std::string &userId) = 0;
	virtual void requestGetUserSettings(const std::string &userId) = 0;
	virtual void requestUpdateUserInformation(
	    const apigateway_service::utils::user::Information &info) = 0;
	virtual void requestUpdateUserSettings(
	    const apigateway_service::utils::user::Settings &settings) = 0;
};

#endif // IAPI_GATEWAY_SERVICE_H
