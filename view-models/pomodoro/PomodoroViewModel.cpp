/*
 * File: PomodoroViewModel.cpp
 * Author: trung.la
 * Date: 05-03-2025
 * Description: View Model for Pomodoro Screen
 */

#include "PomodoroViewModel.h"

PomodoroViewModel::PomodoroViewModel(QObject *parent)
    : QObject(parent)
{
	initDummyData();
}

PomodoroViewModel::~PomodoroViewModel()
{
}

void PomodoroViewModel::initDummyData()
{
	setPomodoroTime(25 * 60); // 25 minutes
	setProgressTime(5 * 60); // 5 minutes
	setShortBreakTime(5 * 60); // 5 minutes
	setLongBreakTime(15 * 60); // 15 minutes
	setCurrentState(PomodoroState::Idle); // Initial state
	setDynamicObjectState(DynamicObjectState::Egg);
	setPomodoroCompleted(0);
	setDynamicObject("default");
}

void PomodoroViewModel::setPomodoroTime(int time)
{
	if (m_pomodoroTime != time) {
		m_pomodoroTime = time;
		emit pomodoroTimeChanged();
	}
}

int PomodoroViewModel::pomodoroTime() const
{
	return m_pomodoroTime;
}

void PomodoroViewModel::setProgressTime(int time)
{
	if (m_progressTime != time) {
		m_progressTime = time;
		emit progressTimeChanged();
	}
}

int PomodoroViewModel::progressTime() const
{
	return m_progressTime;
}

void PomodoroViewModel::setShortBreakTime(int time)
{
	if (m_shortBreakTime != time) {
		m_shortBreakTime = time;
		emit shortBreakTimeChanged();
	}
}

int PomodoroViewModel::shortBreakTime() const
{
	return m_shortBreakTime;
}

void PomodoroViewModel::setLongBreakTime(int time)
{
	if (m_longBreakTime != time) {
		m_longBreakTime = time;
		emit longBreakTimeChanged();
	}
}

int PomodoroViewModel::longBreakTime() const
{
	return m_longBreakTime;
}

void PomodoroViewModel::setCurrentState(PomodoroState state)
{
	if (m_currentState != state) {
		m_currentState = state;
		emit currentStateChanged();
	}
}

PomodoroState PomodoroViewModel::currentState() const
{
	return m_currentState;
}

void PomodoroViewModel::setDynamicObjectState(DynamicObjectState state)
{
	if (m_dynamicObjectState != state) {
		m_dynamicObjectState = state;
		emit dynamicObjectStateChanged();
	}
}

DynamicObjectState PomodoroViewModel::getDynamicObjectState() const
{
	return m_dynamicObjectState;
}

void PomodoroViewModel::setPomodoroCompleted(int completed)
{
	if (m_pomodoroCompleted != completed) {
		m_pomodoroCompleted = completed;
		emit pomodoroCompletedChanged();
	}
}

int PomodoroViewModel::pomodoroCompleted() const
{
	return m_pomodoroCompleted;
}

void PomodoroViewModel::setDynamicObject(const QString &object)
{
	if (m_dynamicObject != object) {
		m_dynamicObject = object;
		emit dynamicObjectChanged();
	}
}

QString PomodoroViewModel::dynamicObject() const
{
	return m_dynamicObject;
}
