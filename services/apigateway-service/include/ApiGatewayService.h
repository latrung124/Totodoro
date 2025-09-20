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
	using Information = apigateway_service::utils::user::Information;
	using Settings = apigateway_service::utils::user::Settings;

	ApiGatewayService();
	~ApiGatewayService() override;

	ApiGatewayService(const ApiGatewayService &) = delete;
	ApiGatewayService &operator=(const ApiGatewayService &) = delete;

	ApiGatewayService(ApiGatewayService &&) = delete;
	ApiGatewayService &operator=(ApiGatewayService &&) = delete;

	void registerListener(const IServiceListener *listener) override;
	void unregisterListener(const IServiceListener *listener) override;

	void start() override;
	void stop() override;

	void requestCreateUser(const Information &userInformation) override;
	void requestGetUserInformation(const std::string &userId) override;
	void requestGetUserSettings(const std::string &userId) override;
	void requestUpdateUserInformation(const Information &info) override;
	void requestUpdateUserSettings(const Settings &settings) override;

private:
	std::vector<IServiceListener *> m_listeners; // TODO: change to map for faster access the listener
};

#endif // API_GATEWAY_SERVICE_H
