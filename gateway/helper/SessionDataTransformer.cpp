/**
 * @file SessionDataTransformer.cpp
 * @author trung.la
 * @date 09-08-2025
 * @brief Session data transformer helper
 */

#include "SessionDataTransformer.h"

#include "TimeTransformer.h"

namespace gateway {

namespace helper {

QVariantMap SessionDataTransformer::transformSessionData(const QVariantMap& rawData) {
    QVariantMap transformed = rawData;
    
    // Format date/time fields
    if (transformed.contains("startTime")) {
        transformed["startTimeFormatted"] = TimeTransformer::formatDateTime(transformed["startTime"].toString());
    }
    
    if (transformed.contains("endTime") && !transformed["endTime"].toString().isEmpty()) {
        transformed["endTimeFormatted"] = TimeTransformer::formatDateTime(transformed["endTime"].toString());
    }
    
    if (transformed.contains("lastUpdate")) {
        transformed["lastUpdateFormatted"] = TimeTransformer::formatDateTime(transformed["lastUpdate"].toString());
    }

    return transformed;
}

} // namespace helper

} // namespace gateway
