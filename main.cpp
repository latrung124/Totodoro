/*
File: main.cpp
* Author: trung.la
* Date: 02-12-2025
* Description: This file contains the main function of the application.
*/
#include <QGuiApplication>
#include <QIcon>
#include <QQmlEngine>

#include <IWMediaService.h>

// TODO: move out of main
#include "core/GuiApplication.h"

#include "core/services/listeners/WMediaServiceListener.h"
#include "core/services/producer/ServiceMessageProducer.h"
#include "core/services/producer/window-service/WMediaInfoMessageCreator.h"
#include "core/services/producer/window-service/WNextAsyncMessageCreator.h"
#include "core/services/producer/window-service/WPauseAsyncMessageCreator.h"
#include "core/services/producer/window-service/WPlayAsyncMessageCreator.h"
#include "core/services/producer/window-service/WPlaybackControlsMessageCreator.h"
#include "core/services/producer/window-service/WPlaybackInfoMessageCreator.h"
#include "core/services/producer/window-service/WPreviousAsyncMessageCreator.h"
#include "core/services/producer/window-service/WTimelinePropertiesMessageCreator.h"
#include "core/services/ServiceManager.h"

#include "utils/qmltypes/DynamicObjectStateClass.h"
#include "utils/qmltypes/PriorityTypeClass.h"

#include "config/const_val/ApplicationConst.h"

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

void registerQmlTypes()
{
	qRegisterMetaType<PriorityType>("PriorityType");
	qmlRegisterUncreatableType<PriorityTypeClass>(
	    "App.Enums", // QML namespace
	    1,
	    0, // Major and minor versions
	    "PriorityType", // Enum group name in QML
	    "Cannot create PriorityType in QML. Access enums only.");

	qRegisterMetaType<DynamicObjectState>("DynamicObjectState");
	qmlRegisterUncreatableType<DynamicObjectStateClass>(
	    "App.Enums", // QML namespace
	    1,
	    0, // Major and minor versions
	    "DynamicObjectState", // Enum group name in QML
	    "Cannot create PriorityType in QML. Access enums only.");
}

void serviceRegister()
{
	// TODO: refactor later, move out of main
	auto service = ServiceManager::instance().registerService<IWMediaService>();
	if (service != nullptr) {
		service->registerListener(new WMediaServiceListener());

		// Register service creators for Service Producer/Factory
		auto producer = ServiceMessageProducer::getInstance();
		producer.registerCreator<WMediaInfoMessageCreator>();
		producer.registerCreator<WPlaybackControlsMessageCreator>();
		producer.registerCreator<WPlaybackInfoMessageCreator>();
		producer.registerCreator<WPlayAsyncMessageCreator>();
		producer.registerCreator<WPauseAsyncMessageCreator>();
		producer.registerCreator<WNextAsyncMessageCreator>();
		producer.registerCreator<WPreviousAsyncMessageCreator>();
		producer.registerCreator<WTimelinePropertiesMessageCreator>();
	}
}

int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);

	registerQmlTypes();

	setApplicationAttribute();
	setApplicationInfo();

	serviceRegister();

	GuiApplication guiApp(&app);
	guiApp.start();

	return app.exec();
}
