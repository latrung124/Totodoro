/*
File: main.cpp
* Author: trung.la
* Date: 02-12-2025
* Description: This file contains the main function of the application.
*/

#include "core/services/service-consumer/ServiceMessageConsumer.h"
#include "core/services/service-handlers/WMediaInfoMessageHandler.h"
#include "core/services/service-handlers/WNextAsyncMessageHandler.h"
#include "core/services/service-handlers/WPauseAsyncMessageHandler.h"
#include "core/services/service-handlers/WPlayAsyncMessageHandler.h"
#include "core/services/service-handlers/WPlaybackControlsMessageHandler.h"
#include "core/services/service-handlers/WPlaybackInfoMessageHandler.h"
#include "core/services/service-handlers/WPreviousAsyncMessageHandler.h"
#include "core/services/service-listeners/WMediaServiceListener.h"
#include "core/services/ServiceManager.h"
#include <IWMediaService.h>

#include "config/const_val/ApplicationConst.h"
#include "core/GuiApplication.h"

#include <QGuiApplication>
#include <QIcon>
#include <QQmlApplicationEngine>

void setApplicationAttribute()
{
#if defined(Q_OS_MACOS)
	QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
}

void setApplicationInfo()
{
	using namespace config::const_val::application;

	QGuiApplication::setOrganizationDomain(OrganizationDomain);
	QGuiApplication::setOrganizationName(OrganizationName);
	QGuiApplication::setApplicationName(ApplicationName);
	QGuiApplication::setApplicationDisplayName(ApplicationDisplayName);
	QGuiApplication::setApplicationVersion(ApplicationVersion);
	QGuiApplication::setWindowIcon(QIcon(ApplicationIcon));
}

void serviceRegister()
{
	auto service = ServiceManager::instance().registerService<IWMediaService>();
	if (service != nullptr) {
		service->registerListener(new WMediaServiceListener());
		ServiceMessageConsumer::getInstance().addHandler(
		    std::make_unique<WMediaInfoMessageHandler>());
		ServiceMessageConsumer::getInstance().addHandler(
		    std::make_unique<WPlaybackControlsMessageHandler>());
		ServiceMessageConsumer::getInstance().addHandler(
		    std::make_unique<WPlaybackInfoMessageHandler>());
		ServiceMessageConsumer::getInstance().addHandler(
		    std::make_unique<WPlayAsyncMessageHandler>());
		ServiceMessageConsumer::getInstance().addHandler(
		    std::make_unique<WPauseAsyncMessageHandler>());
		ServiceMessageConsumer::getInstance().addHandler(
		    std::make_unique<WNextAsyncMessageHandler>());
		ServiceMessageConsumer::getInstance().addHandler(
		    std::make_unique<WPreviousAsyncMessageHandler>());
	}
}

int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);

	setApplicationAttribute();
	setApplicationInfo();

	serviceRegister();

	GuiApplication guiApp(&app);
	guiApp.start();

	return app.exec();
}
