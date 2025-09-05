/**
 * @file AsyncRequestProcessor.h
 * @author trung.la
 * @date 09-05-2025
 * @brief Interface for processing asynchronous requests in the gateway module.
 */

#pragma once

#include <memory>

#include <QObject>

class IApiCommand;

class AsyncRequestProcessor : public QObject
{
    Q_OBJECT
public:
    using IApiCommandPtr = std::shared_ptr<IApiCommand>;
    explicit AsyncRequestProcessor(QObject* parent = nullptr) : QObject(parent) {}
    virtual ~AsyncRequestProcessor() = default;

    /**
     * @brief Processes the given API command asynchronously, waiting for completion or timeout.
     * @param command The API command to process.
     * @param timeoutMs The maximum time to wait for the command to complete, in milliseconds. Default is 5000 ms.
     * If the command does not complete within this time, it will be aborted.
     */
    void processCommand(IApiCommandPtr command, int timeoutMs = 5000);
};