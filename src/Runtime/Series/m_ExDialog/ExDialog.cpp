#include "ExDialog.h"
#include "ui_ExDialog.h"
#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>
#include <QInputDialog>
#include <QMessageBox>

ExDialog::ExDialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ExDialog)
{
    ui->setupUi(this);
}

//标准文件对话框QFileDialog+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void ExDialog::on_btnOpenFile_clicked()
{
    QString path = QDir::currentPath();                        //获取应用程序当前目录
    QString fileter = QString::fromLocal8Bit("文本文件(*.txt);;图片文件(*.jpg *.gif);;所有文件(*.*)");

    QString fileNmae = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("选择一个文件"), path, fileter);
    if (!fileNmae.isEmpty()) {
        ui->plainTextEdit->appendPlainText(fileNmae);
    }
}

void ExDialog::on_btnOpenFiles_clicked()
{
    QString path = QDir::currentPath();                        //获取应用程序当前目录
    QString fileter = QString::fromLocal8Bit("文本文件(*.txt);;图片文件(*.jpg *.gif);;所有文件(*.*)");

    QStringList fileNmaeList = QFileDialog::getOpenFileNames(this, QString::fromLocal8Bit("选择多个文件"), path, fileter);
    for (int i = 0; i < fileNmaeList.count(); i++) {
        ui->plainTextEdit->appendPlainText(fileNmaeList.at(i));
    }
}

void ExDialog::on_btnExistingDir_clicked()
{
    QString currPath = QCoreApplication::applicationDirPath(); //获取应用程序当前目录
    QString path = QFileDialog::getExistingDirectory(this, QString::fromLocal8Bit("选择一个目录【非文件】"), currPath, QFileDialog::ShowDirsOnly);   //最后一个参数，表示只显示路径

    if (!path.isEmpty()) {
        ui->plainTextEdit->appendPlainText(path);
    }
}

void ExDialog::on_btnGetColor_clicked()
{
    QPalette pal = ui->plainTextEdit->palette();              //获取条调色板
    QColor initColor = pal.color(QPalette::Text);
    QColor color = QColorDialog::getColor(initColor, this, QString::fromLocal8Bit("选择颜色"));

    if (color.isValid()) {                                    //因为没有.isEmpty(),故而使用.isValid()来判断
        pal.setColor(QPalette::Text, color);
        ui->plainTextEdit->setPalette(pal);
    }
}

void ExDialog::on_btnGetFont_clicked()
{
    QFont initFont = ui->plainTextEdit->font();
    bool ok = false;
    QFont font = QFontDialog::getFont(&ok, initFont);

    if (ok)
        ui->plainTextEdit->setFont(font);
}

void ExDialog::on_btnSaveFile_clicked()
{
    QString path = QDir::currentPath();                        //获取应用程序当前目录
    QString fileter = QString::fromLocal8Bit("头文件(*.h);;源文件(*.cpp);;所有文件(*.*)");
    QString fileNmae = QFileDialog::getSaveFileName(this, QString::fromLocal8Bit("保存文件"), path, fileter);

    if (!fileNmae.isEmpty())
        ui->plainTextEdit->appendPlainText(fileNmae);
}

//标准消息对话框+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void ExDialog::on_btnQuestion_clicked()
{
    QMessageBox::StandardButton ret = QMessageBox::question(this, QString::fromLocal8Bit("问题消息对话框"), QString::fromLocal8Bit("question对话框的内容"), QMessageBox::Yes | QMessageBox::No | QMessageBox::Close, QMessageBox::NoButton);

    switch (ret) {
    case QMessageBox::Yes: {
        ui->plainTextEdit->appendPlainText(QString::fromLocal8Bit("QMessageBox::yes 按钮被选中"));
        break;
    }
    case QMessageBox::No: {
        ui->plainTextEdit->appendPlainText(QString::fromLocal8Bit("QMessageBox::No 按钮被选中"));
        break;
    }
    case QMessageBox::Close: {
        ui->plainTextEdit->appendPlainText(QString::fromLocal8Bit("QMessageBox::Close 按钮被选中"));
        break;
    }
    default: {
        ui->plainTextEdit->appendPlainText(QString::fromLocal8Bit("这是 switch 的default 的选项"));
        break;
    }
    }
}

