#include "ExMainWindow.h"
#include "ui_ExMainWindow.h"
#include <QDir>
#include <QFileDialog>
#include <QMdiSubWindow>
#include "ExMDI.h"
ExMainWindow::ExMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ExMainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->mdiArea);
    setWindowState(Qt::WindowMaximized);
    ui->toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
}

ExMainWindow::~ExMainWindow()
{
    delete ui;
}

void ExMainWindow::on_actNew_triggered()
{
    ExMDI* mdi = new ExMDI(this);
    ui->mdiArea->addSubWindow(mdi);
    mdi->show();

    ui->actCopy->setEnabled(true);
    ui->actCut->setEnabled(true);
    ui->actPaste->setEnabled(true);
    ui->actFont->setEnabled(true);
}

void ExMainWindow::on_actOpen_triggered()
{
    bool needNew = false;
    ExMDI* mdi = nullptr;

    if (ui->mdiArea->subWindowList().count() > 0) {  //如果有打开的主窗口，获取活动窗口
        mdi = (ExMDI*)ui->mdiArea->activeSubWindow()->widget();
        needNew = mdi->isFileOpended();   //文件已经打开，需要新建窗口
    }
    else {
        needNew = true;
    }

    QString curPath = QDir::currentPath();
    QString fileName = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("打开一个文件"), curPath, QString::fromLocal8Bit("C程序文件(*.h *cpp);;文本文件(*.txt);;所有文件(*.*)"));
    if (fileName.isEmpty()) return;

    if (needNew)
    {
        mdi = new ExMDI(this);
        ui->mdiArea->addSubWindow(mdi);
    }
    

    mdi->loadFromFile(fileName);
    mdi->show();

    ui->actCopy->setEnabled(true);
    ui->actCut->setEnabled(true);
    ui->actPaste->setEnabled(true);
    ui->actFont->setEnabled(true);
}

