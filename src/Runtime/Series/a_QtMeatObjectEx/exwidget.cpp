#include "exwidget.h"
#include "ui_exwidget.h"

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