void ExDialog::on_btnInformation_clicked()
{
    QMessageBox::information(this, QString::fromLocal8Bit("信息消息对话框"), QString::fromLocal8Bit("information对话框的内容"), QMessageBox::Ok, QMessageBox::NoButton);
}

void ExDialog::on_btnWarning_clicked()
{
    QMessageBox::warning(this, QString::fromLocal8Bit("警告消息对话框"), QString::fromLocal8Bit("warning对话框的内容"), QMessageBox::Ok, QMessageBox::NoButton);
}

void ExDialog::on_btnCritical_clicked()
{
    QMessageBox::critical(this, QString::fromLocal8Bit("危机消息对话框"), QString::fromLocal8Bit("critical对话框的内容"), QMessageBox::Ok, QMessageBox::NoButton);
}

void ExDialog::on_btnAbout_clicked()
{
    QMessageBox::about(this, QString::fromLocal8Bit("关于消息对话框"), QString::fromLocal8Bit("abou 作者: 投我以木李，报之以琼玖"));
}

void ExDialog::on_btnAboutQt_clicked()
{
    QMessageBox::aboutQt(this, QString::fromLocal8Bit("关于Qt消息对话框"));
}

//标准输入对话框QInputDialog+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void ExDialog::on_btnGetString_clicked()
{
    bool ok = false;
    QString text = QInputDialog::getText(this, QString::fromLocal8Bit("输入文字对话框"), QString::fromLocal8Bit("请输入一个字符串"), QLineEdit::Normal, QString::fromLocal8Bit("默认输入的字符串"), &ok);

    if (ok && !text.isEmpty())
        ui->plainTextEdit->appendPlainText(text);
}

void ExDialog::on_btnGetItem_clicked()
{
    QStringList list;
    list << QString::fromLocal8Bit("2019-10-02") << QString::fromLocal8Bit("04:28") << QString::fromLocal8Bit("在武汉的卧室") << QString::fromLocal8Bit("敲代码") << QString::fromLocal8Bit("这会没有困意");

    int index = 0;
    bool editable = true;   //ComboBox是否可编辑
    bool ok = false;
    QString text = QInputDialog::getItem(this, QString::fromLocal8Bit("输入item对话框"), QString::fromLocal8Bit("请选择一个item"), list, index, editable, &ok);

    if (ok && !text.isEmpty())
        ui->plainTextEdit->appendPlainText(text);
}

void ExDialog::on_btnInt_clicked()
{
    int min = 0;
    int max = 100;
    int stepVal = 3;
    int size = ui->plainTextEdit->font().pointSize();
    bool ok = false;
    int val = QInputDialog::getInt(this, QString::fromLocal8Bit("输入整数对话框"), QString::fromLocal8Bit("请输入一个整数改变字体大小"), size, min, max, stepVal, &ok);

    if (ok) {
        QFont font = ui->plainTextEdit->font();
        font.setPointSize(val);
        ui->plainTextEdit->setFont(font);
        ui->plainTextEdit->appendPlainText(QString::fromLocal8Bit("字体大小已经被设置为:") + QString::number(val));
    }
}

void ExDialog::on_btnDouble_clicked()
{
    int min = 0;
    int max = 100;
    int d = 2;                 //小数点的位数
    double val = 3.1415;
    bool ok = false;
    double ret = QInputDialog::getDouble(this, QString::fromLocal8Bit("输入浮点数对话框"), QString::fromLocal8Bit("请输入一个整数改变字体大小"), d, min, max, val, &ok);

    if (ok)
        ui->plainTextEdit->appendPlainText(QString::fromLocal8Bit("浮点数大小为:") + QString::number(ret, 'f', 4));
}


ExDialog::~ExDialog()
{
    delete ui;
}
