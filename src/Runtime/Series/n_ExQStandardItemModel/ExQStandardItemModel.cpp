#include "ExQStandardItemModel.h"
#include "ui_ExQStandardItemModel.h"
#include <QToolButton>
#include <QStandardItemModel>
#include <QFileDialog>
#include <QTextStream>
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
   
}

ExQStandardItemModel::~ExQStandardItemModel()
{
    delete ui;
}
