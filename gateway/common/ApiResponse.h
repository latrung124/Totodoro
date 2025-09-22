/**
 * @file ApiResponse.h
 * @author trung.la
 * @date 09-22-2025
 * @brief This file contains the declaration of the ApiResponse struct.
 */

#include <string>
#include <QJsonObject>

namespace gateway
{

struct ApiResponse
{
    bool success;
    int statusCode;
    std::string body;
    QJsonObject data;

    ApiResponse() : success(false), statusCode(0), body(""), data(QJsonObject()) {}
};

} // namespace gateway