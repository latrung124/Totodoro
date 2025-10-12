/**
 * @file TimeTransformer.cpp
 * @author trung.la
 * @date 09-08-2025
 * @brief Time transformer helper
 */

#include "helper/TimeTransformer.h"

#include <QDateTime>

namespace gateway {

namespace helper {

QString TimeTransformer::formatDateTime(const QString& isoDateTime)
{
    QDateTime dateTime = QDateTime::fromString(isoDateTime, Qt::ISODate);
    if (!dateTime.isValid()) {
        return isoDateTime; // Return original if parsing fails
    }
    return dateTime.toString("dd/MM/yyyy HH:mm:ss");
}

} // namespace helper

} // namespace gateway
