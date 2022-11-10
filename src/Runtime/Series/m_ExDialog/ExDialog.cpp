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

//��׼�ļ��Ի���QFileDialog+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void ExDialog::on_btnOpenFile_clicked()
{
    QString path = QDir::currentPath();                        //��ȡӦ�ó���ǰĿ¼
    QString fileter = QString::fromLocal8Bit("�ı��ļ�(*.txt);;ͼƬ�ļ�(*.jpg *.gif);;�����ļ�(*.*)");

    QString fileNmae = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("ѡ��һ���ļ�"), path, fileter);
    if (!fileNmae.isEmpty()) {
        ui->plainTextEdit->appendPlainText(fileNmae);
    }
}

void ExDialog::on_btnOpenFiles_clicked()
{
    QString path = QDir::currentPath();                        //��ȡӦ�ó���ǰĿ¼
    QString fileter = QString::fromLocal8Bit("�ı��ļ�(*.txt);;ͼƬ�ļ�(*.jpg *.gif);;�����ļ�(*.*)");

    QStringList fileNmaeList = QFileDialog::getOpenFileNames(this, QString::fromLocal8Bit("ѡ�����ļ�"), path, fileter);
    for (int i = 0; i < fileNmaeList.count(); i++) {
        ui->plainTextEdit->appendPlainText(fileNmaeList.at(i));
    }
}

void ExDialog::on_btnExistingDir_clicked()
{
    QString currPath = QCoreApplication::applicationDirPath(); //��ȡӦ�ó���ǰĿ¼
    QString path = QFileDialog::getExistingDirectory(this, QString::fromLocal8Bit("ѡ��һ��Ŀ¼�����ļ���"), currPath, QFileDialog::ShowDirsOnly);   //���һ����������ʾֻ��ʾ·��

    if (!path.isEmpty()) {
        ui->plainTextEdit->appendPlainText(path);
    }
}

void ExDialog::on_btnGetColor_clicked()
{
    QPalette pal = ui->plainTextEdit->palette();              //��ȡ����ɫ��
    QColor initColor = pal.color(QPalette::Text);
    QColor color = QColorDialog::getColor(initColor, this, QString::fromLocal8Bit("ѡ����ɫ"));

    if (color.isValid()) {                                    //��Ϊû��.isEmpty(),�ʶ�ʹ��.isValid()���ж�
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
    QString path = QDir::currentPath();                        //��ȡӦ�ó���ǰĿ¼
    QString fileter = QString::fromLocal8Bit("ͷ�ļ�(*.h);;Դ�ļ�(*.cpp);;�����ļ�(*.*)");
    QString fileNmae = QFileDialog::getSaveFileName(this, QString::fromLocal8Bit("�����ļ�"), path, fileter);

    if (!fileNmae.isEmpty())
        ui->plainTextEdit->appendPlainText(fileNmae);
}

//��׼��Ϣ�Ի���+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void ExDialog::on_btnQuestion_clicked()
{
    QMessageBox::StandardButton ret = QMessageBox::question(this, QString::fromLocal8Bit("������Ϣ�Ի���"), QString::fromLocal8Bit("question�Ի��������"), QMessageBox::Yes | QMessageBox::No | QMessageBox::Close, QMessageBox::NoButton);

    switch (ret) {
    case QMessageBox::Yes: {
        ui->plainTextEdit->appendPlainText(QString::fromLocal8Bit("QMessageBox::yes ��ť��ѡ��"));
        break;
    }
    case QMessageBox::No: {
        ui->plainTextEdit->appendPlainText(QString::fromLocal8Bit("QMessageBox::No ��ť��ѡ��"));
        break;
    }
    case QMessageBox::Close: {
        ui->plainTextEdit->appendPlainText(QString::fromLocal8Bit("QMessageBox::Close ��ť��ѡ��"));
        break;
    }
    default: {
        ui->plainTextEdit->appendPlainText(QString::fromLocal8Bit("���� switch ��default ��ѡ��"));
        break;
    }
    }
}

void ExDialog::on_btnInformation_clicked()
{
    QMessageBox::information(this, QString::fromLocal8Bit("��Ϣ��Ϣ�Ի���"), QString::fromLocal8Bit("information�Ի��������"), QMessageBox::Ok, QMessageBox::NoButton);
}

void ExDialog::on_btnWarning_clicked()
{
    QMessageBox::warning(this, QString::fromLocal8Bit("������Ϣ�Ի���"), QString::fromLocal8Bit("warning�Ի��������"), QMessageBox::Ok, QMessageBox::NoButton);
}

void ExDialog::on_btnCritical_clicked()
{
    QMessageBox::critical(this, QString::fromLocal8Bit("Σ����Ϣ�Ի���"), QString::fromLocal8Bit("critical�Ի��������"), QMessageBox::Ok, QMessageBox::NoButton);
}

void ExDialog::on_btnAbout_clicked()
{
    QMessageBox::about(this, QString::fromLocal8Bit("������Ϣ�Ի���"), QString::fromLocal8Bit("abou ����: Ͷ����ľ���֮�����"));
}

void ExDialog::on_btnAboutQt_clicked()
{
    QMessageBox::aboutQt(this, QString::fromLocal8Bit("����Qt��Ϣ�Ի���"));
}

//��׼����Ի���QInputDialog+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void ExDialog::on_btnGetString_clicked()
{
    bool ok = false;
    QString text = QInputDialog::getText(this, QString::fromLocal8Bit("�������ֶԻ���"), QString::fromLocal8Bit("������һ���ַ���"), QLineEdit::Normal, QString::fromLocal8Bit("Ĭ��������ַ���"), &ok);

    if (ok && !text.isEmpty())
        ui->plainTextEdit->appendPlainText(text);
}

void ExDialog::on_btnGetItem_clicked()
{
    QStringList list;
    list << QString::fromLocal8Bit("2019-10-02") << QString::fromLocal8Bit("04:28") << QString::fromLocal8Bit("���人������") << QString::fromLocal8Bit("�ô���") << QString::fromLocal8Bit("���û������");

    int index = 0;
    bool editable = true;   //ComboBox�Ƿ�ɱ༭
    bool ok = false;
    QString text = QInputDialog::getItem(this, QString::fromLocal8Bit("����item�Ի���"), QString::fromLocal8Bit("��ѡ��һ��item"), list, index, editable, &ok);

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
    int val = QInputDialog::getInt(this, QString::fromLocal8Bit("���������Ի���"), QString::fromLocal8Bit("������һ�������ı������С"), size, min, max, stepVal, &ok);

    if (ok) {
        QFont font = ui->plainTextEdit->font();
        font.setPointSize(val);
        ui->plainTextEdit->setFont(font);
        ui->plainTextEdit->appendPlainText(QString::fromLocal8Bit("�����С�Ѿ�������Ϊ:") + QString::number(val));
    }
}

void ExDialog::on_btnDouble_clicked()
{
    int min = 0;
    int max = 100;
    int d = 2;                 //С�����λ��
    double val = 3.1415;
    bool ok = false;
    double ret = QInputDialog::getDouble(this, QString::fromLocal8Bit("���븡�����Ի���"), QString::fromLocal8Bit("������һ�������ı������С"), d, min, max, val, &ok);

    if (ok)
        ui->plainTextEdit->appendPlainText(QString::fromLocal8Bit("��������СΪ:") + QString::number(ret, 'f', 4));
}


ExDialog::~ExDialog()
{
    delete ui;
}
