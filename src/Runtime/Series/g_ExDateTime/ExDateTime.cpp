#include "ExDateTime.h"
#include "ui_ExDateTime.h"
#include <iostream>
#include <qdatetime.h>
#include <QTimer>
#include <qobjectdefs.h>
#include <qwindowdefs.h>

ExDateTime::ExDateTime(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExDateTime)
{
    ui->setupUi(this);

    setWindowTitle(QString::fromLocal8Bit("时间日期(QTime/QDate/QDateTime)和定时器(QTimer)"));

    m_timer = new QTimer(this);
    m_timer->stop();
    m_timer->setInterval(1000);

    connect(m_timer, SIGNAL(timeout()), this, SLOT(onTimerOut()));;
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


void ExDateTime::on_btnStatrt_clicked()
{
    m_timer->start();
    m_time.start();

    ui->btnStatrt->setEnabled(false);
    ui->btnStop->setEnabled(true);
    ui->btnPeriod->setEnabled(false);

    ui->labGo->setText(QString::fromLocal8Bit("时间流逝在后台计算中..."));
}

void ExDateTime::on_btnStop_clicked()
{
    m_timer->stop();
    ui->btnStop->setEnabled(false);
    ui->btnStatrt->setEnabled(true);

    int tmMsec = m_time.elapsed();

    int ms = tmMsec % 1000;
    int sec = tmMsec / 1000;
    ui->btnPeriod->setEnabled(true);
    ui->labGo->setText(QString::fromLocal8Bit("时间已经流逝：%1 秒 %2 毫秒").arg(sec).arg(ms));
}

void ExDateTime::on_btnPeriod_clicked()
{
    m_timer->setInterval(ui->spinBox->value());
}



void ExDateTime::onTimerOut()
{
    QTime currTime = QTime::currentTime();
    ui->lcdHH->display(currTime.toString("hh"));
    ui->lcdmm->display(currTime.toString("mm"));
    ui->lcdSS->display(currTime.toString("ss"));

    int val = ui->progressBar->value();
    val++;
    val = val > 100 ? 0 : val;

    ui->progressBar->setValue(val);
}