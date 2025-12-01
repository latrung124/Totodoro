/**
 * @file UserSettingsRetrievedCompressStrategy.h
 * @author trung.la
 * @date 12-01-2025
 * @brief This file contains the declaration of the UserSettingsRetrievedCompressStrategy class.
 */

#ifndef USER_SETTINGS_RETRIEVED_COMPRESS_STRATEGY_H
#define USER_SETTINGS_RETRIEVED_COMPRESS_STRATEGY_H

#include "core/services/strategies/IStrategy.h"

class RequestUserSettingsAsyncMessage;

class UserSettingsRetrievedCompressStrategy : public IStrategy<RequestUserSettingsAsyncMessage>
{
public:
	~UserSettingsRetrievedCompressStrategy();
	void execute(const RequestUserSettingsAsyncMessage &message) override;

private:
	void compress(const RequestUserSettingsAsyncMessage &message);
};

#endif // USER_SETTINGS_RETRIEVED_COMPRESS_STRATEGY_H
