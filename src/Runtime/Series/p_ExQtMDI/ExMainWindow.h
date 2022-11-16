#ifndef EXMAINWINDOW_H
#define EXMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class ExMainWindow;
}

class ExMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ExMainWindow(QWidget *parent = nullptr);
    ~ExMainWindow();

private slots:
    void on_actOpen_triggered();
    void on_actNew_triggered();

private:
    Ui::ExMainWindow *ui;
};

#endif // EXMAINWINDOW_H
