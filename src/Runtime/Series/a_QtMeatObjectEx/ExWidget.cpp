#include "ExWidget.h"
#include "ui_ExWidget.h"

ExWidget::ExWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExWidget)
{
    ui->setupUi(this);
}

ExWidget::~ExWidget()
{
    delete ui;
}
