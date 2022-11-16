#ifndef EXMDI_H
#define EXMDI_H

#include <QWidget>

namespace Ui {
class ExMDI;
}

class ExMDI : public QWidget
{
    Q_OBJECT

public:
    explicit ExMDI(QWidget *parent = nullptr);
    ~ExMDI();

private:
    Ui::ExMDI *ui;
};

#endif // EXMDI_H
