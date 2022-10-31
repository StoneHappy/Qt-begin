#include "ExWidget.h"
#include "ui_ExWidget.h"

ExWidget::ExWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExWidget)
{
    ui->setupUi(this);

    connect(ui->btnMetaObject, SIGNAL(clicked()), this, SLOT(onClassInfo()));
}

ExWidget::~ExWidget()
{
    delete ui;
}

void ExWidget::onAgeChange(int val)
{

}
void ExWidget::onSpinValChange(int val)
{

}
void ExWidget::onBtnClear()
{

}
void ExWidget::onBtnBoyInc()
{

}
void ExWidget::onBtnGrilInc()
{

}
void ExWidget::onClassInfo()
{
    ui->textEdit->clear();
    
    ui->textEdit->appendPlainText(QString::fromLocal8Bit("===元对象信息(Meta Object)==="));
    ui->textEdit->appendPlainText(QString::fromLocal8Bit("属性(property)"));
}
