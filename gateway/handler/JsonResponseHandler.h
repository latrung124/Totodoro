/**
 * @file JsonResponseHandler.h
 * @author trung.la
 * @date 09-03-2025
 * @brief Implementation of IResponseHandler for handling JSON responses.
 */

#pragma once

#include "IResponseHandler.h"

class JsonResponseHandler : public IResponseHandler
{
public:
    void handleSuccess(const QByteArray& responseData) override;
    void handleError(int statusCode, const QString& errorMessage) override;
    void handleTimeout() override;
};