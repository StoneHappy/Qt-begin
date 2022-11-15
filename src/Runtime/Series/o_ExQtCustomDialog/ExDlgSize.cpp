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
