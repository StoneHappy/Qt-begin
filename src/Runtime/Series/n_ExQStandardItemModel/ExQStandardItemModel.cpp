#include "ExQStandardItemModel.h"
#include "ui_ExQStandardItemModel.h"
#include <QToolButton>
ExQStandardItemModel::ExQStandardItemModel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ExQStandardItemModel)
{
    ui->setupUi(this);
    setWindowTitle(QString::fromLocal8Bit("QTableView��QStandardItemModel���÷�"));

    ui->toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);     //��������������ͼ����ʽ���

    m_labCurrFile = new QLabel(QString::fromLocal8Bit("��ǰ�ļ���"), this);                       //����״̬��
    m_labCellPos = new QLabel(QString::fromLocal8Bit("��ǰ��Ԫ��"), this);
    m_labCellText = new QLabel(QString::fromLocal8Bit("��Ԫ�����ݣ�"), this);
    m_labCurrFile->setMinimumWidth(200);
    m_labCellPos->setMinimumWidth(200);
    m_labCellText->setMinimumWidth(200);
    ui->statusbar->addWidget(m_labCurrFile);
    ui->statusbar->addWidget(m_labCellPos);
    ui->statusbar->addWidget(m_labCellText);
}

ExQStandardItemModel::~ExQStandardItemModel()
{
    delete ui;
}
