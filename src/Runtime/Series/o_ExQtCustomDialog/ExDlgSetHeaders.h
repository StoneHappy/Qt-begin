#ifndef EXDLGSETHEADERS_H
#define EXDLGSETHEADERS_H

#include <QDialog>

namespace Ui {
class ExDlgSetHeaders;
}

class ExDlgSetHeaders : public QDialog
{
    Q_OBJECT

public:
    explicit ExDlgSetHeaders(QWidget *parent = nullptr);
    ~ExDlgSetHeaders();

private:
    Ui::ExDlgSetHeaders *ui;
};

#endif // EXDLGSETHEADERS_H
