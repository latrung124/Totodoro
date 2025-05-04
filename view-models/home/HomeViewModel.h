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
class TaskGroupsViewModel;

class HomeViewModel : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QObject *userProfile READ userProfile WRITE setUserProfile NOTIFY userProfileChanged)
	Q_PROPERTY(QObject *taskGroups READ taskGroups WRITE setTaskGroups NOTIFY taskGroupsChanged)

public:
	using UserProfileViewModelUPtr = std::unique_ptr<UserProfileViewModel>;
	using TaskGroupsViewModelUPtr = std::unique_ptr<TaskGroupsViewModel>;

	explicit HomeViewModel(QObject *parent = nullptr);
	~HomeViewModel() override;

	QObject *userProfile() const;
	void setUserProfile(QObject *userProfile);

	QObject *taskGroups() const;
	void setTaskGroups(QObject *taskGroups);

signals:
	void userProfileChanged();
	void taskGroupsChanged();

private:
	void initDummyData();

	UserProfileViewModelUPtr m_userProfileViewModel;
	TaskGroupsViewModelUPtr m_taskGroupsViewModel;
};

#endif // HOME_VIEW_MODEL_H
