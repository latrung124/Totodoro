/*
* File: TaskGroupsViewModel.h
* Author: trung.la
* Date: 04-30-2025
* Description: View Model for TaskGroups.
*/

#ifndef TASKGROUPSVIEWMODEL_H
#define TASKGROUPSVIEWMODEL_H

#include <QObject>

class TaskGroupsViewModel : public QObject
{
    Q_OBJECT

public:
    explicit TaskGroupsViewModel(QObject *parent = nullptr);
    ~TaskGroupsViewModel() override;
};
#endif // TASKGROUPSVIEWMODEL_H
