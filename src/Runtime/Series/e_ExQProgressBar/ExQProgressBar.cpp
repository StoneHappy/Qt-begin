#include "ExQProgressBar.h"
#include "ui_ExQProgressBar.h"
#include <qobjectdefs.h>

ExQProgressBar::ExQProgressBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExQProgressBar)
{
    ui->setupUi(this);

    setWindowTitle(QString::fromLocal8Bit("QSlider、QScrollBar、QProgressBar控件的联动"));
    connect(ui->progressBarHor, SIGNAL(valueChanged(int)), this, SLOT(onValChange(int)));
    connect(ui->scrollBarHor, SIGNAL(valueChanged(int)), this, SLOT(onValChange(int)));
    connect(ui->sliderHor, SIGNAL(valueChanged(int)), this, SLOT(onValChange(int)));
    connect(ui->progressBarVer, SIGNAL(valueChanged(int)), this, SLOT(onValChange(int)));
    connect(ui->scrollBarVer, SIGNAL(valueChanged(int)), this, SLOT(onValChange(int)));
    connect(ui->sliderVer, SIGNAL(valueChanged(int)), this, SLOT(onValChange(int)));
}

ExQProgressBar::~ExQProgressBar()
{
    delete ui;
}

void ExQProgressBar::onValChange(int val)
{
    ui->progressBarHor->setValue(val);
    ui->scrollBarHor->setValue(val);
    ui->sliderHor->setValue(val);
    ui->progressBarVer->setValue(val);
    ui->scrollBarVer->setValue(val);
    ui->sliderVer->setValue(val);
}
