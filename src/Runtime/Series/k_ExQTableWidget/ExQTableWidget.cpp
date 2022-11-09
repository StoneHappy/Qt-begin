#include "ExQTableWidget.h"
#include "ui_ExQTableWidget.h"

ExQTableWidget::ExQTableWidget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ExQTableWidget)
{
    ui->setupUi(this);
    setWindowTitle(QString::fromLocal8Bit("QTableWidget的讲解和使用"));

    m_labCellIndex = new QLabel(QString::fromLocal8Bit("当前单元格坐标："), this);          //状态栏初始化
    m_labCellIndex->setMinimumWidth(250);
    m_labCellType = new QLabel(QString::fromLocal8Bit("当前单元格类型："), this);
    m_labCellType->setMinimumWidth(200);
    m_labStudID = new QLabel(QString::fromLocal8Bit("学生ID："), this);
    m_labStudID->setMinimumWidth(200);
    ui->statusbar->addWidget(m_labCellIndex);
    ui->statusbar->addWidget(m_labCellType);
    ui->statusbar->addWidget(m_labStudID);
    ui->chkBoxHeadEdit->setChecked(Qt::Unchecked);
}

ExQTableWidget::~ExQTableWidget()
{
    delete ui;
}
