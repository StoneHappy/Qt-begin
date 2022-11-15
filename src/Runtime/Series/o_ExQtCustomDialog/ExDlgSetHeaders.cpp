#include "ExDlgSetHeaders.h"
#include "ui_ExDlgSetHeaders.h"

ExDlgSetHeaders::ExDlgSetHeaders(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExDlgSetHeaders)
{
    ui->setupUi(this);
}

ExDlgSetHeaders::~ExDlgSetHeaders()
{
    delete ui;
}
