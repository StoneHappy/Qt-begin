#ifndef EXDIALOG_H
#define EXDIALOG_H

#include <QMainWindow>

namespace Ui {
class ExDialog;
}

class ExDialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit ExDialog(QWidget *parent = nullptr);
    ~ExDialog();

private:
    Ui::ExDialog *ui;
};

#endif // EXDIALOG_H
