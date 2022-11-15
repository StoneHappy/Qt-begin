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
