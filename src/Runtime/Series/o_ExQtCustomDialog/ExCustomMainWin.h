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

    QStandardItemModel* m_model;                        //数据模型
    QItemSelectionModel* m_seleModel;                   //item选择模型
    QLabel* m_labCellPos;                              //当前单元格行列号
    QLabel* m_labCellText;                             //当前单元格内容
};

#endif // EXCUSTOMMAINWIN_H
