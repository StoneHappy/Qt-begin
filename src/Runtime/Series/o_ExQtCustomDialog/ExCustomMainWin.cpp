#include "ExCustomMainWin.h"
#include "ui_ExCustomMainWin.h"

#include <QStandardItemModel>
#include <QItemSelectionModel>
#include <QLabel>

ExCustomMainWin::ExCustomMainWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ExCustomMainWin)
{
    ui->setupUi(this);
    setWindowTitle(QString::fromLocal8Bit("�Զ���ͱ�׼�Ի�����÷�"));

    m_model = nullptr;

    m_model = new QStandardItemModel(10, 5, this);                       //��������ģ��
    m_seleModel = new QItemSelectionModel(m_model);                      //Itemѡ��ģ��

    connect(m_seleModel, SIGNAL(currentChanged(QModelIndex, QModelIndex)), this, SLOT(on_currentChanged(QModelIndex, QModelIndex)));
    ui->tableView->setModel(m_model);
    ui->tableView->setSelectionModel(m_seleModel);
    //����״̬�����
    m_labCellPos = new QLabel(QString::fromLocal8Bit("��ǰ��Ԫ��"), this);
    m_labCellPos->setMinimumWidth(180);
    m_labCellPos->setAlignment(Qt::AlignHCenter);

    m_labCellText = new QLabel(QString::fromLocal8Bit("��Ԫ�����ݣ�"), this);
    m_labCellText->setMinimumWidth(200);

    ui->statusbar->addWidget(m_labCellPos);
    ui->statusbar->addWidget(m_labCellText);
}

void ExCustomMainWin::on_currentChanged(const QModelIndex& current, const QModelIndex& previous)
{

}


ExCustomMainWin::~ExCustomMainWin()
{
    delete ui;
}
