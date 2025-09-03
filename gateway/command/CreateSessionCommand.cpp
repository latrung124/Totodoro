/**
 * @file CreateSessionCommand.cpp
 * @author trung.la
 * @date 09-03-2025
 * @brief Implementation of CreateSessionCommand to create a Pomodoro session via the Pomodoro API.
 */

#include "CreateSessionCommand.h"

#include <QEventLoop>
#include <QTimer>

CreateSessionCommand::CreateSessionCommand(const QString& userId, 
    const OAIPomodoroServiceCreateSessionBody& body,
    IPomodoroApiClientFactoryPtr factory,
    const QString& baseUrl,
    QObject* parent)
    : IApiCommand(parent),
      mUserId(userId),
      mBody(body),
      mFactory(factory),
      mBaseUrl(baseUrl),
      mResponseHandler(nullptr),
      mApiClient(nullptr)
{
}

void CreateSessionCommand::execute()
{
}

void CreateSessionCommand::setResponseHandler(IResponseHandlerPtr handler)
{
    mResponseHandler = handler;
}

IResponseHandlerPtr CreateSessionCommand::getResponseHandler() const
{
    return mResponseHandler;
}

void CreateSessionCommand::onSessionCreated(const OAIPomodoro_serviceCreateSessionResponse& response)
{
}

void CreateSessionCommand::onSessionError(const OAIPomodoro_serviceCreateSessionResponse& summary, 
                                         QNetworkReply::NetworkError errorType, const QString& errorStr)
{
}

