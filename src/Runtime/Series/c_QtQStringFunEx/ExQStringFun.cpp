#include "ExQStringFun.h"
#include "ui_ExQStringFun.h"

ExQStringFun::ExQStringFun(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExQStringFun)
{
    ui->setupUi(this);
}

ExQStringFun::~ExQStringFun()
{
    delete ui;
}


void ExQStringFun::on_btnAppend_clicked()
{
    QString str1 = ui->comboxStr1->currentText();
    QString str2 = ui->comboxStr2->currentText();

    str1.append(str2);
    ui->editResult->setText(str1);
}

void ExQStringFun::on_btnPrepend_clicked()
{
    QString str1 = ui->comboxStr1->currentText();
    QString str2 = ui->comboxStr2->currentText();

    str1.prepend(str2);
    ui->editResult->setText(str1);
}

void ExQStringFun::on_btnToUpper_clicked()
{
    QString str1 = ui->comboxStr1->currentText();
    QString strResult = str1.toUpper();
    ui->editResult->setText(strResult);
}


void ExQStringFun::on_btnToLower_clicked()
{
    QString str1 = ui->comboxStr1->currentText();
    QString strResult = str1.toLower();
    ui->editResult->setText(strResult);
}

void ExQStringFun::on_btnLeft_clicked()
{
    QString str1 = ui->comboxStr1->currentText();
    int n = ui->spinLabSpin->value();
    QString strResult = str1.left(n);
    ui->editResult->setText(strResult);
}

void ExQStringFun::on_btnRight_clicked()
{
    QString str1 = ui->comboxStr1->currentText();
    int n = ui->spinLabSpin->value();
    QString strResult = str1.right(n);
    ui->editResult->setText(strResult);
}

void ExQStringFun::on_btnSection_clicked()
{
    QString str1 = ui->comboxStr1->currentText();
    QString str2 = ui->comboxStr2->currentText();
    int n = ui->spinLabSpin->value();

    QString str3 = str1.section(str2, n, n+1);
    ui->editResult->setText(str3);
}

void ExQStringFun::on_btnSimplified_clicked()
{
    QString str1 = ui->comboxStr1->currentText();
    QString strRet = str1.simplified();
    ui->editResult->setText(strRet);
}

void ExQStringFun::on_btnTrimmed_clicked()
{
    QString str1 = ui->comboxStr1->currentText();
    QString strRet = str1.trimmed();
    ui->editResult->setText(strRet);
}


void ExQStringFun::on_btnCount_clicked()
{
    QString str1 = ui->comboxStr1->currentText();
    QString strRet = QString("count():%1").arg(str1.count());
    ui->editResult->setText(strRet);
}

void ExQStringFun::on_btnSize_clicked()
{
    QString str1 = ui->comboxStr1->currentText();
    QString strRet = QString("count():%1").arg(str1.size());
    ui->editResult->setText(strRet);
}

void ExQStringFun::on_btnIndexOf_clicked()
{
    QString str1 = ui->comboxStr1->currentText();
    QString str2 = ui->comboxStr2->currentText();

    QString strRet = QString("IndexOf():%1").arg(str1.indexOf(str2));
    ui->editResult->setText(strRet);
}

void ExQStringFun::on_btnLastIndexOf_clicked()
{
    QString str1 = ui->comboxStr1->currentText();
    QString str2 = ui->comboxStr2->currentText();

    QString strRet = QString("lastIndexOf():%1").arg(str1.lastIndexOf(str2));
    ui->editResult->setText(strRet);
}