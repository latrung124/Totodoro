/*
 * File: PomodoroTitleViewModel.h
 * Author: trung.la
 * Date: 06-05-2025
 * Description: View Model for Pomodoro title.
 */

#ifndef POMODOROTITLEVIEWMODEL_H
#define POMODOROTITLEVIEWMODEL_H

#include <QObject>

class PomodoroTitleViewModel : public QObject
{
	Q_OBJECT

public:
	explicit PomodoroTitleViewModel(QObject *parent = nullptr);
	~PomodoroTitleViewModel() override;
};
#endif // POMODOROTITLEVIEWMODEL_H
