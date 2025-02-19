/*
 * File: ModuleController.h
 * Author: trung.la
 * Date: 02-19-2025
 * Description: This file contains the declaration of the ModuleController class.
 */

#ifndef MODULE_CONTROLLER_H
#define MODULE_CONTROLLER_H

#include <memory>

#include <QObject>

class QQmlApplicationEngine;

class ModuleController : public QObject
{
	Q_OBJECT

public:
	using EnginePtr = std::shared_ptr<QQmlApplicationEngine>;

	explicit ModuleController(QObject *parent = nullptr);
	virtual ~ModuleController();

	void loadModule(const QString &moduleName, const QString &moduleComponent);

signals:
	void moduleLoadedSuccess();
	void moduleLoadedFailed();
	void destroyModule();

private:
	void startConnections();
	void endConnections();

	EnginePtr m_engine = nullptr;
};

#endif // MODULE_CONTROLLER_H
