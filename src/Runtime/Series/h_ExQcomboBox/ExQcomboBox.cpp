#include "ExQcomboBox.h"
#include "ui_ExQcomboBox.h"

ExQcomboBox::ExQcomboBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExQcomboBox)
{
    ui->setupUi(this);
}

ExQcomboBox::~ExQcomboBox()
{
    delete ui;
}
