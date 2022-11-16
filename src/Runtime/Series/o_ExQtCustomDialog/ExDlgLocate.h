#ifndef EXDLGLOCATE_H
#define EXDLGLOCATE_H

#include <QDialog>

namespace Ui {
class ExDlgLocate;
}

class ExDlgLocate : public QDialog
{
    Q_OBJECT

public:
    explicit ExDlgLocate(QWidget *parent = nullptr);
    ~ExDlgLocate();

    void setSpinRange(int rowCount, int colCount);
    void setSpinValue(int rowNo, int colNo);
private:
    Ui::ExDlgLocate *ui;
};

#endif // EXDLGLOCATE_H
