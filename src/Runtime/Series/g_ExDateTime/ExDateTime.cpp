#include "ExDateTime.h"
#include "ui_ExDateTime.h"

ExDateTime::ExDateTime(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExDateTime)
{
    ui->setupUi(this);
}

ExDateTime::~ExDateTime()
{
    delete ui;
}


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//获取当前日期和时间，该日期时间栏里面显示
void ExDateTime::on_btnGetDateTime_clicked()
{
    QDateTime currDateTime = QDateTime::currentDateTime();
    ui->timeEdit->setTime(currDateTime.time());
    ui->editTime->setText(currDateTime.toString("hh:mm:ss:zzz"));
    ui->dateEdit->setDate(currDateTime.date());
    ui->editDate->setText(currDateTime.toString("yyyy-MM-dd"));
    ui->dateTimeEdit->setDateTime(currDateTime);
    ui->editDateTime->setText(currDateTime.toString("yyyy-MM-dd hh:mm:ss:zzz"));
    ui->labCurrDataTime->setText(currDateTime.toString("yyyy-MM-dd hh:mm:ss:zzz"));
}
