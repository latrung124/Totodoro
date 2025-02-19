/*
 * File: GuiApplication.cpp
 * Author: trung.la
 * Date: 02-06-2025
 * Description: This file contains the implementation of the GuiApplication class.
 */

#include "GuiApplication.h"

#include <QGuiApplication>

#include "core/controllers/ModelController.h"
#include "core/controllers/ModuleController.h"
#include "core/controllers/ViewModelController.h"

GuiApplication::GuiApplication(QGuiApplication *app, QObject *parent)
    : QObject(parent)
    , m_app(app)
    , m_modelController(std::make_unique<ModelController>())
    , m_viewModelController(std::make_unique<ViewModelController>())
    , m_moduleController(std::make_unique<ModuleController>())
{
	startConnections();
}

GuiApplication::~GuiApplication()
{
	endConnections();
}

void GuiApplication::startConnections()
{
	const auto moduleController = m_moduleController.get();
	connect(
	    moduleController,
	    &ModuleController::moduleLoadedSuccess,
	    this,
	    &GuiApplication::construct,
	    Qt::QueuedConnection);

	connect(
	    moduleController,
	    &ModuleController::destroyModule,
	    this,
	    &GuiApplication::destroy,
	    Qt::QueuedConnection);
}

void GuiApplication::endConnections()
{
	const auto moduleController = m_moduleController.get();
	disconnect(moduleController, &ModuleController::moduleLoadedSuccess, this, nullptr);

	disconnect(moduleController, &ModuleController::destroyModule, this, nullptr);
}

void GuiApplication::start()
{
	// Start the application & services
	m_moduleController->loadModule("Totodoro", "Main");
}

void GuiApplication::end()
{
	// End the application & services
	m_app->quit();
}

void GuiApplication::construct()
{
	// Construct the necessary variable & component
}

void GuiApplication::destroy()
{
	// Destroy the necessary variable & component
}
