/**
 * @file UserInformationMessage.cpp
 * @author trung.la
 * @date 10-28-2025
 * @brief This file contains the implementation of the UserInformationMessage class.
 */

#include "UserInformationMessage.h"

namespace {
using namespace apigateway_service::utils::user;
}

UserInformationMessage::UserInformationMessage(ExtractUserInformationStrategyUPtr strategy)
    : Message(MessageId::UserInformationMessage)
    , m_strategy(std::move(strategy))
{
}

UserInformationMessage::~UserInformationMessage() = default;

void UserInformationMessage::setUserInformation(const UserInformation &info)
{
	m_userInformation = info;
}

UserInformationMessage::UserInformation UserInformationMessage::getUserInformation() const
{
	return m_userInformation;
}

void UserInformationMessage::execute()
{
	if (m_strategy) {
		m_strategy->execute(*this);
	}
}
