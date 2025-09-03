/**
 * @file IApiCommand.h
 * @author trung.la
 * @date 09-03-2025
 * @brief Interface for API command classes.
 */

#pragma once

#include "IResponseHandler.h"

#include <QObject>

#include <memory>

class IApiCommand : public QObject
{
    Q_OBJECT
public:
    IApiCommand(QObject* parent = nullptr) : QObject(parent) {}
    virtual ~IApiCommand() = default;

    // Execute the command
    virtual void execute() = 0;
    virtual void setResponseHandler(std::shared_ptr<IResponseHandler> handler) = 0;
    virtual std::shared_ptr<IResponseHandler> getResponseHandler() const = 0;
};
