/**
 * @file UserInfoRetrievedCompressStrategy.h
 * @author trung.la
 * @date 12-01-2025
 * @brief This file contains the declaration of the UserInfoRetrievedCompressStrategy class.
 */

#ifndef USER_INFO_RETRIEVED_COMPRESS_STRATEGY_H
#define USER_INFO_RETRIEVED_COMPRESS_STRATEGY_H

#include "core/services/strategies/IStrategy.h"

class RequestUserInformationAsyncMessage;

class UserInfoRetrievedCompressStrategy : public IStrategy<RequestUserInformationAsyncMessage>
{
public:
	~UserInfoRetrievedCompressStrategy();
	void execute(const RequestUserInformationAsyncMessage &message) override;

private:
	void compress(const RequestUserInformationAsyncMessage &message);
};

#endif // USER_INFO_RETRIEVED_COMPRESS_STRATEGY_H
