#include "ExQString.h"
#include "ui_ExQString.h"

ExQString::ExQString(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExQString)
{
    ui->setupUi(this);
    setWindowTitle(QObject::tr("2/8/10/16进制互相转化"));
}

ExQString::~ExQString()
{
    delete ui;
}
