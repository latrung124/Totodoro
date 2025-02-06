#include "config/const_val/ApplicationConst.h"
#include "core/GuiApplication.h"

#include <QGuiApplication>
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
}

int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);

	setApplicationAttribute();
	setApplicationInfo();

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
