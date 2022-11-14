#ifndef EXQSTANDARDITEMMODEL_H
#define EXQSTANDARDITEMMODEL_H

#include <QMainWindow>

namespace Ui {
class ExQStandardItemModel;
}

class QStandardItemModel;
class QLabel;
class QItemSelectionModel;

class ExQStandardItemModel : public QMainWindow
{
    Q_OBJECT

public:
    explicit ExQStandardItemModel(QWidget *parent = nullptr);
    ~ExQStandardItemModel();

private:
    Ui::ExQStandardItemModel *ui;

    QLabel* m_labCurrFile;                 //当前文件
    QLabel* m_labCellPos;                   //当前单元格行列号
    QLabel* m_labCellText;                  //当前单元格数据内容
    QStandardItemModel* m_model;            //数据模型
    QItemSelectionModel* m_selectModet;     //选择模型
};

#endif // EXQSTANDARDITEMMODEL_H
