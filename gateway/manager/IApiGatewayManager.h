/**
 * @file IApiGatewayManager.h
 * @author trung.la
 * @date 09-22-2025
 * @brief This file contains the declaration of the IApiGatewayManager interface.
 */

#pragma once

#include <QObject>

class IApiGatewayManager : public QObject
{
    Q_OBJECT
public:
    explicit IApiGatewayManager(QObject* parent = nullptr) : QObject(parent) {}
    virtual ~IApiGatewayManager() = default;
};
