/**
 * @file PomodoroApiClientFactory.h
 * @author trung.la
 * @date 09-03-2025
 * @brief Factory for creating Pomodoro API client instances.
 */

#pragma once

#include <memory>

#include <QObject>
#include <QString>

#include "common/CommonDefine.h"

class ApiClientFactory
{
public:
	static std::unique_ptr<QObject> createClient(
	    gateway::RouteType routeType, const QString &baseUrl);
};

using ApiClientFactoryPtr = std::shared_ptr<ApiClientFactory>;
