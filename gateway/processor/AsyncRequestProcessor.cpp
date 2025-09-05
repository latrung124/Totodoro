/**
 * @file AsyncRequestProcessor.cpp
 * @author trung.la
 * @date 09-05-2025
 * @brief Implementation of AsyncRequestProcessor for processing asynchronous API commands.
 */

#include "AsyncRequestProcessor.h"

#include <QEventLoop>
#include <QTimer>
#include <QDebug>

#include "command/IApiCommand.h"
#include "handler/IResponseHandler.h"

void AsyncRequestProcessor::processCommand(IApiCommandPtr command, int timeoutMs)
{
    if (!command) {
        qWarning() << "AsyncRequestProcessor: Command is null.";
        return;
    }

    QEventLoop loop;
    QTimer timer;
    timer.setSingleShot(true);

    // Connect to command completion
    QObject::connect(command.get(), &QObject::destroyed, &loop, &QEventLoop::quit);
    QObject::connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);

    // Execute the command
    command->execute();

    // Start the timer
    timer.start(timeoutMs);

    // Start the event loop and wait for either the command to finish or the timeout
    loop.exec();

    if (timer.isActive()) {
        // Command finished before timeout
        timer.stop();
    } else {
        // Timeout occurred
        qWarning() << "AsyncRequestProcessor: Command timed out after" << timeoutMs << "ms.";
        auto handler = command->getResponseHandler();
        if (handler) {
            handler->handleTimeout();
        } else {
            qWarning() << "AsyncRequestProcessor: No response handler to handle timeout error.";
        }
    }
}
