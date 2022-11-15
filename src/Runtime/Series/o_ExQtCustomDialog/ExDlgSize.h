#ifndef EXDLGSIZE_H
#define EXDLGSIZE_H

#include <QDialog>

namespace Ui {
class ExDlgSize;
}

class ExDlgSize : public QDialog
{
    Q_OBJECT

public:
    explicit ExDlgSize(QWidget *parent = nullptr);
    ~ExDlgSize();

private:
    Ui::ExDlgSize *ui;
};

#endif // EXDLGSIZE_H
