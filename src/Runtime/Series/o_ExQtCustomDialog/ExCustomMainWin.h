#ifndef EXCUSTOMMAINWIN_H
#define EXCUSTOMMAINWIN_H

#include <QMainWindow>
class QStandardItemModel;
class QLabel;
class QItemSelectionModel;

namespace Ui {
class ExCustomMainWin;
}

class ExCustomMainWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit ExCustomMainWin(QWidget *parent = nullptr);
    ~ExCustomMainWin();

private slots:
    void on_currentChanged(const QModelIndex& current, const QModelIndex& previous);


private:
    Ui::ExCustomMainWin *ui;

    QStandardItemModel* m_model;                        //����ģ��
    QItemSelectionModel* m_seleModel;                   //itemѡ��ģ��
    QLabel* m_labCellPos;                              //��ǰ��Ԫ�����к�
    QLabel* m_labCellText;                             //��ǰ��Ԫ������
};

#endif // EXCUSTOMMAINWIN_H
