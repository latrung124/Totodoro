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
	Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
	Q_PROPERTY(QString icon READ icon WRITE setIcon NOTIFY iconChanged)

public:
	explicit PomodoroTitleViewModel(QObject *parent = nullptr);
	~PomodoroTitleViewModel() override;

	QString title() const;
	void setTitle(const QString &title);

	QString icon() const;
	void setIcon(const QString &icon);

signals:
	void titleChanged();
	void iconChanged();

private:
	void initDummyData();

	QString m_title;
	QString m_icon;
};
#endif // POMODOROTITLEVIEWMODEL_H
