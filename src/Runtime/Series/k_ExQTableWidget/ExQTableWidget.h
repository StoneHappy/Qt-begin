#ifndef EXQTABLEWIDGET_H
#define EXQTABLEWIDGET_H

#include <QMainWindow>

namespace Ui {
class ExQTableWidget;
}

class ExQTableWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit ExQTableWidget(QWidget *parent = nullptr);
    ~ExQTableWidget();

private:
    Ui::ExQTableWidget *ui;
};

#endif // EXQTABLEWIDGET_H
