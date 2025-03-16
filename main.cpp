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
#include "core/services/service-handlers/WTimelinePropertiesMessageHandler.h"

#include "core/services/service-listeners/WMediaServiceListener.h"

// TODO: move out of main
#include "core/services/service-producer/ServiceMessageProducer.h"
#include "core/services/service-producer/window-service/WMediaInfoMessageCreator.h"
#include "core/services/service-producer/window-service/WNextAsyncMessageCreator.h"
#include "core/services/service-producer/window-service/WPauseAsyncMessageCreator.h"
#include "core/services/service-producer/window-service/WPlayAsyncMessageCreator.h"
#include "core/services/service-producer/window-service/WPlaybackControlsMessageCreator.h"
#include "core/services/service-producer/window-service/WPlaybackInfoMessageCreator.h"
#include "core/services/service-producer/window-service/WPreviousAsyncMessageCreator.h"
#include "core/services/service-producer/window-service/WTimelinePropertiesMessageCreator.h"

#include "core/services/ServiceManager.h"
#include <IWMediaService.h>

#include "config/const_val/ApplicationConst.h"
#include "core/GuiApplication.h"

#include <QGuiApplication>
#include <QIcon>

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
	// TODO: refactor later, move out of main
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
		ServiceMessageConsumer::getInstance().addHandler(
		    std::make_unique<WTimelinePropertiesMessageHandler>());

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

	setApplicationAttribute();
	setApplicationInfo();

	serviceRegister();

	GuiApplication guiApp(&app);
	guiApp.start();

	return app.exec();
}
