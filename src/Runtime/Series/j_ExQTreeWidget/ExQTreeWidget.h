#ifndef EXQTREEWIDGET_H
#define EXQTREEWIDGET_H

#include <QMainWindow>

namespace Ui {
class ExQTreeWidget;
}

class ExQTreeWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit ExQTreeWidget(QWidget *parent = nullptr);
    ~ExQTreeWidget();

private:
    Ui::ExQTreeWidget *ui;
};

#endif // EXQTREEWIDGET_H
