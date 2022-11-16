#include "ExDlgLocate.h"
#include "ExCustomMainWin.h"
#include "ui_ExDlgLocate.h"

ExDlgLocate::ExDlgLocate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExDlgLocate)
{
    ui->setupUi(this);
}

ExDlgLocate::~ExDlgLocate()
{
    delete ui;
}

void ExDlgLocate::setSpinRange(int rowCount, int colCount)
{
    ui->spinBoxRow->setMaximum(rowCount - 1);
    ui->spinBoxCol->setMaximum(colCount - 1);
}

void ExDlgLocate::setSpinValue(int rowNo, int colNo)
{
    ui->spinBoxCol->setValue(colNo);
    ui->spinBoxRow->setValue(rowNo);
}

void ExDlgLocate::on_btnSetText_clicked()
{
    int row = ui->spinBoxRow->value();
    int col = ui->spinBoxCol->value();

    ExCustomMainWin* parWind = (ExCustomMainWin*)parentWidget();
    parWind->setACellText(row, col, ui->lineEdit->text());

    if (ui->checkBoxRow->isChecked())
        ui->spinBoxRow->setValue(1 + ui->spinBoxRow->value());
    if (ui->checkBoxCol->isChecked())
        ui->spinBoxCol->setValue(1 + ui->spinBoxCol->value());
}

void ExDlgLocate::on_btnClose_clicked()
{
}

void ExDlgLocate::closeEvent(QCloseEvent* event)
{
    ExCustomMainWin* parWind = (ExCustomMainWin*)parentWidget();
    parWind->setActLocateEnable(true);
    parWind->setDlgLocateNull();
}

void ExDlgLocate::showEvent(QShowEvent* evnet)
{
    ExCustomMainWin* parWind = (ExCustomMainWin*)parentWidget();
    parWind->setActLocateEnable(false);
}
