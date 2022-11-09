#include "ExQTableWidget.h"
#include "ui_ExQTableWidget.h"
#include <qfont.h>
#include <qtablewidget.h>

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

    setCentralWidget(ui->splitter_2);
    on_btnSetHeader_clicked();
}

void ExQTableWidget::on_btnSetHeader_clicked()
{
    QTableWidgetItem* item = nullptr;
    QStringList list;
    list << QString::fromLocal8Bit("姓名") << QString::fromLocal8Bit("性别") << QString::fromLocal8Bit("出生日期") << QString::fromLocal8Bit("籍贯") << QString::fromLocal8Bit("分数") << QString::fromLocal8Bit("是否喜欢二次元");

    ui->tableWidget->setColumnCount(list.count());
    for (int i = 0; i < ui->tableWidget->columnCount(); ++i) {
        item = new QTableWidgetItem(list.at(i));
        QFont font;
        font.setBold(true);
        font.setPointSize(12);
        item->setFont(font);
        item->setTextColor(Qt::red);
        ui->tableWidget->setHorizontalHeaderItem(i, item);
    }
    
}


ExQTableWidget::~ExQTableWidget()
{
    delete ui;
}
