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

/**
 * @brief Interface for API command classes.
 * Inherits from QObject to leverage Qt's signal-slot mechanism.
 * Each command should implement the execute method to perform its action.
 */
class IApiCommand : public QObject
{
    Q_OBJECT
public:
    IApiCommand(QObject* parent = nullptr) : QObject(parent) {}
    virtual ~IApiCommand() = default;

    /// Execute the command
    virtual void execute() = 0;

    /// Set and get the response handler
    virtual void setResponseHandler(std::shared_ptr<IResponseHandler> handler) = 0;

    /// Get the response handler
    virtual std::shared_ptr<IResponseHandler> getResponseHandler() const = 0;

signals:
    /// Signal emitted when the command is completed
    void completed(bool success);
};
