/**
 * @file PomodoroApiGatewayManager.cpp
 * @author trung.la
 * @date 09-24-2025
 * @brief This file contains the implementation of the PomodoroApiGatewayManager class.
 */

#include "manager/PomodoroApiGatewayManager.h"

#include <QDebug>
#include <QString>

#include <OAIPomodoroServiceApi.h>
#include <OAIPomodoroServiceUpdateSessionBody.h>

#include "common/CommonDefine.h"
#include "common/Properties.h"
#include "common/ApiResponse.h"
#include "factory/ApiCommandFactory.h"
#include "handler/JsonResponseHandler.h"

#include "command/pomodoro/CreateSessionCommand.h"
#include "command/pomodoro/GetSessionsCommand.h"
#include "command/pomodoro/UpdateSessionCommand.h"
#include "command/pomodoro/DeleteSessionCommand.h"

PomodoroApiGatewayManager::PomodoroApiGatewayManager(QObject* parent)
    : IApiGatewayManager(parent), m_responseHandler(std::make_shared<JsonResponseHandler>())
{
}

bool PomodoroApiGatewayManager::registerResponseCallback(gateway::RequestType requestType, const ResponseCallback& callback)
{
    if (m_responseCallbacks.find(requestType) != m_responseCallbacks.end())
    {
        qDebug() << "Callback for request type" << static_cast<int>(requestType) << "is already registered.";
        return false; // Callback for this request type already registered
    }

    m_responseCallbacks[requestType] = callback;
    return true;
}

bool PomodoroApiGatewayManager::unregisterResponseCallback(gateway::RequestType requestType)
{
    auto it = m_responseCallbacks.find(requestType);
    if (it == m_responseCallbacks.end())
    {
        qDebug() << "No callback found for request type" << static_cast<int>(requestType) << "to unregister.";
        return false; // No callback found for this request type
    }

    m_responseCallbacks.erase(it);
    return true;
}

void PomodoroApiGatewayManager::trigger(gateway::RequestType requestType, const gateway::Properties& properties)
{
    switch (requestType) {
        case gateway::RequestType::CreatePomodoroSession: {
            const auto& sessionProps = properties.getProperty<gateway::PomodoroSessionProperties>();
            if (!createPomodoroSession(sessionProps)) {
                qDebug() << "Failed to trigger CreatePomodoroSession request.";
            }
            break;
        }
        case gateway::RequestType::GetPomodoroSessions: {
            const auto& sessionProps = properties.getProperty<gateway::PomodoroSessionProperties>();
            if (!getPomodoroSessions(sessionProps.userId, sessionProps.taskId)) {
                qDebug() << "Failed to trigger GetPomodoroSessions request.";
            }
            break;
        }
        case gateway::RequestType::UpdatePomodoroSession: {
            const auto& sessionProps = properties.getProperty<gateway::PomodoroSessionProperties>();
            if (!updatePomodoroSession(sessionProps)) {
                qDebug() << "Failed to trigger UpdatePomodoroSession request.";
            }
            break;
        }
        case gateway::RequestType::DeletePomodoroSession: {
            const auto& sessionProps = properties.getProperty<gateway::PomodoroSessionProperties>();
            if (!deletePomodoroSession(sessionProps.sessionId)) {
                qDebug() << "Failed to trigger DeletePomodoroSession request.";
            }
            break;
        }
        default: {
            qDebug() << "Unsupported request type triggered:" << static_cast<int>(requestType);
            break;
        }
    }
}

bool PomodoroApiGatewayManager::createPomodoroSession(const gateway::PomodoroSessionProperties& sessionProps)
{
    qDebug() << "Creating Pomodoro session for user:" << QString::fromStdString(sessionProps.userId);
    // Sample implementation for creating a Pomodoro session
    QString createSessionBodyQStr = QString::fromStdString(sessionProps.toCreateSessionBodyJsonString());
    ApiCommandFactory& factory = ApiCommandFactory::instance();
    auto command = factory.createTyped<CreateSessionCommand>(
        QString::fromStdString(sessionProps.userId),
        OpenAPI::OAIPomodoroServiceCreateSessionBody(createSessionBodyQStr),
        gateway::kBaseUrl.data(),
        nullptr // Set parent to this manager for QObject hierarchy
    );

    if (!command)
    {
        qDebug() << "Failed to create CreateSessionCommand.";
        return false;
    }

    command->setResponseHandler(m_responseHandler);
    command->execute();

    return true;
}

bool PomodoroApiGatewayManager::getPomodoroSessions(const std::string& userId, const std::string& taskId)
{
    qDebug() << "Retrieving Pomodoro sessions for user:" << QString::fromStdString(userId);
    QString userIdQStr = QString::fromStdString(userId);
    QString taskIdQStr = QString::fromStdString(taskId);
    ApiCommandFactory& factory = ApiCommandFactory::instance();
    auto command = factory.createTyped<GetSessionsCommand>(
        userIdQStr,
        taskIdQStr,
        gateway::kBaseUrl.data(),
        nullptr // Set parent to this manager for QObject hierarchy
    );

    if (!command)
    {
        qDebug() << "Failed to create GetSessionsCommand.";
        return false;
    }

    command->setResponseHandler(m_responseHandler);
    command->execute();

    return true;
}

bool PomodoroApiGatewayManager::updatePomodoroSession(const gateway::PomodoroSessionProperties& sessionProps)
{
    qDebug() << "Updating Pomodoro session:" << QString::fromStdString(sessionProps.sessionId);
    QString updateSessionBodyQStr = QString::fromStdString(sessionProps.toUpdateSessionBodyJsonString());
    ApiCommandFactory& factory = ApiCommandFactory::instance();
    auto command = factory.createTyped<UpdateSessionCommand>(
        OpenAPI::OAIPomodoroServiceUpdateSessionBody(updateSessionBodyQStr),
        QString::fromStdString(sessionProps.sessionId),
        gateway::kBaseUrl.data(),
        nullptr // Set parent to this manager for QObject hierarchy
    );

    if (!command)
    {
        qDebug() << "Failed to create UpdateSessionCommand.";
        return false;
    }

    command->setResponseHandler(m_responseHandler);
    command->execute();

    return true;
}

bool PomodoroApiGatewayManager::deletePomodoroSession(const std::string& sessionId)
{
    qDebug() << "Deleting Pomodoro session:" << QString::fromStdString(sessionId);
    QString sessionIdQStr = QString::fromStdString(sessionId);
    ApiCommandFactory& factory = ApiCommandFactory::instance();
    auto command = factory.createTyped<DeleteSessionCommand>(
        sessionIdQStr,
        gateway::kBaseUrl.data(),
        nullptr // Set parent to this manager for QObject hierarchy
    );

    if (!command)
    {
        qDebug() << "Failed to create DeleteSessionCommand.";
        return false;
    }

    command->setResponseHandler(m_responseHandler);
    command->execute();

    return true;
}
