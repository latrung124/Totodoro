/*
 * File: GuiApplication.cpp
 * Author: trung.la
 * Date: 02-06-2025
 * Description: This file contains the implementation of the GuiApplication class.
 */

#include "GuiApplication.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickWindow>

#include "core/controllers/ModelController.h"
#include "core/controllers/ViewModelController.h"

#include "core/services/queue/MessageQueue.h"

GuiApplication::GuiApplication(QGuiApplication *app, QObject *parent)
    : QObject(parent)
    , m_app(app)
    , m_modelController(std::make_unique<ModelController>())
    , m_viewModelController(std::make_unique<ViewModelController>())
    , m_engine(std::make_unique<QQmlApplicationEngine>())
{
}

GuiApplication::~GuiApplication()
{
	MessageQueue::getInstance().stop();
	endConnections();
}

void GuiApplication::startConnections()
{
	QObject *root = m_engine->rootObjects().first();
	if (!root) {
		return;
	}

	QQuickWindow *window = qobject_cast<QQuickWindow *>(root);
	if (!window) {
		return;
	}

	connect(window, &QQuickWindow::closing, m_app, &QGuiApplication::quit);
	connect(m_app, &QGuiApplication::aboutToQuit, this, &GuiApplication::end);
}

void GuiApplication::endConnections()
{
}

void GuiApplication::setContexts()
{
	m_engine->rootContext()->setContextProperty("viewModelController", m_viewModelController.get());
}

void GuiApplication::start()
{
	MessageQueue::getInstance().start();

	setContexts();

	m_engine->addImportPath("qrc:/resources/qml");
	m_engine->loadFromModule("Totodoro", "Main");
	if (m_engine->rootObjects().isEmpty()) {
		qFatal("Failed to load QML file.");
	}

	initViewModels();

	startConnections();
}

void GuiApplication::end()
{
	MessageQueue::getInstance().stop();
}

QObject *GuiApplication::rootObject() const
{
	QObject *root = m_engine->rootObjects().first();
	if (!root) {
		return nullptr;
	}

	return root;
}

void GuiApplication::initViewModels()
{
	m_viewModelController->registerViewModels();
	m_viewModelController->initMediaPlayerView(rootObject());
}
