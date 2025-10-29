/**
 * @file UserSettingsViewModel.h
 * @author trung.la
 * @date 10-29-2025
 * @brief This file contains the declaration of the UserSettingsViewModel class.
 */

#ifndef USERSETTINGSVIEWMODEL_H
#define USERSETTINGSVIEWMODEL_H

#include <QObject>

class UserSettingsViewModel : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString userId READ userId WRITE setUserId NOTIFY userIdChanged)
	Q_PROPERTY(QString theme READ theme WRITE setTheme NOTIFY themeChanged)
	Q_PROPERTY(QString language READ language WRITE setLanguage NOTIFY languageChanged)
	Q_PROPERTY(uint32_t pomodoroDuration READ pomodoroDuration WRITE setPomodoroDuration NOTIFY
	               pomodoroDurationChanged)
	Q_PROPERTY(uint32_t shortBreakDuration READ shortBreakDuration WRITE setShortBreakDuration
	               NOTIFY shortBreakDurationChanged)
	Q_PROPERTY(uint32_t longBreakDuration READ longBreakDuration WRITE setLongBreakDuration NOTIFY
	               longBreakDurationChanged)
	Q_PROPERTY(uint32_t longBreakInterval READ longBreakInterval WRITE setLongBreakInterval NOTIFY
	               longBreakIntervalChanged)
	Q_PROPERTY(bool autoStartShortBreak READ autoStartShortBreak WRITE setAutoStartShortBreak NOTIFY
	               autoStartShortBreakChanged)
	Q_PROPERTY(bool autoStartLongBreak READ autoStartLongBreak WRITE setAutoStartLongBreak NOTIFY
	               autoStartLongBreakChanged)
	Q_PROPERTY(bool autoStartPomodoro READ autoStartPomodoro WRITE setAutoStartPomodoro NOTIFY
	               autoStartPomodoroChanged)
	Q_PROPERTY(bool shortBreakNotification READ shortBreakNotification WRITE
	               setShortBreakNotification NOTIFY shortBreakNotificationChanged)
	Q_PROPERTY(bool longBreakNotification READ longBreakNotification WRITE setLongBreakNotification
	               NOTIFY longBreakNotificationChanged)
	Q_PROPERTY(bool pomodoroNotification READ pomodoroNotification WRITE setPomodoroNotification
	               NOTIFY pomodoroNotificationChanged)
	Q_PROPERTY(
	    bool autoStartMusic READ autoStartMusic WRITE setAutoStartMusic NOTIFY autoStartMusicChanged)
	Q_PROPERTY(bool autoStartNextTask READ autoStartNextTask WRITE setAutoStartNextTask NOTIFY
	               autoStartNextTaskChanged)

public:
	explicit UserSettingsViewModel(QObject *parent = nullptr);

	~UserSettingsViewModel() override;

	QString userId() const;
	void setUserId(const QString &userId);

	QString theme() const;
	void setTheme(const QString &theme);

	QString language() const;
	void setLanguage(const QString &language);

	uint32_t pomodoroDuration() const;
	void setPomodoroDuration(uint32_t duration);

	uint32_t shortBreakDuration() const;
	void setShortBreakDuration(uint32_t duration);

	uint32_t longBreakDuration() const;
	void setLongBreakDuration(uint32_t duration);

	uint32_t longBreakInterval() const;
	void setLongBreakInterval(uint32_t interval);

	bool autoStartShortBreak() const;
	void setAutoStartShortBreak(bool autoStart);

	bool autoStartLongBreak() const;
	void setAutoStartLongBreak(bool autoStart);

	bool autoStartPomodoro() const;
	void setAutoStartPomodoro(bool autoStart);

	bool shortBreakNotification() const;
	void setShortBreakNotification(bool enabled);

	bool longBreakNotification() const;
	void setLongBreakNotification(bool enabled);

	bool pomodoroNotification() const;
	void setPomodoroNotification(bool enabled);

	bool autoStartMusic() const;
	void setAutoStartMusic(bool autoStart);

	bool autoStartNextTask() const;
	void setAutoStartNextTask(bool autoStart);

signals:
	void userIdChanged(const QString &userId);
	void themeChanged(const QString &theme);
	void languageChanged(const QString &language);
	void pomodoroDurationChanged(uint32_t duration);
	void shortBreakDurationChanged(uint32_t duration);
	void longBreakDurationChanged(uint32_t duration);
	void longBreakIntervalChanged(uint32_t interval);
	void autoStartShortBreakChanged(bool autoStart);
	void autoStartLongBreakChanged(bool autoStart);
	void autoStartPomodoroChanged(bool autoStart);
	void shortBreakNotificationChanged(bool enabled);
	void longBreakNotificationChanged(bool enabled);
	void pomodoroNotificationChanged(bool enabled);
	void autoStartMusicChanged(bool autoStart);
	void autoStartNextTaskChanged(bool autoStart);

public slots:
	void onUserIdChanged(const QString &userId);
	void onThemeChanged(const QString &theme);
	void onLanguageChanged(const QString &language);
	void onPomodoroDurationChanged(uint32_t duration);
	void onShortBreakDurationChanged(uint32_t duration);
	void onLongBreakDurationChanged(uint32_t duration);
	void onLongBreakIntervalChanged(uint32_t interval);
	void onAutoStartShortBreakChanged(bool autoStart);
	void onAutoStartLongBreakChanged(bool autoStart);
	void onAutoStartPomodoroChanged(bool autoStart);
	void onShortBreakNotificationChanged(bool enabled);
	void onLongBreakNotificationChanged(bool enabled);
	void onPomodoroNotificationChanged(bool enabled);
	void onAutoStartMusicChanged(bool autoStart);
	void onAutoStartNextTaskChanged(bool autoStart);

private:
	QString m_userId;
	QString m_theme;
	QString m_language;
	uint32_t m_pomodoroDuration;
	uint32_t m_shortBreakDuration;
	uint32_t m_longBreakDuration;
	uint32_t m_longBreakInterval;
	bool m_autoStartShortBreak;
	bool m_autoStartLongBreak;
	bool m_autoStartPomodoro;
	bool m_shortBreakNotification;
	bool m_longBreakNotification;
	bool m_pomodoroNotification;
	bool m_autoStartMusic;
	bool m_autoStartNextTask;
};

#endif // USERSETTINGSVIEWMODEL_H
