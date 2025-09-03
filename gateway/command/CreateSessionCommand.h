/**
 * @file CreateSessionCommand.h
 * @author trung.la
 * @date 09-03-2025
 * @brief Command to create a Pomodoro session via the Pomodoro API.
 */

#pragma once

#include "IApiCommand.h"

class CreateSessionCommand : public IApiCommand
{
public:
    CreateSessionCommand() = default;
    ~CreateSessionCommand() override = default;

    void execute() override;
    void setResponseHandler(IResponseHandlerPtr handler) override;
    IResponseHandlerPtr getResponseHandler() const override;
};