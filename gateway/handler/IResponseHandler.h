/**
 * @file IResponseHandler.h
 * @author trung.la
 * @date 09-03-2025
 * @brief Interface for handling API responses.
 */

#pragma once

#include <QByteArray>
#include <QVariantMap>

/**
 * @brief Interface for handling API responses.
 */
class IResponseHandler
{
public:
    virtual ~IResponseHandler() = default;

    virtual void handleSuccess(const QByteArray& responseData) = 0;
    virtual void handleError(int statusCode, const QString& errorMessage) = 0;
    virtual void handleTimeout() = 0;

    QByteArray getResponseData() const { return mResponse; }
    QVariantMap getParsedData() const { return mParsedData; }
    int getStatusCode() const { return mStatusCode; }
    bool isSuccessful() const { return mIsSuccess; }

protected:
    QByteArray mResponse;
    QVariantMap mParsedData;
    int mStatusCode = 0;
    bool mIsSuccess = false;
};

using IResponseHandlerPtr = std::shared_ptr<IResponseHandler>;