#include "ExQTreeWidget.h"
#include "ui_ExQTreeWidget.h"
#include <qicon.h>
#include <qnamespace.h>
#include <qtreewidget.h>
#include <qvariant.h>
#include <QFileDialog>

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

//添加目录节点
void ExQTreeWidget::addFolderItem(QTreeWidgetItem *parItem, QString dirName)
{
    QIcon icon;
    icon.addFile(":/image/Image006.jpg");

    //添加一个新的节点
    QTreeWidgetItem* item = new QTreeWidgetItem(treeItemType::itemFile);
    QString folderName = getFinalFolderName(dirName);
    item->setIcon(treeColNum::colItem, icon);
    item->setText(treeColNum::colItem, folderName);
    item->setText(treeColNum::colItemType, QString("treeItemType"));
    item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsAutoTristate);
    item->setCheckState(treeColNum::colItem, Qt::Unchecked);
    item->setData(treeColNum::colItem, Qt::UserRole, QVariant(dirName));
    parItem->addChild(item);
}

void ExQTreeWidget::addImageItem(QTreeWidgetItem *parItem, QString fileName)
{
    if (parItem == nullptr) return;

    QIcon icon;
    icon.addFile(":/image/Image014.jpg");

    QTreeWidgetItem* item = new QTreeWidgetItem(treeItemType::itemImage);
    QString folderName = getFinalFolderName(fileName);
    item->setIcon(treeColNum::colItem, icon);
    item->setText(treeColNum::colItem, folderName);
    item->setText(treeColNum::colItemType, QString::fromLocal8Bit("treeItemType"));
    item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsAutoTristate);
    item->setData(treeColNum::colItem, Qt::UserRole, QVariant(fileName));
    parItem->addChild(item);

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//增加文件夹
void ExQTreeWidget::on_actAddFolder_triggered()
{
    QString path = QFileDialog::getExistingDirectory();             //选择目录
    if (! path.isEmpty()) {
        QTreeWidgetItem* item = ui->treeFiles->currentItem();       //获取当前节点

        if(item != nullptr)
            addFolderItem(item, path);
    }
}

void ExQTreeWidget::on_actAddFile_triggered()
{
    QStringList list = QFileDialog::getOpenFileNames(this, QString::fromLocal8Bit("选择多个将要加载的图片"), "", "Images(*.jpg, *.png, *.*)");             //选择目录
    if (! list.isEmpty()) {
        QTreeWidgetItem* parItem = nullptr;
        QTreeWidgetItem* item = ui->treeFiles->currentItem();       //获取当前节点

        if(item == nullptr) return;

        if (item->type() == treeItemType::itemImage) {
            parItem = item->parent();
        }
        else {
            parItem = item;
        }
        for (int i = 0; i < list.size(); ++i) {
            QString strName = list.at(i);
            addImageItem(parItem, strName);
        }
    }
}

//从完整的路径里面，获取最后的文件夹名称
QString ExQTreeWidget::getFinalFolderName(const QString &pathName)
{
    QString path = pathName;
    int cnt = pathName.count();
    int i = pathName.lastIndexOf("/");
    QString str = pathName.right(cnt - i - 1);
    return str;
}

ExQTreeWidget::~ExQTreeWidget()
{
    delete ui;
}
