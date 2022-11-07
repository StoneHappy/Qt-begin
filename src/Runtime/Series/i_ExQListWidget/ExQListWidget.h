#ifndef EXQLISTWIDGET_H
#define EXQLISTWIDGET_H

#include <QMainWindow>
#include <QListWidgetItem>
namespace Ui {
class ExQListWidget;
}

class ExQListWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit ExQListWidget(QWidget *parent = nullptr);
    ~ExQListWidget();

private slots:
    void on_actListInit_triggered();
    void on_actInsert_triggered();
    void on_actClear_triggered();
    void on_actDel_triggered();
    void on_actAdd_triggered();
    void on_actSelAll_triggered();
    void on_actSelNone_triggered();
    void on_actSelInvs_triggered();
    void on_listWidget_customContextMenuRequested(const QPoint &pos);
    void on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);
    void on_actExit_triggered();

    void setActionForToolBtn();
    void creatorPopMenu();


private:
    Ui::ExQListWidget *ui;
};

#endif // EXQLISTWIDGET_H
