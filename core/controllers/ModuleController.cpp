/*
 * File: ModuleController.cpp
 * Author: trung.la
 * Date: 02-19-2025
 * Description: This file contains the implementation of the ModuleController class.
 */

#include "ModuleController.h"

#include <QQmlApplicationEngine>

ModuleController::ModuleController(QObject *parent)
    : QObject(parent),
    m_engine(std::make_shared<QQmlApplicationEngine>())
{
    startConnections();
}

ModuleController::~ModuleController()
{
	m_engine->deleteLater();
	endConnections();
}

void ModuleController::loadModule(const QString &moduleName, const QString &moduleComponent)
{
	m_engine->loadFromModule(moduleName, moduleComponent);
}

void ModuleController::startConnections()
{
	const auto engine = m_engine.get();
	connect(engine, &QQmlApplicationEngine::objectCreationFailed, this, [this]() {
		emit moduleLoadedFailed();
	}, Qt::QueuedConnection);

	connect(engine, &QQmlApplicationEngine::objectCreated, this, [this](QObject *obj, const QUrl &url) {
		if (!obj) {
			qWarning() << "Failed to create object from url: " << url;
			emit moduleLoadedFailed();
		}
		emit moduleLoadedSuccess();
	}, Qt::QueuedConnection);

	connect(engine, &QQmlApplicationEngine::quit, this, [this]() {
		emit destroyModule();
	}, Qt::QueuedConnection);
}

void ModuleController::endConnections()
{
	const auto engine = m_engine.get();
	disconnect(engine, &QQmlApplicationEngine::objectCreationFailed, this, nullptr);

	disconnect(engine, &QQmlApplicationEngine::objectCreated, this, nullptr);
}
