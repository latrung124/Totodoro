/*
 * File: WindowNavigator.h
 * Author: trung.la
 * Date: 02-23-2025
 * Description: This file contains the definition of the WindowNavigator class.
 */

#ifndef WINDOWNAVIGATOR_H
#define WINDOWNAVIGATOR_H

#include "core/contexts/Context.h"

class WindowNavigator : public Context
{
	Q_OBJECT

public:
	WindowNavigator(QObject *obj = nullptr);
	virtual ~WindowNavigator();

public slots:
	void closeWindow();
	void maximizeWindow();
	void minimizeWindow();
};

#endif // WINDOWNAVIGATOR_H
