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

    if (ui->mdiArea->subWindowList().count() > 0) {  //����д򿪵������ڣ���ȡ�����
        mdi = (ExMDI*)ui->mdiArea->activeSubWindow()->widget();
        needNew = mdi->isFileOpended();   //�ļ��Ѿ��򿪣���Ҫ�½�����
    }
    else {
        needNew = true;
    }

    QString curPath = QDir::currentPath();
    QString fileName = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("��һ���ļ�"), curPath, QString::fromLocal8Bit("C�����ļ�(*.h *cpp);;�ı��ļ�(*.txt);;�����ļ�(*.*)"));
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

