/**
 * @file SessionDataTransformer.h
 * @author trung.la
 * @date 09-08-2025
 * @brief Session data transformer helper
 */

#pragma once

#include <QVariantMap>

namespace gateway { namespace helper {

/**
 * @class SessionDataTransformer
 * @brief Helper class for transforming session data
 */
class SessionDataTransformer
{
public:
	/**
	 * @brief Transform session data by formatting date-time fields
	 * @param sessionData Input session data as QVariantMap
	 */
	static QVariantMap transformSessionData(const QVariantMap &sessionData);
};

}} // namespace gateway::helper
