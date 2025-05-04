/*
 * File: UserProfileViewModel.h
 * Author: trung.la
 * Date: 04-30-2025
 * Description: View Model for UserProfile.
 */

#ifndef USERPROFILEVIEWMODEL_H
#define USERPROFILEVIEWMODEL_H

#include <QObject>

class UserProfileViewModel : public QObject
{
	Q_OBJECT

public:
	explicit UserProfileViewModel(QObject *parent = nullptr);
	~UserProfileViewModel() override;
};

#endif // USERPROFILEVIEWMODEL_H
