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
    // POST /v1/sessions -> create a pomodoro session
    server.Post(R"(^/v1/sessions$)", [baseUrl](const httplib::Request& req, httplib::Response& res) {
        // Parse body
        OAIPomodoroServiceCreateSessionBody body;
        if (!req.body.empty()) {
            const auto bodyStr = QString::fromUtf8(req.body.data(), static_cast<int>(req.body.size()));
            body.fromJson(bodyStr);
        }

        // Prepare API
        OAIPomodoroServiceApi api;
        api.setBaseUrl(QString::fromStdString(baseUrl));

        QByteArray out;
        int status = 500;

        const bool ok = waitForResponse(
            // success connector
            [&](auto slot) {
                QObject::connect(&api, &OAIPomodoroServiceApi::pomodoro_serviceCreateSessionSignal, slot);
            },
            // error connector
            [&](auto slot) {
                QObject::connect(&api, &OAIPomodoroServiceApi::pomodoro_serviceCreateSessionSignalE, slot);
            },
            // invoke upstream request
            [&]() {
                api.pomodoro_serviceCreateSession(body);
            },
            10000, // timeout ms
            out, status
        );

        res.status = status;
        res.set_content(out.constData(), "application/json");
    });

    // Catch-all for any /v1/sessions/* endpoint (not implemented yet)
    auto notImplemented = [](const httplib::Request& req, httplib::Response& res) {
        QJsonObject err{
            {"error", "Not Implemented"},
            {"path", QString::fromStdString(req.path)},
            {"message", "Endpoint under /v1/sessions/* is not implemented in the gateway"}
        };
        const auto json = QJsonDocument(err).toJson(QJsonDocument::Compact);
        res.status = 501;
        res.set_content(json.constData(), "application/json");
    };

    server.Get(R"(^/v1/sessions/.*$)", notImplemented);
    server.Post(R"(^/v1/sessions/.*$)", notImplemented);
    server.Put(R"(^/v1/sessions/.*$)", notImplemented);
    server.Delete(R"(^/v1/sessions/.*$)", notImplemented);
    server.Patch(R"(^/v1/sessions/.*$)", notImplemented);
}

}
