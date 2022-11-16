#include "ExMainWindow.h"
#include "ui_ExMainWindow.h"

ExMainWindow::ExMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ExMainWindow)
{
    ui->setupUi(this);
}

ExMainWindow::~ExMainWindow()
{
    delete ui;
}
