/*
 * File: PomodoroViewModel.h
 * Author: trung.la
 * Date: 05-03-2025
 * Description: View Model for Pomodoro Screen
 */

#ifndef POMODORO_VIEW_MODEL_H
#define POMODORO_VIEW_MODEL_H

#include <QObject>

#include "utils/qmltypes/DynamicObjectStateClass.h"

class PomodoroViewModel : public QObject
{
	Q_OBJECT
	Q_PROPERTY(int pomodoroTime READ pomodoroTime WRITE setPomodoroTime NOTIFY pomodoroTimeChanged)
	Q_PROPERTY(int progressTime READ progressTime WRITE setProgressTime NOTIFY progressTimeChanged)
	Q_PROPERTY(
	    int shortBreakTime READ shortBreakTime WRITE setShortBreakTime NOTIFY shortBreakTimeChanged)
	Q_PROPERTY(
	    int longBreakTime READ longBreakTime WRITE setLongBreakTime NOTIFY longBreakTimeChanged)
	Q_PROPERTY(int currentState READ currentState WRITE setCurrentState NOTIFY currentStateChanged)
	Q_PROPERTY(DynamicObjectState dynamicObjectState READ getDynamicObjectState WRITE
	               setDynamicObjectState NOTIFY dynamicObjectStateChanged)
	Q_PROPERTY(int pomodoroCompleted READ pomodoroCompleted WRITE setPomodoroCompleted NOTIFY
	               pomodoroCompletedChanged)
	Q_PROPERTY(
	    QString dynamicObject READ dynamicObject WRITE setDynamicObject NOTIFY dynamicObjectChanged)

public:
	explicit PomodoroViewModel(QObject *parent = nullptr);
	~PomodoroViewModel() override;

	void setPomodoroTime(int time);
	int pomodoroTime() const;

	void setProgressTime(int time);
	int progressTime() const;

	void setShortBreakTime(int time);
	int shortBreakTime() const;

	void setLongBreakTime(int time);
	int longBreakTime() const;

	void setCurrentState(int state);
	int currentState() const;

	void setDynamicObjectState(DynamicObjectState state);
	DynamicObjectState getDynamicObjectState() const;

	void setPomodoroCompleted(int completed);
	int pomodoroCompleted() const;

	void setDynamicObject(const QString &object);
	QString dynamicObject() const;

signals:
	void pomodoroTimeChanged();
	void progressTimeChanged();
	void shortBreakTimeChanged();
	void longBreakTimeChanged();
	void currentStateChanged();
	void dynamicObjectStateChanged();
	void pomodoroCompletedChanged();
	void dynamicObjectChanged();

private:
	// Time in seconds
	int m_pomodoroTime = 0;
	int m_progressTime = 0;
	int m_shortBreakTime = 0;
	int m_longBreakTime = 0;
	int m_currentState = 0;
	int m_pomodoroCompleted = 0;
	QString m_dynamicObject;
	DynamicObjectState m_dynamicObjectState = DynamicObjectState::Egg; // Default state is Egg
};

#endif // POMODORO_VIEW_MODEL_H
