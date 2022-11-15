#include "ExQStandardItemModel.h"
#include "ui_ExQStandardItemModel.h"
#include <QToolButton>
#include <QStandardItemModel>
#include <QFileDialog>
#include <QTextStream>
#include "ExDelegate.h"
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

//action+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//打开和导入文件，并且在plainTextEdit里面显示
void ExQStandardItemModel::on_actOpen_triggered()
{
    QString currPath = QCoreApplication::applicationDirPath();
    QString fileName = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("打开一个文件"), currPath, QString::fromLocal8Bit("导入数据文件(*txt);;所有文件(*.*)"));

    if (fileName.isEmpty())
        return;

    QStringList list;
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {                //只读形式打开文本文件
        QTextStream stream(&file);                                         //用文本流读取文件
        ui->plainTextEdit->clear();

        while (!stream.atEnd()) {                                          //读取文本中文本的内容
            QString str = stream.readLine();
            ui->plainTextEdit->appendPlainText(str);
            list.append(str);
        }

        file.close();                                                      //关闭
        m_labCurrFile->setText("当前文件：" + fileName);                    //设置状态栏

        ui->actAppend->setEnabled(true);                                   //设置action的Enabled的属性
        ui->actInsert->setEnabled(true);
        ui->actDelete->setEnabled(true);
        ui->actSave->setEnabled(true);
    }

    init(list);                                                            //初始化.txt的数据
}

//从list初始化数据模型QTableView里面
void ExQStandardItemModel::init(QStringList& list)
{
    int rowCount = list.count();                                           //文本行数，第一行为表头
    m_model->setRowCount(rowCount - 1);

    QString header = list.at(0);
    QStringList headerList = header.split(QRegExp("\\s+"), QString::SkipEmptyParts); //通过一个或者多个空格或者tab按键切割
    m_model->setHorizontalHeaderLabels(headerList);                       //设置表头

    QStandardItem* item = nullptr;                                        //此处开始，设置表格数据
    QStringList tempList;
    int j = 0;

    for (int i = 1; i < rowCount; i++) {
        QString aLineText = list.at(i);
        tempList = aLineText.split(QRegExp("\\s+"), QString::SkipEmptyParts);//正则表达式中\s匹配任何空白字符，包括空格、制表符、换页符等等, 等价于[ \f\n\r\t\v]

        for (j = 0; j < COLUMN - 1; j++) {                                     //设置前5列的item

            if (j == 3) {
                ExDelegate* itemDelegate = new ExDelegate();
                ui->tableView->setItemDelegateForColumn(3, itemDelegate);
            }

            item = new QStandardItem(tempList.at(j));
            m_model->setItem(i - 1, j, item);
        }



        item = new QStandardItem(tempList.at(j));                          //最后一列的item
        item->setCheckable(true);                                          //设置有检查框

        if (tempList.at(j) == "https://www.google.com")
            item->setCheckState(Qt::Unchecked);
        else
            item->setCheckState(Qt::Checked);

        m_model->setItem(i - 1, COLUMN - 1, item);
    }
}

void ExQStandardItemModel::on_actAppend_triggered()
{
    QList<QStandardItem*> list;
    QStandardItem* item;

    for (size_t i = 0; i < COLUMN - 1; i++)
    {
        item = new QStandardItem(QString::fromLocal8Bit("添加一行"));
        list << item;
    }

    QString str = m_model->headerData(m_model->columnCount() - 1, Qt::Horizontal, Qt::DisplayRole).toString();
    item = new QStandardItem(str + QString::fromLocal8Bit("添加一行"));
    item->setCheckable(true);
    list << item;
    m_model->insertRow(m_model->rowCount(), list);
    QModelIndex currIndex = m_model->index(m_model->rowCount() - 1, 0);
    m_selectModet->clearSelection();
    m_selectModet->setCurrentIndex(currIndex, QItemSelectionModel::Select);
}


