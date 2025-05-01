/*
* File: TasksViewModel.h
* Author: trung.la
* Date: 05-01-2025
* Description: View Model for Tasks.
*/

#ifndef TASKSVIEWMODEL_H
#define TASKSVIEWMODEL_H

#include <QAbstractListModel>

class TasksViewModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit TasksViewModel(QObject *parent = nullptr);
    ~TasksViewModel() override;
};

#endif // TASKSVIEWMODEL_H