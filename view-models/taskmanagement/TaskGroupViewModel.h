/*
 * File: TaskGroupViewModel.h
 * Author: trung.la
 * Date: 05-01-2025
 * Description: View Model for TaskGroup.
 */

#ifndef TASKGROUPVIEWMODEL_H
#define TASKGROUPVIEWMODEL_H

#include <QObject>

#include <memory>

#include "utils/qmltypes/PriorityTypeClass.h"

class TasksViewModel;

class TaskGroupViewModel : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QString taskGroupId READ taskGroupId WRITE setTaskGroupId NOTIFY taskGroupIdChanged)
	Q_PROPERTY(QString icon READ icon WRITE setIcon NOTIFY iconChanged)
	Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
	Q_PROPERTY(QString deadline READ deadline WRITE setDeadline NOTIFY deadlineChanged)
	Q_PROPERTY(PriorityType priority READ priority WRITE setPriority NOTIFY priorityChanged)
	Q_PROPERTY(QString status READ status WRITE setStatus NOTIFY statusChanged)
	Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)
	Q_PROPERTY(
	    int completedTasks READ completedTasks WRITE setCompletedTasks NOTIFY completedTasksChanged)
	Q_PROPERTY(int totalTasks READ totalTasks WRITE setTotalTasks NOTIFY totalTasksChanged)
	Q_PROPERTY(QObject *tasks READ tasks WRITE setTasks NOTIFY tasksChanged)

public:
	using TasksViewModelPtr = std::shared_ptr<TasksViewModel>;

	explicit TaskGroupViewModel(QObject *parent = nullptr);
	~TaskGroupViewModel() override;

	void setTaskGroupId(const QString &taskGroupId);
	QString taskGroupId() const;

	void setIcon(const QString &icon);
	QString icon() const;

	void setName(const QString &name);
	QString name() const;

	void setDeadline(const QString &deadline);
	QString deadline() const;

	void setPriority(const PriorityType &priority);
	PriorityType priority() const;

	void setStatus(const QString &status);
	QString status() const;

	void setDescription(const QString &description);
	QString description() const;

	void setCompletedTasks(int completedTasks);
	int completedTasks() const;

	void setTotalTasks(int totalTasks);
	int totalTasks() const;

	void setTasks(const QObject *tasks);
	QObject *tasks() const;

signals:
	void taskGroupIdChanged();
	void iconChanged();
	void nameChanged();
	void deadlineChanged();
	void priorityChanged();
	void statusChanged();
	void descriptionChanged();
	void completedTasksChanged();
	void totalTasksChanged();
	void tasksChanged();

private:
	int m_completedTasks = 0;
	int m_totalTasks = 0;
	QString m_taskGroupId;
	QString m_icon;
	QString m_name;
	QString m_deadline;
	PriorityType m_priority = PriorityType::Medium;
	QString m_status;
	QString m_description;
	TasksViewModelPtr m_tasks;
};

#endif // TASKGROUPVIEWMODEL_H
