/*
 * File: TaskGroupsViewModel.h
 * Author: trung.la
 * Date: 04-30-2025
 * Description: View Model for TaskGroups.
 */

#ifndef TASKGROUPSVIEWMODEL_H
#define TASKGROUPSVIEWMODEL_H

#include <QAbstractListModel>

#include <memory>
#include <vector>

class TaskGroupViewModel;

class TaskGroupsViewModel : public QAbstractListModel
{
	Q_OBJECT

public:
	using TaskGroupViewModelPtr = std::shared_ptr<TaskGroupViewModel>;

	enum Role
	{
		TaskGroupIdRole = Qt::UserRole + 1,
		IconRole,
		NameRole,
		DeadlineRole,
		PriorityRole,
		StatusRole,
		DescriptionRole,
		CompletedTasksRole,
		TotalTasksRole,
		TasksRole
	};

	explicit TaskGroupsViewModel(QObject *parent = nullptr);
	~TaskGroupsViewModel() override;

	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
	QHash<int, QByteArray> roleNames() const override;

	Q_INVOKABLE QVariantMap get(int index) const; // Used for debug on qml
	TaskGroupViewModelPtr getTaskGroupById(const QString &taskGroupId) const;

public slots:
	void onTaskGroupAppended(const QString &taskGroupId);
	void onTaskGroupRemoved(const QString &taskGroupId);
	void onTaskGroupUpdated(const QString &taskGroupId);
	void onTaskGroupsCleared();

private:
	void initDummyData();

	std::vector<TaskGroupViewModelPtr> m_taskGroups;
};
#endif // TASKGROUPSVIEWMODEL_H
