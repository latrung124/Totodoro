/*
* File: Navigator.h
* Author: michael.godfrey
* Date: 04-25-2025
* Description: This file contains the Navigator class, which is responsible for managing the navigation of the application.
*/

#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include <QObject>
#include <QString>
#include <QVariantMap>

#include <stack>

class Navigator : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString currentViewName READ currentViewName NOTIFY currentViewNameChanged)
    Q_PROPERTY(QVariantMap currentParams READ currentParams NOTIFY currentParamsChanged)

public:
    explicit Navigator(QObject *parent = nullptr);

    Q_INVOKABLE void push(const QString &viewName, const QVariantMap &params = QVariantMap());
    Q_INVOKABLE void pop();
    Q_INVOKABLE void replace(const QString &viewName, const QVariantMap &params = QVariantMap());
    Q_INVOKABLE void clear();

    QString currentViewName() const;
    QVariantMap currentParams() const;

signals:
    void currentViewNameChanged(const QString &viewName);
    void currentParamsChanged(const QVariantMap &params);

    void viewPushed(const QString &viewName, const QVariantMap &params);
    void viewPopped(const QString &viewName, const QVariantMap &params);
    void viewReplaced(const QString &viewName, const QVariantMap &params);
    void viewCleared();

private:
    struct NavigationEntry
    {
        QString viewName;
        QVariantMap params;
    };

    QString m_currentViewName;
    QVariantMap m_currentParams;
    std::stack<NavigationEntry> m_navigationStack;
};

#endif // NAVIGATOR_H