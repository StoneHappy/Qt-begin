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

private slots:
    void on_btnSetText_clicked();
    void on_btnClose_clicked();

private:
    Ui::ExDlgLocate *ui;

protected:
    virtual void closeEvent(QCloseEvent* event) override;
    virtual void showEvent(QShowEvent* evnet) override;
};

#endif // EXDLGLOCATE_H
