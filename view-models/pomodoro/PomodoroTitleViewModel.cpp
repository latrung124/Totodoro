/*
 * File: PomodoroTitleViewModel.cpp
 * Author: trung.la
 * Date: 06-05-2025
 * Description: View Model for Pomodoro title.
 */

#include "PomodoroTitleViewModel.h"

PomodoroTitleViewModel::PomodoroTitleViewModel(QObject *parent)
    : QObject(parent)
{
	initDummyData();
}

PomodoroTitleViewModel::~PomodoroTitleViewModel()
{
}

void PomodoroTitleViewModel::initDummyData()
{
	// Initialize with dummy data
	m_title = "Default Task Group";
	m_icon = "default_icon.png"; // TODO: Replace with actual icon path and update in qml bindings
}

QString PomodoroTitleViewModel::title() const
{
	return m_title;
}

void PomodoroTitleViewModel::setTitle(const QString &title)
{
	if (m_title != title) {
		m_title = title;
		emit titleChanged();
	}
}

QString PomodoroTitleViewModel::icon() const
{
	return m_icon;
}

void PomodoroTitleViewModel::setIcon(const QString &icon)
{
	if (m_icon != icon) {
		m_icon = icon;
		emit iconChanged();
	}
}
