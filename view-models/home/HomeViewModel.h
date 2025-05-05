/*
 * File: HomeViewModel.h
 * Author: trung.la
 * Date: 04-30-2025
 * Description: View Model for Home tab.
 */

#ifndef HOME_VIEW_MODEL_H
#define HOME_VIEW_MODEL_H

#include <QObject>

#include <memory>

class UserProfileViewModel;
class PomodoroViewModel;
class PomodoroTitleViewModel;
class TaskGroupsViewModel;
class TasksViewModel;

class HomeViewModel : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QObject *userProfile READ userProfile WRITE setUserProfile NOTIFY userProfileChanged)
	Q_PROPERTY(QObject *pomodoro READ pomodoro WRITE setPomodoro NOTIFY pomodoroChanged)
	Q_PROPERTY(QObject *taskGroups READ taskGroups WRITE setTaskGroups NOTIFY taskGroupsChanged)
	Q_PROPERTY(QObject *tasks READ tasks WRITE setTasks NOTIFY tasksChanged)
	Q_PROPERTY(QObject *pomodoroTitle READ pomodoroTitle NOTIFY pomodoroTitleChanged)

public:
	using UserProfileViewModelUPtr = std::unique_ptr<UserProfileViewModel>;
	using PomodoroViewModelUPtr = std::unique_ptr<PomodoroViewModel>;
	using PomodoroTitleViewModelUPtr = std::unique_ptr<PomodoroTitleViewModel>;
	using TaskGroupsViewModelUPtr = std::unique_ptr<TaskGroupsViewModel>;
	using TasksViewModelUPtr = std::unique_ptr<TasksViewModel>;

	explicit HomeViewModel(QObject *parent = nullptr);
	~HomeViewModel() override;

	QObject *userProfile() const;
	void setUserProfile(QObject *userProfile);

	QObject *pomodoro() const;
	void setPomodoro(QObject *pomodoro);

	QObject *pomodoroTitle() const;
	void setPomodoroTitle(QObject *pomodoroTitle);

	QObject *taskGroups() const;
	void setTaskGroups(QObject *taskGroups);

	QObject *tasks() const;
	void setTasks(QObject *tasks);

signals:
	void userProfileChanged();
	void pomodoroChanged();
	void pomodoroTitleChanged();
	void taskGroupsChanged();
	void tasksChanged();

private:
	void initDummyData();

	UserProfileViewModelUPtr m_userProfileViewModel;
	PomodoroViewModelUPtr m_pomodoroViewModel;
	PomodoroTitleViewModelUPtr m_pomodoroTitleViewModel;
	TaskGroupsViewModelUPtr m_taskGroupsViewModel;
	TasksViewModelUPtr m_tasksViewModel;
};

#endif // HOME_VIEW_MODEL_H
