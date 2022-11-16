#ifndef EXCUSTOMMAINWIN_H
#define EXCUSTOMMAINWIN_H

#include <QMainWindow>
class QStandardItemModel;
class QLabel;
class QItemSelectionModel;
class ExDlgSetHeaders;
class ExDlgLocate;
namespace Ui {
class ExCustomMainWin;
}

class ExCustomMainWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit ExCustomMainWin(QWidget *parent = nullptr);
    ~ExCustomMainWin();

    void setACellText(int row, int col, QString text);
    void setActLocateEnable(bool enable);
    void setDlgLocateNull();

private slots:
    void on_currentChanged(const QModelIndex& current, const QModelIndex& previous);
    void on_actSetHeader_triggered();
    void on_actLocate_triggered();

private:
    Ui::ExCustomMainWin *ui;

    ExDlgSetHeaders* m_dlgSetHeaders = nullptr;
    ExDlgLocate* m_dlglocate = nullptr;

    QStandardItemModel* m_model;                        //����ģ��
    QItemSelectionModel* m_seleModel;                   //itemѡ��ģ��
    QLabel* m_labCellPos;                              //��ǰ��Ԫ�����к�
    QLabel* m_labCellText;                             //��ǰ��Ԫ������
};

#endif // EXCUSTOMMAINWIN_H
