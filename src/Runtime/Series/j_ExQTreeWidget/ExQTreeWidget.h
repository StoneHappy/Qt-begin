#ifndef EXQTREEWIDGET_H
#define EXQTREEWIDGET_H

#include <QMainWindow>
#include <qobjectdefs.h>

namespace Ui {
class ExQTreeWidget;
}

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
    void initTree();

private:
    Ui::ExQTreeWidget *ui;
};

#endif // EXQTREEWIDGET_H
