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

class QQmlApplicationEngine;

class GuiApplication : public QObject
{
	Q_OBJECT

public:
	using QQmlApplicationEnginePtr = std::unique_ptr<QQmlApplicationEngine>;

	explicit GuiApplication(QGuiApplication *app, QObject *parent = nullptr);
	~GuiApplication();

	void start();
	void end();

	QObject *rootObject() const;

signals:
	void destroySignal();

private:
	void startConnections();
	void endConnections();

	void initViewModels();
	void setContexts();

	QGuiApplication *m_app = nullptr;
	QQmlApplicationEnginePtr m_engine = nullptr;
};

#endif // GUIAPPLICATION_H
