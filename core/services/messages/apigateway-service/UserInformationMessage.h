/**
 * @file UserInformationMessage.h
 * @author trung.la
 * @date 10-28-2025
 * @brief This file contains the declaration of the UserInformationMessage class.
 */

#ifndef USER_INFORMATION_MESSAGE_H
#define USER_INFORMATION_MESSAGE_H

#include "core/services/messages/Message.h"
#include "core/services/strategies/IStrategy.h"
#include <ApiGatewayServiceUtils.h>

class UserInformationMessage : public Message
{
public:
	using UserInformation = apigateway_service::utils::user::Information;
	using ExtractUserInformationStrategyUPtr = std::unique_ptr<IStrategy<UserInformationMessage>>;

	UserInformationMessage(ExtractUserInformationStrategyUPtr strategy);
	~UserInformationMessage();

	void setUserInformation(const UserInformation &info);
	UserInformation getUserInformation() const;

	void execute() override;

private:
	UserInformation m_userInformation;
	ExtractUserInformationStrategyUPtr m_strategy;
};

#endif // USER_INFORMATION_MESSAGE_H
