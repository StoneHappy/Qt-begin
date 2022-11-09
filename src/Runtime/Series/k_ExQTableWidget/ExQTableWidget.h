#ifndef EXQTABLEWIDGET_H
#define EXQTABLEWIDGET_H

#include <QMainWindow>
#include <qlabel.h>
namespace Ui {
class ExQTableWidget;
}

class QLabel;

class ExQTableWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit ExQTableWidget(QWidget *parent = nullptr);
    ~ExQTableWidget();

private:
    Ui::ExQTableWidget *ui;
    QLabel *m_labCellIndex;                              //状态栏上用来显示单元格的行号、列号
    QLabel *m_labCellType;                               //状态栏上用来显示单元格的type
    QLabel *m_labStudID;                                 //状态栏上用来显示单元格的学号
};

#endif // EXQTABLEWIDGET_H
