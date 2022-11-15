#include "ExCustomMainWin.h"
#include "ui_ExCustomMainWin.h"

ExCustomMainWin::ExCustomMainWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ExCustomMainWin)
{
    ui->setupUi(this);
}

ExCustomMainWin::~ExCustomMainWin()
{
    delete ui;
}
