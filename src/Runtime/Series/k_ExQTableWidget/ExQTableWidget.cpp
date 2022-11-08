#include "ExQTableWidget.h"
#include "ui_ExQTableWidget.h"

ExQTableWidget::ExQTableWidget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ExQTableWidget)
{
    ui->setupUi(this);
}

ExQTableWidget::~ExQTableWidget()
{
    delete ui;
}
