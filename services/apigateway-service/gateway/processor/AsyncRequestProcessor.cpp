/**
 * @file AsyncRequestProcessor.cpp
 * @author trung.la
 * @date 09-05-2025
 * @brief Implementation of AsyncRequestProcessor for processing asynchronous API commands.
 */

#include "AsyncRequestProcessor.h"

#include <QDebug>
#include <QEventLoop>
#include <QTimer>

#include "command/IApiCommand.h"
#include "handler/IResponseHandler.h"

bool AsyncRequestProcessor::processCommand(IApiCommandPtr command, int timeoutMs)
{
	if (!command) {
		qWarning() << "AsyncRequestProcessor: Command is null.";
		return false;
	}

	QEventLoop loop;
	QTimer timer;
	timer.setSingleShot(true);

	// Connect to command completion
	QObject::connect(command.get(), &IApiCommand::completed, &loop, &QEventLoop::quit);
	QObject::connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);

	// Execute the command
	command->execute();

	// Start the timer
	timer.start(timeoutMs);

	// Start the event loop and wait for either the command to finish or the timeout
	loop.exec();

	// Check if we timed out
	if (!timer.isActive()) {
		// Timeout occurred, notify the response handler
		auto handler = command->getResponseHandler();
		if (handler) {
			handler->handleTimeout();
		}
		return false;
	}

	// Check if command was successful
	auto handler = command->getResponseHandler();
	return handler && handler->isSuccessful();
}
