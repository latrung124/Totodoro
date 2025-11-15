/**
 * @file UserInformationExtractStrategy.h
 * @author trung.la
 * @date 10-28-2025
 * @brief This file contains the declaration of the UserInformationExtractStrategy class.
 */

#ifndef USER_INFORMATION_EXTRACT_STRATEGY_H
#define USER_INFORMATION_EXTRACT_STRATEGY_H

#include "core/services/strategies/IStrategy.h"

class UserInformationMessage;

class UserInformationExtractStrategy : public IStrategy<UserInformationMessage>
{
public:
	~UserInformationExtractStrategy();
	void execute(const UserInformationMessage &message) override;

private:
	void extract(const UserInformationMessage &message);
};

#endif // USER_INFORMATION_EXTRACT_STRATEGY_H
