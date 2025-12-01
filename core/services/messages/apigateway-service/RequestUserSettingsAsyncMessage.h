/**
 * @file RequestUserSettingsAsyncMessage.h
 * @author trung.la
 * @date 12-01-2025
 * @brief This file contains the declaration of the RequestUserSettingsAsyncMessage class.
 */

#ifndef REQUEST_USER_SETTINGS_ASYNC_MESSAGE_H
#define REQUEST_USER_SETTINGS_ASYNC_MESSAGE_H

#include "core/services/messages/Message.h"
#include "core/services/strategies/IStrategy.h"

#include <ApiGatewayServiceUtils.h>

class RequestUserSettingsAsyncMessage : public Message
{
public:
	using CompressStrategyUPtr = std::unique_ptr<IStrategy<RequestUserSettingsAsyncMessage>>;

	RequestUserSettingsAsyncMessage(CompressStrategyUPtr strategy);
	~RequestUserSettingsAsyncMessage();

	std::string getUserId() const;
	void setUserId(const std::string &userId);

	void execute() override;

private:
	CompressStrategyUPtr m_strategy;
	std::string m_userId;
};

#endif // REQUEST_USER_SETTINGS_ASYNC_MESSAGE_H
