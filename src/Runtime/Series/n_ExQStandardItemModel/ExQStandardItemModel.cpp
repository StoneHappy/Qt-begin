#include "ExQStandardItemModel.h"
#include "ui_ExQStandardItemModel.h"

ExQStandardItemModel::ExQStandardItemModel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ExQStandardItemModel)
{
    ui->setupUi(this);
}

ExQStandardItemModel::~ExQStandardItemModel()
{
    delete ui;
}
