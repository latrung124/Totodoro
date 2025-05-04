/*
 * File: TaskViewModel.h
 * Author: trung.la
 * Date: 05-02-2025
 * Description: View Model for Task.
 */

#ifndef TASKVIEWMODEL_H
#define TASKVIEWMODEL_H

#include <QObject>

#include "utils/qmltypes/PriorityTypeClass.h"

class TaskViewModel : public QObject
{
	Q_OBJECT
	Q_PROPERTY(int taskId READ taskId WRITE setTaskId NOTIFY taskIdChanged)
	Q_PROPERTY(QString taskName READ taskName WRITE setTaskName NOTIFY taskNameChanged)
	Q_PROPERTY(QString icon READ icon WRITE setIcon NOTIFY iconChanged)
	Q_PROPERTY(
	    int totalPomodoros READ totalPomodoros WRITE setTotalPomodoros NOTIFY totalPomodorosChanged)
	Q_PROPERTY(int completedPomodoros READ completedPomodoros WRITE setCompletedPomodoros NOTIFY
	               completedPomodorosChanged)
	Q_PROPERTY(
	    PriorityType priorityType READ priorityType WRITE setPriorityType NOTIFY priorityTypeChanged)
	Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)
	Q_PROPERTY(QString deadline READ deadline WRITE setDeadline NOTIFY deadlineChanged)

public:
	explicit TaskViewModel(QObject *parent = nullptr);
	~TaskViewModel() override;

	int taskId() const;
	void setTaskId(int id);

	QString taskName() const;
	void setTaskName(const QString &name);

	QString icon() const;
	void setIcon(const QString &iconPath);

	int totalPomodoros() const;
	void setTotalPomodoros(int count);

	int completedPomodoros() const;
	void setCompletedPomodoros(int count);

	PriorityType priorityType() const;
	void setPriorityType(PriorityType type);

	QString description() const;
	void setDescription(const QString &description);

	QString deadline() const;
	void setDeadline(const QString &deadline);

signals:
	void taskIdChanged();
	void taskNameChanged();
	void iconChanged();
	void totalPomodorosChanged();
	void completedPomodorosChanged();
	void priorityTypeChanged();
	void descriptionChanged();
	void deadlineChanged();

private:
	int m_taskId = 0; // TODO: Use a unique identifier for each task
	QString m_taskName;
	QString m_icon;
	int m_totalPomodoros = 0;
	int m_completedPomodoros = 0;
	PriorityType m_priorityType = PriorityType::Medium;
	QString m_description;
	QString m_deadline;
};

#endif // TASKVIEWMODEL_H
