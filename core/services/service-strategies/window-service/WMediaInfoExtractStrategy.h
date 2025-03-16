/*
 * File: WMediaInfoExtractStrategy.h
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the declaration of the WMediaInfoExtractStrategy class.
 */

#ifndef WMEDIA_INFO_EXTRACT_STRATEGY_H
#define WMEDIA_INFO_EXTRACT_STRATEGY_H

#include "core/services/service-strategies/ExtractStrategy.h"

class WMediaInfoMessage;

class WMediaInfoExtractStrategy : public ExtractStrategy<WMediaInfoMessage>
{
public:
	void extract(const WMediaInfoMessage &message) override;
};

#endif // WMEDIA_INFO_EXTRACT_STRATEGY_H
