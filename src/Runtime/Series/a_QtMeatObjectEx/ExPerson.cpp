#include "ExPerson.h"
#include <qobject.h>
#include <qobjectdefs.h>

ExPerson::ExPerson(QString name, QObject *parent)
    : QObject(parent)
{
    m_name = name;
}

int ExPerson::getAge()
{
    return m_age;
}

void ExPerson::setAge(int value)
{
    m_age = value;
    emit ageChanged(m_age);
}

void ExPerson::incAge()
{
    m_age++;
    emit ageChanged(m_age);
}