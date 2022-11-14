#include "ExQStandardItemModel.h"
#include "ui_ExQStandardItemModel.h"
#include <QToolButton>
ExQStandardItemModel::ExQStandardItemModel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ExQStandardItemModel)
{
    ui->setupUi(this);
    setWindowTitle(QString::fromLocal8Bit("QTableView和QStandardItemModel的用法"));

    ui->toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);     //设置主工具栏的图标样式风格

    m_labCurrFile = new QLabel(QString::fromLocal8Bit("当前文件："), this);                       //设置状态栏
    m_labCellPos = new QLabel(QString::fromLocal8Bit("当前单元格："), this);
    m_labCellText = new QLabel(QString::fromLocal8Bit("单元格内容："), this);
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
