/**
 * @file CreateSessionCommand.cpp
 * @author trung.la
 * @date 09-03-2025
 * @brief Implementation of CreateSessionCommand to create a Pomodoro session via the Pomodoro API.
 */

#include "CreateSessionCommand.h"

void CreateSessionCommand::execute()
{
    // Implementation to call the Pomodoro API to create a session
    // This is a placeholder; actual implementation would involve using the OAIPomodoroServiceApi
}

void CreateSessionCommand::setResponseHandler(IResponseHandlerPtr handler)
{
}

IResponseHandlerPtr CreateSessionCommand::getResponseHandler() const
{
    return nullptr; // Placeholder; actual implementation would return the stored response handler
}

