/**
 * @file RequestUserInformationAsyncMessage.h
 * @author trung.la
 * @date 11-24-2025
 * @brief This file contains the declaration of the RequestUserInformationAsyncMessage class.
 */

#ifndef REQUEST_USER_INFORMATION_ASYNC_MESSAGE_H
#define REQUEST_USER_INFORMATION_ASYNC_MESSAGE_H

#include "core/services/messages/Message.h"
#include "core/services/strategies/IStrategy.h"

#include <ApiGatewayServiceUtils.h>

class RequestUserInformationAsyncMessage : public Message
{
public:
	using CompressStrategyUPtr = std::unique_ptr<IStrategy<RequestUserInformationAsyncMessage>>;

	RequestUserInformationAsyncMessage(CompressStrategyUPtr strategy);
	~RequestUserInformationAsyncMessage();

	std::string getEmail() const;
	void setEmail(const std::string &email);

	void execute() override;

private:
	CompressStrategyUPtr m_strategy;
	std::string m_email;
};
#endif // REQUEST_USER_INFORMATION_ASYNC_MESSAGE_H
