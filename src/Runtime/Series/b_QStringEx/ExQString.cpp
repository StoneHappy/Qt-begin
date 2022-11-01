#include "ExQString.h"
#include "ui_ExQString.h"

ExQString::ExQString(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExQString)
{
    ui->setupUi(this);
    setWindowTitle(QObject::tr("2/8/10/16进制互相转化"));
}

ExQString::~ExQString()
{
    delete ui;
}


void ExQString::on_btnResult_clicked()
{
    float a = ui->editA->text().toFloat();
    float b = ui->editB->text().toFloat();
    float result = a * b;

    QString str = QString::number(static_cast<double>(result), 'f', 2);

    ui->editC->setText(str);
}
void ExQString::on_btn2_clicked()
{
    QString str = ui->edit2->text();
    bool ok;
    int val = str.toInt(&ok, 2);

    str = str.setNum(val, 8);
    ui->edit8->setText(str);
    str = str.setNum(val, 10);
    ui->edit10->setText(str);
    str = str.setNum(val, 16);
    ui->edit16->setText(str);
}
void ExQString::on_btn8_clicked()
{
    QString str = ui->edit8->text();
    bool ok;
    int val = str.toInt(&ok, 8);

    str = str.setNum(val, 2);
    ui->edit2->setText(str);
    str = str.setNum(val, 10);
    ui->edit10->setText(str);
    str = str.setNum(val, 16);
    ui->edit16->setText(str);
}
void ExQString::on_btn10_clicked()
{
    QString str = ui->edit10->text();
    bool ok;
    int val = str.toInt(&ok, 10);

    str = str.setNum(val, 2);
    ui->edit2->setText(str);
    str = str.setNum(val, 8);
    ui->edit8->setText(str);
    str = str.setNum(val, 16);
    ui->edit16->setText(str);
}
void ExQString::on_btn16_clicked()
{
    QString str = ui->edit16->text();
    bool ok;
    int val = str.toInt(&ok, 16);

    str = str.setNum(val, 2);
    ui->edit2->setText(str);
    str = str.setNum(val, 8);
    ui->edit8->setText(str);
    str = str.setNum(val, 10);
    ui->edit10->setText(str);
}