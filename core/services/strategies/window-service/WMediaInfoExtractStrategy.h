/*
 * File: WMediaInfoExtractStrategy.h
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the declaration of the WMediaInfoExtractStrategy class.
 */

#ifndef WMEDIA_INFO_EXTRACT_STRATEGY_H
#define WMEDIA_INFO_EXTRACT_STRATEGY_H

#include "core/services/strategies/IStrategy.h"

class WMediaInfoMessage;

class WMediaInfoExtractStrategy : public IStrategy<WMediaInfoMessage>
{
public:
	~WMediaInfoExtractStrategy();
	void execute(const WMediaInfoMessage &message) override;

private:
	void extract(const WMediaInfoMessage &message);
};

#endif // WMEDIA_INFO_EXTRACT_STRATEGY_H
