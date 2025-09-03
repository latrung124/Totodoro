/**
 * File: PomodoroOpenApiController.cpp
 * Author: trung.la
 * Date: 09-02-2025
 * Description: Implementation file for PomodoroOpenApiController class that handles Pomodoro-related API endpoints.
 */

#include "PomodoroOpenApiController.h"

#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTimer>
#include <QtGlobal>

// Generated Qt OpenAPI client headers
#include <OAIPomodoroServiceApi.h>
#include <OAIPomodoroServiceCreateSessionBody.h>
#include <OAIPomodoro_serviceCreateSessionResponse.h>

using namespace OpenAPI;

namespace {

template <typename SuccessConn, typename ErrorConn, typename RequestInvoker>
bool waitForResponse(SuccessConn successConnect,
                    ErrorConn errorConnect,
                    RequestInvoker invokeRequest,
                    int timeoutMs,
                    QByteArray& outBody,
                    int& outStatusCode)
{
    QEventLoop loop;
    QTimer timeout;
    timeout.setSingleShot(true);
    QObject::connect(&timeout, &QTimer::timeout, &loop, &QEventLoop::quit);

    bool isSuccess = false;

    // Connect success signal
    successConnect([&](auto result) {
        // Most generated models have asJson() that returns QString
        if constexpr (std::is_same_v<decltype(result), OAIPomodoro_serviceCreateSessionResponse>) {
            const QString json = result.asJson();
            outBody = json.toUtf8();
            outStatusCode = 200;
        } else {
            // Fallback if void result or different model
            outBody = "{}";
            outStatusCode = 200;
        }
        isSuccess = true;
        loop.quit();
    });

    // Connect error signal
    errorConnect([&](QNetworkReply::NetworkError, QString errorStr) {
        QJsonObject err{
            {"error", "Upstream service error"},
            {"message", errorStr}
        };
        outBody = QJsonDocument(err).toJson(QJsonDocument::Compact);
        outStatusCode = 502; // Bad Gateway
        isSuccess = false;
        loop.quit();
    });

    // Fire request and wait
    invokeRequest();
    timeout.start(timeoutMs);
    loop.exec();

    if (!isSuccess && !timeout.isActive()) {
        // Timeout occurred
        QJsonObject err{
            {"error", "Gateway timeout"},
            {"message", "Upstream service did not respond in time"}
        };
        outBody = QJsonDocument(err).toJson(QJsonDocument::Compact);
        outStatusCode = 504; // Gateway Timeout
    }
    timeout.stop();
    return isSuccess;
}

inline std::string pathParam(const httplib::Request& req, size_t idx)
{
    if (idx < req.matches.size()) {
        return req.matches[idx].str();
    }
    return "";
}

} // namespace

namespace gateway {

void PomodoroOpenApiController::registerRoutes(httplib::Server& server, const std::string& baseUrl)
{
}

}
