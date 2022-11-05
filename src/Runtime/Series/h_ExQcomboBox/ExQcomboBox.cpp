#include "ExQcomboBox.h"
#include "ui_ExQcomboBox.h"

ExQcomboBox::ExQcomboBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExQcomboBox)
{
    ui->setupUi(this);
}

ExQcomboBox::~ExQcomboBox()
{
    delete ui;
}


//左上角区域+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//初始化简单的QComboBox控件
void ExQcomboBox::on_btnLeftInit_clicked()
{
    QIcon ico;
    ico.addFile(":/images/github.ico");

    ui->comBoxLeft->clear();
    for (int i = 0; i < 13; i++) {
        ui->comBoxLeft->addItem(ico, QString::fromLocal8Bit("第%1个item项").arg(i));   //带有ico图标的项
    }
}