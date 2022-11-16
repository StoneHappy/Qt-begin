#include "ExDlgSize.h"
#include "ui_ExDlgSize.h"

ExDlgSize::ExDlgSize(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExDlgSize)
{
    ui->setupUi(this);
}

ExDlgSize::~ExDlgSize()
{
    delete ui;
}

void ExDlgSize::setRowCol(int row, int col)
{
    ui->spinBoxRow->setValue(row);
    ui->spinBoxCol->setValue(col);
}

int ExDlgSize::getRowCout()
{
    return ui->spinBoxRow->value();
}

int ExDlgSize::getColCount()
{
    return ui->spinBoxCol->value();
}
