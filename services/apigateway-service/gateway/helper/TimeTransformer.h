/**
 * @file TimeTransformer.h
 * @author trung.la
 * @date 09-08-2025
 * @brief Time transformer helper
 */

#pragma once

#include <QString>

namespace gateway { namespace helper {
/**
 * @class TimeTransformer
 * @brief Helper class for transforming time formats
 */
class TimeTransformer
{
public:
	/**
	 * @brief Format ISO 8601 date-time string to "dd/MM/yyyy HH:mm:ss" format
	 * @param isoDateTime ISO 8601 date-time string
	 * @return Formatted date-time string
	 */
	static QString formatDateTime(const QString &isoDateTime);
};

}} // namespace gateway::helper
