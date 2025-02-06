/*
* File: GuiApplication.h
* Author: trung.la
* Date: 02-06-2025
* Description: This file contains the definition of the GuiApplication class.
*/

#ifndef GUIAPPLICATION_H
#define GUIAPPLICATION_H

#include <memory>

class QQmlApplicationEngine;

class ModelController;
class ViewModelController;
class ConnectionManager;

class GuiApplication
{
public:
    using ModelControllerPtr = std::unique_ptr<ModelController>;
    using ViewModelControllerPtr = std::unique_ptr<ViewModelController>;
    using ConnectionManagerPtr = std::unique_ptr<ConnectionManager>;

    explicit GuiApplication(QQmlApplicationEngine *engine);
    ~GuiApplication();

    void init();

private:
    void loadModule();
    void initConnection();

    QQmlApplicationEngine* m_engine = nullptr;
    ModelControllerPtr m_modelController = nullptr;
    ViewModelControllerPtr m_viewModelController = nullptr;
    ConnectionManagerPtr m_connectionManager = nullptr;
};

#endif // GUIAPPLICATION_H