#ifndef EXMAINWINDOW_H
#define EXMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class ExMainWindow;
}

class ExMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ExMainWindow(QWidget *parent = nullptr);
    ~ExMainWindow();

private slots:
    void on_actOpen_triggered();
    void on_actNew_triggered();
    void on_actQuit_triggered();   //�˳�����
    void on_actFont_triggered();   //��������
    void on_actCut_triggered();    //�����ı�
    void on_actCopy_triggered();   //�����ı�
    void on_actPaste_triggered();  //ճ���ı�
private:
    Ui::ExMainWindow *ui;
};

#endif // EXMAINWINDOW_H
