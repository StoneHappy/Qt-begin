#include "ExDlgLocate.h"
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
