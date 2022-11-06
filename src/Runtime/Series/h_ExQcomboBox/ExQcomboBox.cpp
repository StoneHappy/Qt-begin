#include "ExQcomboBox.h"
#include "ui_ExQcomboBox.h"
#include <qcombobox.h>
#include <qicon.h>
#include <qtextdocument.h>
#include <QTextBlock>

ExQcomboBox::ExQcomboBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExQcomboBox)
{
    ui->setupUi(this);
    connect(ui->comBoxRight, &QComboBox::currentTextChanged, this, &ExQcomboBox::onSelectDisplay);
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


void ExQcomboBox::on_btnRightInit_clicked()
{
    QIcon ico;
    ico.addFile(":/images/gril.ico");

    QMap<QString, QString> map;
    map.insert(QString::fromLocal8Bit("张投"), QString::fromLocal8Bit("16岁"));
    map.insert(QString::fromLocal8Bit("张我"), QString::fromLocal8Bit("17岁"));
    map.insert(QString::fromLocal8Bit("张以"), QString::fromLocal8Bit("18岁"));
    map.insert(QString::fromLocal8Bit("张木"), QString::fromLocal8Bit("19岁"));
    map.insert(QString::fromLocal8Bit("张李"), QString::fromLocal8Bit("20岁"));
    map.insert(QString::fromLocal8Bit("张，"), QString::fromLocal8Bit("21岁"));
    map.insert(QString::fromLocal8Bit("张报"), QString::fromLocal8Bit("22岁"));
    map.insert(QString::fromLocal8Bit("张之"), QString::fromLocal8Bit("23岁"));
    map.insert(QString::fromLocal8Bit("张以"), QString::fromLocal8Bit("24岁"));
    map.insert(QString::fromLocal8Bit("张琼"), QString::fromLocal8Bit("25岁"));
    map.insert(QString::fromLocal8Bit("张玖"), QString::fromLocal8Bit("26岁"));
    map.insert(QString::fromLocal8Bit("张。"), QString::fromLocal8Bit("27岁"));

    ui->comBoxRight->clear();
    foreach(QString str, map.keys()){
        ui->comBoxRight->addItem(ico, str, map.value(str));           //因为有Map，所以QComboBox显示会按照key排序，而非上面的定义顺序,注意不是map.key(str)
    }
}


void ExQcomboBox::onSelectDisplay(QString str)
{
    QString strData = ui->comBoxRight->currentData().toString();
    ui->labDisplay->setText(QString::fromLocal8Bit("显示当前的Item项： ") + str + " " + strData);

    ui->plainTextEdit->appendPlainText(str + " " + strData);
}

void ExQcomboBox::on_btnBottomClear_clicked()
{
    ui->plainTextEdit->clear();
    ui->labDisplay->setText(QString::fromLocal8Bit("显示当前的Item项："));
}

void ExQcomboBox::on_btnLeftClear_clicked()
{
    ui->comBoxLeft->clear();
}

void ExQcomboBox::on_checkBoxOnlyWrite_clicked()
{
    if(ui->checkBoxOnlyWrite->isChecked())
        ui->comBoxLeft->setEditable(true);
    else
        ui->comBoxLeft->setEditable(false);
}

void ExQcomboBox::on_btnBottomAdd_clicked()
{
    QTextDocument* doc = ui->plainTextEdit->document();
    int cnt =doc->blockCount();

    QIcon ico;
    ico.addFile(":/images/github.ico");

    ui->comBoxLeft->clear();
    ui->comBoxRight->clear();

    for (int i = 0; i < cnt; i++) {
        QTextBlock text = doc->findBlockByNumber(i);                  //获取文本中一段（以换行为标志）
        ui->comBoxLeft->addItem(ico, text.text());
        ui->comBoxRight->addItem(ico, text.text(), QString::fromLocal8Bit("附加内容:%1").arg(i));
    }
}

void ExQcomboBox::on_checkBoxOnlyRead_clicked()
{
    if(ui->checkBoxOnlyRead->isChecked())
        ui->plainTextEdit->setEnabled(false);
    else
        ui->plainTextEdit->setEnabled(true);
}
