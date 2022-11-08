#ifndef EXQTREEWIDGET_H
#define EXQTREEWIDGET_H

#include <QMainWindow>
#include <qobjectdefs.h>

namespace Ui {
class ExQTreeWidget;
}

class QTreeWidgetItem;
class QLabel;

class ExQTreeWidget : public QMainWindow
{
    Q_OBJECT

public:
    enum treeItemType {         //枚举，节点类型
        itemRoot,
        itemFile,
        itemImage
    };

     enum treeColNum {           //目录树列表的编号
        colItem = 0,
        colItemType = 1
    };

public:
    explicit ExQTreeWidget(QWidget *parent = nullptr);
    ~ExQTreeWidget();

private slots:
    void on_actAddFolder_triggered();
    void on_actAddFile_triggered();
    void on_actAdaptiveHeight_triggered();
    void on_treeFiles_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);
    void on_actAmplification_triggered();
    void on_actShrink_triggered();
    void on_actZoomRealSize_triggered();
    void on_actAdaptiveWidth_triggered();

private:
    void initTree();
    void addFolderItem(QTreeWidgetItem *parItem, QString dirName);
    void addImageItem(QTreeWidgetItem *parItem, QString fileName);

    QString getFinalFolderName(const QString &pathName);
    void displayImage(QTreeWidgetItem* item);

private:
    Ui::ExQTreeWidget *ui;
    QLabel *m_labFlie;      //状态栏显示当前文件路径
    QPixmap m_curPixmap;    //显示当前文件图片
    float m_ratio;
};

#endif // EXQTREEWIDGET_H
