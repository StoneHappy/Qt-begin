#include "ExMDI.h"
#include "ui_ExMDI.h"

ExMDI::ExMDI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExMDI)
{
    ui->setupUi(this);
}

ExMDI::~ExMDI()
{
    delete ui;
}
