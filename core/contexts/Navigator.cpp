/*
 * File: Navigator.cpp
 * Author: michael.godfrey
 * Date: 04-25-2025
 * Description: This file contains the implementation of the Navigator class, which is responsible for managing the navigation of the application.
 */

#include "core/contexts/Navigator.h"

Navigator::Navigator(QObject *parent)
    : QObject(parent) // Initialize stack size to 10
{
}

void Navigator::push(const QString &viewName, const QVariantMap &params)
{
	if (viewName == m_currentViewName) {
		return;
	}

	NavigationEntry entry{.viewName = viewName, .params = params};
	m_navigationStack.push(entry);
	m_currentViewName = viewName;
	m_currentParams = params;
}

void Navigator::pop()
{
	if (m_navigationStack.empty()) {
		return;
	}

	m_navigationStack.pop();
}

void Navigator::replace(const QString &viewName, const QVariantMap &params)
{
	// replace on top
	if (m_navigationStack.empty()) {
		return;
	}

	NavigationEntry &topEntry = m_navigationStack.top();
	topEntry.viewName = viewName;
	topEntry.params = params;
	m_currentViewName = viewName;
	m_currentParams = params;
}

void Navigator::clear()
{
	while (!m_navigationStack.empty()) {
		m_navigationStack.pop();
	}
}

QString Navigator::currentViewName() const
{
	return m_currentViewName;
}

QVariantMap Navigator::currentParams() const
{
	return m_currentParams;
}