void ExQStandardItemModel::on_actSave_triggered()
{
    QString path = QCoreApplication::applicationDirPath();
    QString fileName = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("选择一个文件"), path, QString::fromLocal8Bit("另存数据(*.txt);;所有数据(*.*)"));
    if (fileName.isEmpty()) return;

    QFile file(fileName);

    if (!file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate)) return;

    QTextStream stream(&file);
    QStandardItem* item;
    int i = 0, j = 0;
    QString str = "";
    ui->plainTextEdit->clear();

    for (i = 0; i < m_model->columnCount(); i++)
    {
        item = m_model->horizontalHeaderItem(i);
        str = str + item->text() + "\t\t";
    }

    stream << str << "\n";
    ui->plainTextEdit->appendPlainText(str);

    for (i = 0; i < m_model->rowCount(); i++)
    {
        str = "";

        for (j = 0; j < m_model->columnCount(); j++)
        {
            item = m_model->item(i, j);
            str = str + item->text() + "\t\t";
        }
        stream << str << "\n";
        ui->plainTextEdit->appendPlainText(str);
    }
}

void ExQStandardItemModel::on_actInsert_triggered()
{
    QList<QStandardItem*> list;
    QStandardItem* item;

    for (size_t i = 0; i < COLUMN - 1; i++)
    {
        item = new QStandardItem(QString::fromLocal8Bit("添加一行"));
        list << item;
    }

    QString str = m_model->headerData(m_model->columnCount() - 1, Qt::Horizontal, Qt::DisplayRole).toString();
    item = new QStandardItem(str + QString::fromLocal8Bit("添加一行"));
    item->setCheckable(true);
    list << item;

    QModelIndex currIndex = m_selectModet->currentIndex();
    m_model->insertRow(currIndex.row(), list);
    m_selectModet->clearSelection();
    m_selectModet->setCurrentIndex(currIndex, QItemSelectionModel::Select);
}

void ExQStandardItemModel::on_actDelete_triggered()
{
    QModelIndex currIndex = m_selectModet->currentIndex();
    m_model->removeRow(currIndex.row());
}

void ExQStandardItemModel::on_actExit_triggered()
{
    close();
}

void ExQStandardItemModel::on_actModelData_triggered()
{
    QStandardItem* item;
    int i = 0, j = 0;
    QString str = "";
    ui->plainTextEdit->clear();

    for (i = 0; i < m_model->columnCount(); i++)
    {
        item = m_model->horizontalHeaderItem(i);
        str = str + item->text() + "\t\t";
    }

    ui->plainTextEdit->appendPlainText(str);

    for (i = 0; i < m_model->rowCount(); i++)
    {
        str = "";

        for (j = 0; j < m_model->columnCount(); j++)
        {
            item = m_model->item(i, j);
            str = str + item->text() + "\t\t";
        }
        ui->plainTextEdit->appendPlainText(str);
    }
}

void ExQStandardItemModel::on_actAlignLeft_triggered()
{
    if (!m_selectModet->hasSelection()) return;

    QModelIndexList list = m_selectModet->selectedIndexes();

    for (size_t i = 0; i < list.count(); i++)
    {
        QModelIndex index = list.at(i);
        QStandardItem* item = m_model->itemFromIndex(index);
        item->setTextAlignment(Qt::AlignLeft);
    }
}

void ExQStandardItemModel::on_actAlignCenter_triggered()
{
    if (!m_selectModet->hasSelection())
        return;

    QModelIndexList list = m_selectModet->selectedIndexes();     //获得选中的List<item>

    for (int i = 0; i < list.count(); i++) {
        QModelIndex index = list.at(i);                          //获取一个模型索引
        QStandardItem* item = m_model->itemFromIndex(index);
        item->setTextAlignment(Qt::AlignCenter);                 //设置文本居中
    }
}
//文本右对齐
void ExQStandardItemModel::on_actAlingRight_triggered()
{
    if (!m_selectModet->hasSelection())
        return;

    QModelIndexList list = m_selectModet->selectedIndexes();

    for (int i = 0; i < list.count(); i++) {
        QModelIndex index = list.at(i);
        QStandardItem* item = m_model->itemFromIndex(index);
        item->setTextAlignment(Qt::AlignRight);
    }
}

void ExQStandardItemModel::on_actBold_triggered(bool checked)
{
    if (!m_selectModet->hasSelection())
        return;

    QModelIndexList list = m_selectModet->selectedIndexes();

    for (int i = 0; i < list.count(); i++) {
        QModelIndex index = list.at(i);
        QStandardItem* item = m_model->itemFromIndex(index);

        QFont font = item->font();
        font.setBold(checked);
        item->setFont(font);
    }
}

ExQStandardItemModel::~ExQStandardItemModel()
{
    delete ui;
}
