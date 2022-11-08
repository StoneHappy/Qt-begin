#include "ExQTreeWidget.h"
#include "ui_ExQTreeWidget.h"
#include <qicon.h>
#include <qnamespace.h>
#include <qtreewidget.h>
#include <qvariant.h>

ExQTreeWidget::ExQTreeWidget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ExQTreeWidget)
{
    ui->setupUi(this);

    setWindowTitle(QString::fromLocal8Bit("QTreeWidget和QDockWidget的讲解和使用"));

    setCentralWidget(ui->scrollArea);
    initTree();
    
}

void ExQTreeWidget::initTree()
{
    ui->treeFiles->clear();


    QString dataStr = "";
    QIcon icon;

    icon.addFile(":/images/Image001.jpg");

    QTreeWidgetItem* root = new QTreeWidgetItem(treeItemType::itemRoot);
    root->setIcon(treeColNum::colItem, icon);
    root->setText(treeColNum::colItem, QString::fromLocal8Bit("相簿"));
    root->setText(treeColNum::colItemType, QString::fromLocal8Bit("treeItemType"));
    root->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsAutoTristate);
    root->setCheckState(treeColNum::colItem, Qt::Unchecked);
    root->setData(treeColNum::colItem, Qt::UserRole, QVariant(dataStr));

    ui->treeFiles->addTopLevelItem(root);
}


ExQTreeWidget::~ExQTreeWidget()
{
    delete ui;
}
