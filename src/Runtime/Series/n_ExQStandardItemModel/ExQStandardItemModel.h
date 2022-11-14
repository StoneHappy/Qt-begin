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

private slots:
    void onCurrentChanged(const QModelIndex& current, const QModelIndex& previous);  //��ǰ��Ԫ�����仯ʱ
    void on_actOpen_triggered();            //�򿪺͵����ļ���������plainTextEdit������ʾ

private:
    void init(QStringList& list);           //��list��ʼ������ģ��

private:
    Ui::ExQStandardItemModel *ui;

    QLabel* m_labCurrFile;                 //��ǰ�ļ�
    QLabel* m_labCellPos;                   //��ǰ��Ԫ�����к�
    QLabel* m_labCellText;                  //��ǰ��Ԫ����������
    QStandardItemModel* m_model;            //����ģ��
    QItemSelectionModel* m_selectModet;     //ѡ��ģ��
};

#endif // EXQSTANDARDITEMMODEL_H
