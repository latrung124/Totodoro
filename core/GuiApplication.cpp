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

#include "core/controllers/ViewModelController.h"

#include "core/services/queue/MessageQueue.h"

GuiApplication::GuiApplication(QGuiApplication *app, QObject *parent)
    : QObject(parent)
    , m_app(app)
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
	m_engine->rootContext()->setContextProperty(
	    "viewModelController", &ViewModelController::getInstance());
}

void GuiApplication::start()
{
	MessageQueue::getInstance().start();

	setContexts();

	m_engine->addImportPath("qrc:/resources/qml");

	// Handle objectCreated signal
	connect(
	    m_engine.get(),
	    &QQmlApplicationEngine::objectCreated,
	    this,
	    [this](QObject *obj, const QUrl &url) {
		    Q_UNUSED(url);
		    if (!obj) {
			    qFatal("Failed to load QML file.");
		    }

		    ViewModelController::getInstance().setRootObject(obj);
	    });

	m_engine->loadFromModule("Totodoro", "Main");
	if (m_engine->rootObjects().isEmpty()) {
		qFatal("Failed to load QML file.");
	}

	initViewModels();

	// Start some connections after the mainwindow was loaded.
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
	auto &vmController = ViewModelController::getInstance();

	vmController.registerViewModels();

	vmController.initMediaPlayerView();
	vmController.initHomeView(); // Start with Home View
}
