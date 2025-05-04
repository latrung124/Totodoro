/*
 * File: TasksViewModel.h
 * Author: trung.la
 * Date: 05-01-2025
 * Description: View Model for Tasks.
 */

#ifndef TASKSVIEWMODEL_H
#define TASKSVIEWMODEL_H

#include <QAbstractListModel>

#include <memory>
#include <vector>

class TaskViewModel;

class TasksViewModel : public QAbstractListModel
{
	Q_OBJECT

public:
	using TaskViewModelPtr = std::shared_ptr<TaskViewModel>;

	enum TaskRoles
	{
		TaskIdRole = Qt::UserRole + 1,
		TaskNameRole,
		IconRole,
		TotalPomodorosRole,
		CompletedPomodorosRole,
		PriorityTypeRole,
		DescriptionRole,
		DeadlineRole
	};

	explicit TasksViewModel(QObject *parent = nullptr);
	~TasksViewModel() override;

	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
	QHash<int, QByteArray> roleNames() const override;

private:
	std::vector<TaskViewModelPtr> m_tasks;
};

#endif // TASKSVIEWMODEL_H
