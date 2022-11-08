#include "ExQTreeWidget.h"
#include "ui_ExQTreeWidget.h"

ExQTreeWidget::ExQTreeWidget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ExQTreeWidget)
{
    ui->setupUi(this);
}

ExQTreeWidget::~ExQTreeWidget()
{
    delete ui;
}
