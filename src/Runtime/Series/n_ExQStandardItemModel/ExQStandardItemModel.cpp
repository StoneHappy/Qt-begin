#include "ExQStandardItemModel.h"
#include "ui_ExQStandardItemModel.h"
#include <QToolButton>
#include <QStandardItemModel>

#define COLUMN 6  //数据表的列数

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

    m_model = new QStandardItemModel(2, COLUMN, this);                          //设置数据模型，一开始设置为默认的2行6列表的一个表    m_selectModet = new QItemSelectionModel(m_model, this);                //设置选择模型
    m_selectModet = new QItemSelectionModel(m_model, this);                //设置选择模型
    ui->tableView->setModel(m_model);                                      //设置数据模型
    ui->tableView->setSelectionModel(m_selectModet);                       //设置选择模型
    ui->tableView->setSelectionMode(QAbstractItemView::ExtendedSelection); //设置选择模式
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectItems);   //设置选择行为
    connect(m_selectModet, SIGNAL(currentChanged(QModelIndex, QModelIndex)), this, SLOT(onCurrentChanged(QModelIndex, QModelIndex)));  //选择当前单元格变化时的信号与槽
}

void ExQStandardItemModel::onCurrentChanged(const QModelIndex& current, const QModelIndex& previous)
{
    if (current.isValid()) {                                               //当前模型索性有效
        m_labCellPos->setText(QString::fromLocal8Bit("当前单元格：%1行, %2列").arg(current.row()).arg(current.column()));
        QStandardItem* item = m_model->itemFromIndex(current);             //从模型索引获得Item
        m_labCellText->setText(QString::fromLocal8Bit("当前文件：%1").arg(item->text()));  //显示item的文字内容

        QFont font = item->font();
        ui->actBold->setChecked(font.bold());                              //更新actFontBold的check状态
    }
}

ExQStandardItemModel::~ExQStandardItemModel()
{
    delete ui;
}
