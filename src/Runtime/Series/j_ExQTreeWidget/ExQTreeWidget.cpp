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
    m_labFlie = new QLabel(QString::fromLocal8Bit("当前文件的路径:"), this);
    ui->statusbar->addWidget(m_labFlie);
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

//图片自动适应高度
void ExQTreeWidget::on_actAdaptiveHeight_triggered()
{
    int height = ui->scrollArea->height();                        //得到scrollArea的高度
    int realHeight = m_curPixmap.height();                        //原始图片的实际高度
    m_ratio = height * 1.0 / realHeight;                          //当前显示比例，必须转换为浮点数

    QPixmap pixmap = m_curPixmap.scaledToHeight(height - 50);     //图片缩放到指定高度
    ui->labDisplay->setPixmap(pixmap);                            //设置Label的PixMap
}

//图片自动适应宽度
void ExQTreeWidget::on_actAdaptiveWidth_triggered()
{
    int width = ui->scrollArea->width();
    int realWidth = m_curPixmap.width();
    m_ratio = width * 1.0 / realWidth;

    QPixmap pixmap = m_curPixmap.scaledToHeight(width - 50);
    ui->labDisplay->setPixmap(pixmap);
}

//放大
void ExQTreeWidget::on_actAmplification_triggered()
{
    m_ratio *= 1.2;                                             //在当前比例基础上乘以0.8
    int height = m_curPixmap.height() * m_ratio;                // 显示宽度
    int widht = m_curPixmap.width() * m_ratio;                  // 显示宽度

    QPixmap pix = m_curPixmap.scaled(widht, height);            //图片缩放到指定高度和宽度，保持长宽比例
    ui->labDisplay->setPixmap(pix);

}

//缩小
void ExQTreeWidget::on_actShrink_triggered()
{
    m_ratio *= 0.8;
    int height = m_curPixmap.height() * m_ratio;
    int widht = m_curPixmap.width() * m_ratio;

    QPixmap pix = m_curPixmap.scaled(widht, height);
    ui->labDisplay->setPixmap(pix);
}

//还原
void ExQTreeWidget::on_actZoomRealSize_triggered()
{
    m_ratio = 1;
    int height = m_curPixmap.height();
    int widht = m_curPixmap.width();

    QPixmap pix = m_curPixmap.scaled(widht, height);
    ui->labDisplay->setPixmap(pix);
}

void ExQTreeWidget::on_treeFiles_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous)
{
    if (current != nullptr && previous != nullptr) {
        displayImage(current);
    }
}

void ExQTreeWidget::displayImage(QTreeWidgetItem* item)
{
    QString fileName = item->data(treeColNum::colItem, Qt::UserRole).toString();
    m_labFlie->setText(fileName);
    m_curPixmap.load(fileName);
    on_actAdaptiveHeight_triggered();

    ui->actAmplification->setEnabled(true);
    ui->actShrink->setEnabled(true);
    ui->actZoomRealSize->setEnabled(true);
    ui->actAdaptiveHeight->setEnabled(true);
    ui->actAdaptiveWidth->setEnabled(true);
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
