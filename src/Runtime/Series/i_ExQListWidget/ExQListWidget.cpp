#include "ExQListWidget.h"
#include "ui_ExQListWidget.h"
#include <iostream>
#include <qdatetime.h>
#include <qicon.h>
#include <qlistwidget.h>
#include <qmenu.h>
#include <qnamespace.h>
#include <QPushButton>
#include <qtoolbutton.h>
ExQListWidget::ExQListWidget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ExQListWidget)
{
    ui->setupUi(this);
    setWindowTitle(QString::fromLocal8Bit("QListWidget和QToolButton用法"));

    setCentralWidget(ui->splitter);

    setActionForToolBtn();
    creatorPopMenu();
    ui->listWidget->setContextMenuPolicy(Qt::CustomContextMenu);   //设置QListWidget支持右键菜单,这句话一定要有
}

ExQListWidget::~ExQListWidget()
{
    delete ui;
}

void ExQListWidget::setActionForToolBtn()
{
    ui->toolBtnInit->setDefaultAction(ui->actListInit);
    ui->toolBtnClear->setDefaultAction(ui->actClear);
    ui->toolBtnInsert->setDefaultAction(ui->actInsert);
    ui->toolBtnAdd->setDefaultAction(ui->actAdd);
    ui->toolBtnDelete->setDefaultAction(ui->actDel);

    ui->toolBtnSelAll->setDefaultAction(ui->actSelAll);
    ui->toolBtnSelNone->setDefaultAction(ui->actSelInvs);
    ui->toolBtnSelInvs->setDefaultAction(ui->actSelNone);
}

void ExQListWidget::creatorPopMenu()
{
    QMenu* menu = new QMenu(this);
    menu->addAction(ui->actSelAll);
    menu->addAction(ui->actSelInvs);
    menu->addAction(ui->actSelNone);

    ui->toolBtnSelectItem->setDefaultAction(ui->actSelPopMenu);
    ui->toolBtnSelectItem->setMenu(menu);

    QToolButton* toolBtn = new QToolButton(this);
    toolBtn->setPopupMode(QToolButton::InstantPopup);
    toolBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    toolBtn->setDefaultAction(ui->actSelPopMenu);
    toolBtn->setMenu(menu);
    ui->toolBar->addSeparator();
    ui->toolBar->addWidget(toolBtn);

    ui->toolBar->addSeparator();
    ui->toolBar->addAction(ui->actExit);
}

void ExQListWidget::on_actListInit_triggered()
{
    QListWidgetItem* item;
    QIcon icon;
    icon.addFile(":/images/github.png");

    bool chk = ui->checkBox->isChecked();
    ui->listWidget->clear();
    for (int i = 0; i < 13; i++) {
        item = new QListWidgetItem();
        item->setText(QString::fromLocal8Bit("初始化 第%1个项item").arg(i));
        item->setIcon(icon);
        item->setCheckState(Qt::Unchecked);

        if (chk)
            item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEditable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        else
            item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);

        ui->listWidget->addItem(item);
    }
}

void ExQListWidget::on_actInsert_triggered()
{
    QListWidgetItem* item;
    QIcon icon;
    icon.addFile(":/images/girl.png");

    bool chk = ui->checkBox->isChecked();

    item = new QListWidgetItem();
    item->setText(QDateTime::currentDateTime().toString("yyyy-mm-dd hh:MM:ss:zzz"));
    item->setIcon(icon);
    item->setCheckState(Qt::Unchecked);

    if (chk)
        item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEditable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
    else
        item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);

    ui->listWidget->insertItem(ui->listWidget->currentRow(), item);
}

void ExQListWidget::on_actClear_triggered()
{
    ui->listWidget->clear();
}

void ExQListWidget::on_actDel_triggered()
{
    int row = ui->listWidget->currentRow();
    QListWidgetItem* item = ui->listWidget->takeItem(row);
    delete item;
}

void ExQListWidget::on_actAdd_triggered()
{
    QListWidgetItem* item;
    QIcon icon;
    icon.addFile(":/images/girl.png");

    bool chk = ui->checkBox->isChecked();

    item = new QListWidgetItem();
    item->setText(QDateTime::currentDateTime().toString("yyyy-mm-dd hh:MM:ss:zzz"));
    item->setIcon(icon);
    item->setCheckState(Qt::Unchecked);

    if (chk)
        item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEditable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
    else
        item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);

    ui->listWidget->addItem(item);
}

void ExQListWidget::on_actSelAll_triggered()
{
    int nCount = ui->listWidget->count();

    for (int i = 0; i < nCount; i++) {
        QListWidgetItem* item = ui->listWidget->item(i);
        item->setCheckState(Qt::Checked);
    }
}

void ExQListWidget::on_actSelNone_triggered()
{
    int nCount = ui->listWidget->count();

    for (int i = 0; i < nCount; i++) {
        QListWidgetItem* item = ui->listWidget->item(i);
        item->setCheckState(Qt::Unchecked);
    }
}

void ExQListWidget::on_actSelInvs_triggered()
{
    int nCount = ui->listWidget->count();

    for (int i = 0; i < nCount; i++) {
        QListWidgetItem* item = ui->listWidget->item(i);
        if (item->checkState() == Qt::Checked) 
            item->setCheckState(Qt::Unchecked);
        else
            item->setCheckState(Qt::Checked);
    }
}

//鼠标右键自定义快捷菜单
void ExQListWidget::on_listWidget_customContextMenuRequested(const QPoint &pos)
{
    Q_UNUSED(pos)
    QMenu* menu = new QMenu(this);                                         //创建菜单
    menu->addAction(ui->actListInit);
    menu->addAction(ui->actAdd);
    menu->addAction(ui->actDel);
    menu->addAction(ui->actClear);
    menu->addAction(ui->actInsert);
    menu->addSeparator();
    menu->addAction(ui->actSelAll);
    menu->addAction(ui->actSelNone);
    menu->addAction(ui->actSelInvs);
    menu->exec(QCursor::pos());                                            //在鼠标光标位置显示右键快捷菜单
    delete menu;                                                           //手工创建的指针必须手工删除
}

void ExQListWidget::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    ui->lineEditRight->clear();
    if (current != nullptr) {
        if (previous == nullptr) 
            ui->lineEditRight->setText(QString::fromLocal8Bit("当前项:%1；  前一项%2").arg(current->text()).arg(QString::fromLocal8Bit("不存在")));
        else
            ui->lineEditRight->setText(QString::fromLocal8Bit("当前项:%1；  前一项%2").arg(current->text()).arg(previous->text()));
    }
}

//退出
void ExQListWidget::on_actExit_triggered()
{
    this->close();
}
