#include "ExQFileSystemModel.h"
#include "ui_ExQFileSystemModel.h"

ExQFileSystemModel::ExQFileSystemModel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ExQFileSystemModel)
{
    ui->setupUi(this);
}

ExQFileSystemModel::~ExQFileSystemModel()
{
    delete ui;
}
