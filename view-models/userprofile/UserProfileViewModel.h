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
	Q_PROPERTY(QString displayName READ displayName WRITE setDisplayName NOTIFY displayNameChanged)
	Q_PROPERTY(QString avatarUrl READ avatarUrl WRITE setAvatarUrl NOTIFY avatarUrlChanged)

public:
	explicit UserProfileViewModel(QObject *parent = nullptr);
	~UserProfileViewModel() override;

	QString displayName() const;
	void setDisplayName(const QString &displayName);

	QString email() const;
	void setEmail(const QString &email);

	QString avatarUrl() const;
	void setAvatarUrl(const QString &avatarUrl);

signals:
	void displayNameChanged(const QString &displayName);
	void avatarUrlChanged(const QString &avatarUrl);
	void emailChanged(const QString &email);

public slots:
	void onDisplayNameChanged(const QString &displayName);
	void onAvatarUrlChanged(const QString &avatarUrl);
	void onEmailChanged(const QString &email);

private:
	QString m_displayName;
	QString m_avatarUrl;
	QString m_email;
};

#endif // USERPROFILEVIEWMODEL_H
