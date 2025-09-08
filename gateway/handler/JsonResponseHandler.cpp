/**
 * @file JsonResponseHandler.cpp
 * @author trung.la
 * @date 09-03-2025
 * @brief Implementation of IResponseHandler for handling JSON responses.
 */

#include "JsonResponseHandler.h"

#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>

void JsonResponseHandler::handleSuccess(const QByteArray& responseData)
{
    mResponse = responseData;
    mStatusCode = 200; // Assuming success status code
    mIsSuccess = true;

    QJsonDocument doc = QJsonDocument::fromJson(responseData);
    if (!doc.isNull() && doc.isObject()) {
        qInfo() << "Parsed JSON response successfully in handleSuccess";
        mParsedData = doc.object().toVariantMap();
    } else {
        qWarning() << "Failed to parse JSON response in handleSuccess";
    }
}

void JsonResponseHandler::handleError(int statusCode, const QString& errorMessage)
{
    QJsonObject errorJson{
        {"error", "Service Error"},
        {"message", errorMessage},
        {"status", statusCode}
    };

    mResponse = QJsonDocument(errorJson).toJson(QJsonDocument::Compact);
    mStatusCode = statusCode;
    mIsSuccess = false;
}

void JsonResponseHandler::handleTimeout()
{
    QJsonObject timeoutJson{
        {"error", "Gateway timeout"},
        {"message", "Upstream service did not respond in time"}
    };

    mResponse = QJsonDocument(timeoutJson).toJson(QJsonDocument::Compact);
    mStatusCode = 504; // Gateway Timeout
    mIsSuccess = false;
}

QJsonArray JsonResponseHandler::getJsonArray(const QString& key) const {
    if (mParsedData.contains(key) && mParsedData[key].canConvert<QVariantList>()) {
        QVariantList list = mParsedData[key].toList();
        return QJsonArray::fromVariantList(list);
    }
    return QJsonArray();
}

QVariantList JsonResponseHandler::getArray(const QString& key) const {
    if (mParsedData.contains(key) && mParsedData[key].canConvert<QVariantList>()) {
        return mParsedData[key].toList();
    }
    return QVariantList();
}
