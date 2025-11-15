/**
 * @file UserSettingsExtractStrategy.h
 * @author trung.la
 * @date 10-29-2025
 * @brief This file contains the declaration of the UserSettingsExtractStrategy class.
 */

#ifndef USER_SETTINGS_EXTRACT_STRATEGY_H
#define USER_SETTINGS_EXTRACT_STRATEGY_H

#include "core/services/strategies/IStrategy.h"

class UserSettingsMessage;

class UserSettingsExtractStrategy : public IStrategy<UserSettingsMessage>
{
public:
	~UserSettingsExtractStrategy();
	void execute(const UserSettingsMessage &message) override;

private:
	void extract(const UserSettingsMessage &message);
};

#endif // USER_SETTINGS_EXTRACT_STRATEGY_H
