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
	Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged)
	Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
	Q_PROPERTY(QString icon READ icon WRITE setIcon NOTIFY iconChanged)
	Q_PROPERTY(
	    int totalPomodoros READ totalPomodoros WRITE setTotalPomodoros NOTIFY totalPomodorosChanged)
	Q_PROPERTY(int completedPomodoros READ completedPomodoros WRITE setCompletedPomodoros NOTIFY
	               completedPomodorosChanged)
	Q_PROPERTY(PriorityType priority READ priority WRITE setPriority NOTIFY priorityChanged)
	Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)
	Q_PROPERTY(QString dueDate READ dueDate WRITE setDueDate NOTIFY dueDateChanged)

public:
	explicit TaskViewModel(QObject *parent = nullptr);
	~TaskViewModel() override;

	int id() const;
	void setId(int id);

	QString name() const;
	void setName(const QString &name);

	QString icon() const;
	void setIcon(const QString &iconPath);

	int totalPomodoros() const;
	void setTotalPomodoros(int count);

	int completedPomodoros() const;
	void setCompletedPomodoros(int count);

	PriorityType priority() const;
	void setPriority(PriorityType type);

	QString description() const;
	void setDescription(const QString &description);

	QString dueDate() const;
	void setDueDate(const QString &dueDate);

signals:
	void idChanged();
	void nameChanged();
	void iconChanged();
	void totalPomodorosChanged();
	void completedPomodorosChanged();
	void priorityChanged();
	void descriptionChanged();
	void dueDateChanged();

private:
	int m_id = 0; // TODO: Use a unique identifier for each task
	QString m_name;
	QString m_icon;
	int m_totalPomodoros = 0;
	int m_completedPomodoros = 0;
	PriorityType m_priority = PriorityType::Medium;
	QString m_description;
	QString m_dueDate;
};

#endif // TASKVIEWMODEL_H
