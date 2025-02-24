/*
 * File: WindowNavigator.cpp
 * Author: trung.la
 * Date: 02-23-2025
 * Description: This file contains the implementation of the WindowNavigator class.
 */

#include "core/contexts/WindowNavigator.h"
#include <QDebug>

WindowNavigator::WindowNavigator(QObject *obj)
    : Context(obj)
{
}

WindowNavigator::~WindowNavigator()
{
}

void WindowNavigator::closeWindow()
{
	// Close the window
}

void WindowNavigator::maximizeWindow()
{
	// Maximize the window
}

void WindowNavigator::minimizeWindow()
{
	// Minimize the window
}
