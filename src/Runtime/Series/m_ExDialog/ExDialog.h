#ifndef EXDIALOG_H
#define EXDIALOG_H

#include <QMainWindow>

namespace Ui {
class ExDialog;
}

class ExDialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit ExDialog(QWidget *parent = nullptr);
    ~ExDialog();

private:
    Ui::ExDialog *ui;

private slots:
    void on_btnOpenFile_clicked();        //��һ���ļ�
    void on_btnOpenFiles_clicked();       //�򿪶���ļ�
    void on_btnExistingDir_clicked();     //ѡ������Ŀ¼
    void on_btnGetColor_clicked();        //ѡ����ɫ
    void on_btnGetFont_clicked();         //ѡ������
    void on_btnSaveFile_clicked();        //�����ļ�

    void on_btnQuestion_clicked();
    void on_btnInformation_clicked();
    void on_btnWarning_clicked();
    void on_btnCritical_clicked();
    void on_btnAbout_clicked();
    void on_btnAboutQt_clicked();

    void on_btnGetString_clicked();       //�����ַ���
    void on_btnGetItem_clicked();         //itemѡ������
    void on_btnInt_clicked();             //��������
    void on_btnDouble_clicked();          //���븡����
};

#endif // EXDIALOG_H
