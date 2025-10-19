/**
 * @file ApiGatewayService.h
 * @author trung.la
 * @date 09-20-2025
 * @brief This file contains the declaration of the ApiGatewayService class.
 */

#ifndef API_GATEWAY_SERVICE_H
#define API_GATEWAY_SERVICE_H

#include <memory>
#include <vector>

#include <ApiGatewayServiceUtils.h>
#include <IApiGatewayService.h>

namespace gateway {
class Gateway;
} // namespace gateway

class APIGATEWAY_SERVICE_API ApiGatewayService : public IApiGatewayService
{
public:
	using Information = apigateway_service::utils::user::Information;
	using Settings = apigateway_service::utils::user::Settings;
	using GatewayUPtr = std::unique_ptr<gateway::Gateway>;

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

	void onResponseCreateUser(const Information &userInformation);
	void onResponseGetUserInformation(const Information &userInformation);
	void onResponseGetUserSettings(const Settings &settings);
	void onResponseUpdateUserInformation(const Information &userInformation);
	void onResponseUpdateUserSettings(const Settings &settings);

private:
	std::vector<IServiceListener *> m_listeners; // TODO: change to map for faster access the listener
	GatewayUPtr m_gateway;
};

#endif // API_GATEWAY_SERVICE_H
