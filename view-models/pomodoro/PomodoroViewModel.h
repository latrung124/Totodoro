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
#include "utils/qmltypes/PomodoroStateClass.h"

class PomodoroViewModel : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString taskName READ taskName WRITE setTaskName NOTIFY taskNameChanged)
	Q_PROPERTY(QString taskDescription READ taskDescription WRITE setTaskDescription NOTIFY
	               taskDescriptionChanged)
	Q_PROPERTY(int pomodoroTime READ pomodoroTime WRITE setPomodoroTime NOTIFY pomodoroTimeChanged)
	Q_PROPERTY(
	    QString progressTime READ progressTime WRITE setProgressTime NOTIFY progressTimeChanged)
	Q_PROPERTY(
	    int shortBreakTime READ shortBreakTime WRITE setShortBreakTime NOTIFY shortBreakTimeChanged)
	Q_PROPERTY(
	    int longBreakTime READ longBreakTime WRITE setLongBreakTime NOTIFY longBreakTimeChanged)
	Q_PROPERTY(PomodoroState currentState READ currentState WRITE setCurrentState NOTIFY
	               currentStateChanged)
	Q_PROPERTY(DynamicObjectState dynamicObjectState READ getDynamicObjectState WRITE
	               setDynamicObjectState NOTIFY dynamicObjectStateChanged)
	Q_PROPERTY(int completedPomodoros READ completedPomodoros WRITE setCompletedPomodoros NOTIFY
	               completedPomodorosChanged)
	Q_PROPERTY(
	    QString dynamicObject READ dynamicObject WRITE setDynamicObject NOTIFY dynamicObjectChanged)
	Q_PROPERTY(
	    int totalTimeSpent READ totalTimeSpent WRITE setTotalTimeSpent NOTIFY totalTimeSpentChanged)

public:
	explicit PomodoroViewModel(QObject *parent = nullptr);
	~PomodoroViewModel() override;

	QString taskName() const;
	void setTaskName(const QString &name);

	QString taskDescription() const;
	void setTaskDescription(const QString &description);

	void setPomodoroTime(int time);
	int pomodoroTime() const;

	void setProgressTime(QString time);
	QString progressTime() const;

	void setShortBreakTime(int time);
	int shortBreakTime() const;

	void setLongBreakTime(int time);
	int longBreakTime() const;

	void setCurrentState(PomodoroState state);
	PomodoroState currentState() const;

	void setDynamicObjectState(DynamicObjectState state);
	DynamicObjectState getDynamicObjectState() const;

	void setCompletedPomodoros(int completedPomodoros);
	int completedPomodoros() const;

	void setDynamicObject(const QString &object);
	QString dynamicObject() const;

	void setTotalTimeSpent(int totalTime);
	int totalTimeSpent() const;

signals:
	void taskNameChanged();
	void taskDescriptionChanged();
	void pomodoroTimeChanged();
	void progressTimeChanged();
	void shortBreakTimeChanged();
	void longBreakTimeChanged();
	void currentStateChanged();
	void dynamicObjectStateChanged();
	void dynamicObjectChanged();
	void completedPomodorosChanged();
	void totalTimeSpentChanged();

private:
	void initDummyData();

	// Time in seconds
	int m_pomodoroTime = 0;
	int m_shortBreakTime = 0;
	int m_longBreakTime = 0;
	int m_completedPomodoros = 0;
	int m_totalTimeSpent = 0;
	PomodoroState m_currentState = PomodoroState::Idle;
	DynamicObjectState m_dynamicObjectState = DynamicObjectState::Egg; // Default state is Egg
	QString m_progressTime;
	QString m_dynamicObject;
	QString m_taskName;
	QString m_taskDescription;
};

#endif // POMODORO_VIEW_MODEL_H
