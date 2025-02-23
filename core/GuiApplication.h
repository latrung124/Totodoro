/*
 * File: GuiApplication.h
 * Author: trung.la
 * Date: 02-06-2025
 * Description: This file contains the definition of the GuiApplication class.
 */

#ifndef GUIAPPLICATION_H
#define GUIAPPLICATION_H

#include <memory>

#include <QObject>

class QGuiApplication;

class ModelController;
class ViewModelController;
class ModuleController;
class Context;

class GuiApplication : public QObject
{
	Q_OBJECT

public:
	using ModelControllerPtr = std::unique_ptr<ModelController>;
	using ViewModelControllerPtr = std::unique_ptr<ViewModelController>;
	using ModuleControllerPtr = std::unique_ptr<ModuleController>;
	using ContextPtr = std::unique_ptr<Context>;

	explicit GuiApplication(QGuiApplication *app, QObject *parent = nullptr);
	~GuiApplication();

	void start();
	void end();

signals:
	void destroySignal();

public slots:
	void construct();
	void destroy();

private:
	void startConnections();
	void endConnections();

	QGuiApplication *m_app = nullptr;
	ModelControllerPtr m_modelController = nullptr;
	ViewModelControllerPtr m_viewModelController = nullptr;
	ModuleControllerPtr m_moduleController = nullptr;
	ContextPtr m_windowNavigator = nullptr;
};

#endif // GUIAPPLICATION_H
