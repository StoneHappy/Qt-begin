#include "ExDialog.h"
#include "ui_ExDialog.h"

ExDialog::ExDialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ExDialog)
{
    ui->setupUi(this);
}

ExDialog::~ExDialog()
{
    delete ui;
}
