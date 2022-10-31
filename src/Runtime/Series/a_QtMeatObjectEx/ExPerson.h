#pragma once

#include <QObject>
#include <qobject.h>
#include <qobjectdefs.h>
#include <stdint.h>

class ExPerson : public QObject
{
    Q_OBJECT

    Q_CLASSINFO("author", "StoneHappy")
    Q_CLASSINFO("version", "1.0.0")
    Q_CLASSINFO("info", "Qt5 Meta Object and Property Example")

    Q_PROPERTY(int age READ getAge WRITE setAge NOTIFY ageChanged)
    Q_PROPERTY(QString name MEMBER m_name)
    Q_PROPERTY(int score MEMBER m_score)
public:
    explicit ExPerson(QString name, QObject *parent = nullptr);

public:
    int getAge();
    void setAge(int value);

    void incAge();

signals:
    void ageChanged(int value);  //属性age发生改变的信号函数
private:
    int m_age = 5;
    QString m_name;
    int m_score = 50;
};