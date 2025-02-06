/*
* File: GuiApplication.cpp
* Author: trung.la
* Date: 02-06-2025
* Description: This file contains the implementation of the GuiApplication class.
*/

#include "GuiApplication.h"

#include "core/controllers/ModelController.h"
#include "core/controllers/ViewModelController.h"

#include "core/connections/ConnectionManager.h"

#include <QQmlApplicationEngine>

GuiApplication::GuiApplication(QQmlApplicationEngine *engine)
    : m_engine(engine)
    , m_modelController(std::make_unique<ModelController>())
    , m_viewModelController(std::make_unique<ViewModelController>())
    , m_connectionManager(std::make_unique<ConnectionManager>())
{
}

GuiApplication::~GuiApplication()
{
}

void GuiApplication::init()
{
    loadModule();
    initConnection();
}

void GuiApplication::loadModule()
{
    if (!m_engine) {
        return;
    }

    m_engine->loadFromModule("Totodoro", "Main");
}

void GuiApplication::initConnection()
{
    if (!m_connectionManager) {
        return;
    }

    m_connectionManager->connectViewModelAndModel(m_viewModelController.get(), m_modelController.get());
}