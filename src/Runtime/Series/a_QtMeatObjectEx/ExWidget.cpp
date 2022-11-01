#include "ExWidget.h"
#include "Series/a_QtMeatObjectEx/ExPerson.h"
#include "ui_ExWidget.h"
#include <qglobal.h>
#include <qmetaobject.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qspinbox.h>
#include <QMetaProperty>

ExWidget::ExWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExWidget)
{
    ui->setupUi(this);

    m_boy = new ExPerson(QString::fromLocal8Bit("张三"));
    m_boy->setProperty("score", 90);
    m_boy->setProperty("age", 20);
    m_boy->setProperty("sex", "Boy");
    connect(m_boy, &ExPerson::ageChanged, this,&ExWidget::onAgeChange);

    m_girl = new ExPerson(QString::fromLocal8Bit("小红"));
    m_girl->setProperty("score", 90);
    m_girl->setProperty("age", 20);
    m_girl->setProperty("sex", "Girl");
    connect(m_girl, &ExPerson::ageChanged, this,&ExWidget::onAgeChange);

    ui->spinBoy->setProperty("isBoy", true);
    ui->spinGril->setProperty("isBoy", false);

    connect(ui->spinGril, SIGNAL(valueChanged(int)), this, SLOT(onSpinValChange(int)));
    connect(ui->spinBoy,  SIGNAL(valueChanged(int)), this, SLOT(onSpinValChange(int)));

    connect(ui->btnBoyAdd, SIGNAL(clicked()), this, SLOT(onBtnBoyInc()));
    connect(ui->btnGrilAdd, SIGNAL(clicked()), this, SLOT(onBtnGrilInc()));
    connect(ui->btnMetaObject, SIGNAL(clicked()), this, SLOT(onClassInfo()));
    connect(ui->btnClean, SIGNAL(clicked()), this, SLOT(onBtnClear()));
}

ExWidget::~ExWidget()
{
    delete ui;
}

void ExWidget::onAgeChange(int val)
{
    Q_UNUSED(val)

    ExPerson* person = qobject_cast<ExPerson *>(sender());
    QString name = person->property("name").toString();
    QString sex = person->property("sex").toString();
    int age = person->getAge();
    ui->textEdit->appendPlainText(name + "," + sex + QString::asprintf(QString::fromLocal8Bit(",年龄=%d").toStdString().c_str(),age));
}
void ExWidget::onSpinValChange(int val)
{
    Q_UNUSED(val)

    QSpinBox* spin = qobject_cast<QSpinBox *>(sender());

    if (spin->property("isBoy").toBool())
        m_boy->setAge(ui->spinBoy->value());
    else
        m_girl->setAge(ui->spinGril->value());

}
void ExWidget::onBtnClear()
{
    ui->textEdit->clear();
}
void ExWidget::onBtnBoyInc()
{
    m_boy->incAge();
}
void ExWidget::onBtnGrilInc()
{
    m_girl->incAge();
}
void ExWidget::onClassInfo()
{
    const QMetaObject* meta = m_boy->metaObject();

    ui->textEdit->clear();
    ui->textEdit->appendPlainText(QString::fromLocal8Bit("===元对象信息(Meta Object)==="));
    ui->textEdit->appendPlainText(QString::fromLocal8Bit("类名称: %1\n").arg(meta->className()));
    ui->textEdit->appendPlainText(QString::fromLocal8Bit("属性(property)"));

    for (int i = meta->propertyOffset(); i < meta->propertyCount(); i++) {
        QMetaProperty prop = meta->property(i);
        const char* propName = prop.name();
        QString propValue = m_boy->property(propName).toString();
        ui->textEdit->appendPlainText(QString::fromLocal8Bit("属性名称=%1， 属性值= %2").arg(propName).arg(propValue));
    }

    ui->textEdit->appendPlainText("");
    ui->textEdit->appendPlainText("classInfo: ");

    for (int i = meta->classInfoOffset(); i < meta->classInfoCount(); i++) {
        QMetaClassInfo classInfo = meta->classInfo(i);
        ui->textEdit->appendPlainText(QString::fromLocal8Bit("Name= %1, Vuale= %2").arg(classInfo.name()).arg(classInfo.value()));
    }
}
