/*
File: main.cpp
* Author: trung.la
* Date: 02-12-2025
* Description: This file contains the main function of the application.
*/

#include "core/services/ServiceManager.h"
#include "core/handlers/service-listeners/WMediaServiceListener.h"
#include "interfaces/window-services/IWMediaService.h"

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
	if (service != nullptr)
		service->registerListener(new WMediaServiceListener());
}

int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);

	setApplicationAttribute();
	setApplicationInfo();

	serviceRegister();

	QQmlApplicationEngine engine;
	QObject::connect(
	    &engine,
	    &QQmlApplicationEngine::objectCreationFailed,
	    &app,
	    []() { QCoreApplication::exit(-1); },
	    Qt::QueuedConnection);

	GuiApplication guiApp(&engine);
	guiApp.init();

	return app.exec();
}
