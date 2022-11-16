#include "ExCustomMainWin.h"
#include "ExDlgSetHeaders.h"
#include "ExDlgLocate.h"
#include "ExDlgSize.h"
#include "ui_ExCustomMainWin.h"

#include <QStandardItemModel>
#include <QItemSelectionModel>
#include <QLabel>

ExCustomMainWin::ExCustomMainWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ExCustomMainWin)
{
    ui->setupUi(this);
    setWindowTitle(QString::fromLocal8Bit("自定义和标准对话框的用法"));

    m_model = nullptr;

    m_model = new QStandardItemModel(10, 5, this);                       //创建数据模型
    m_seleModel = new QItemSelectionModel(m_model);                      //Item选择模型

    connect(m_seleModel, SIGNAL(currentChanged(QModelIndex, QModelIndex)), this, SLOT(on_currentChanged(QModelIndex, QModelIndex)));
    ui->tableView->setModel(m_model);
    ui->tableView->setSelectionModel(m_seleModel);
    //创建状态栏组件
    m_labCellPos = new QLabel(QString::fromLocal8Bit("当前单元格："), this);
    m_labCellPos->setMinimumWidth(180);
    m_labCellPos->setAlignment(Qt::AlignHCenter);

    m_labCellText = new QLabel(QString::fromLocal8Bit("单元格内容："), this);
    m_labCellText->setMinimumWidth(200);

    ui->statusbar->addWidget(m_labCellPos);
    ui->statusbar->addWidget(m_labCellText);
}

void ExCustomMainWin::on_currentChanged(const QModelIndex& current, const QModelIndex& previous)
{
    if (current.isValid())
    {
        QStandardItem* item;
        item = m_model->itemFromIndex(current);

        m_labCellPos->setText(QString::fromLocal8Bit("当前单元格：%1行，%2列").arg(current.row()).arg(current.column()));
        m_labCellText->setText(QString::fromLocal8Bit("单元格内容: %1").arg(item->text()));
    }
}


ExCustomMainWin::~ExCustomMainWin()
{
    delete ui;
}

void ExCustomMainWin::setACellText(int row, int col, QString text)
{
    QModelIndex index = m_model->index(row, col);
    m_seleModel->clearSelection();
    m_seleModel->setCurrentIndex(index, QItemSelectionModel::Select);
    m_model->setData(index, text, Qt::DisplayRole);
}

void ExCustomMainWin::setActLocateEnable(bool enable)
{
    ui->actLocate->setEnabled(enable);
}

void ExCustomMainWin::setDlgLocateNull()
{
    m_dlglocate = nullptr;
}

void ExCustomMainWin::on_actSetHeader_triggered()
{
    if (m_dlgSetHeaders == nullptr)
        m_dlgSetHeaders = new ExDlgSetHeaders(this);

    if (m_dlgSetHeaders->headerList().count() != m_model->columnCount())
    {
        QStringList list;

        for (size_t i = 0; i < m_model->rowCount(); i++)
        {
            list.append(m_model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString());
        }
        m_dlgSetHeaders->setHeaderList(list);
    }

    int ret = m_dlgSetHeaders->exec();
    if (ret == QDialog::Accepted)
    {
        QStringList list = m_dlgSetHeaders->headerList();
        m_model->setHorizontalHeaderLabels(list);
    }

}

void ExCustomMainWin::on_actLocate_triggered()
{
    ui->actLocate->setEnabled(false);
    m_dlglocate = new ExDlgLocate(this);

    Qt::WindowFlags flags = m_dlglocate->windowFlags();
    m_dlglocate->setWindowFlags(flags | Qt::WindowStaysOnTopHint);

    m_dlglocate->setSpinRange(m_model->rowCount(), m_model->columnCount());
    QModelIndex curIndex = m_seleModel->currentIndex();
    if (curIndex.isValid())
    {
        m_dlglocate->setSpinValue(curIndex.row(), curIndex.column());
    }
    m_dlglocate->show();
}

void ExCustomMainWin::on_actSetSize_triggered()
{
    ExDlgSize* dlgSize = new ExDlgSize(this);
    Qt::WindowFlags flags = dlgSize->windowFlags();
    dlgSize->setWindowFlags(flags | Qt::MSWindowsFixedSizeDialogHint);
    dlgSize->setRowCol(m_model->rowCount(), m_model->columnCount());
    int ret = dlgSize->exec();

    if (ret == QDialog::Accepted)
    {
        int row = dlgSize->getRowCout();
        int col = dlgSize->getColCount();
        m_model->setRowCount(row);
        m_model->setColumnCount(col);
    }

    delete dlgSize;
}
