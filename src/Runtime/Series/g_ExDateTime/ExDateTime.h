#ifndef EXDATETIME_H
#define EXDATETIME_H

#include <QWidget>
#include <qobjectdefs.h>

namespace Ui {
class ExDateTime;
}

class ExDateTime : public QWidget
{
    Q_OBJECT

public:
    explicit ExDateTime(QWidget *parent = nullptr);
    ~ExDateTime();

private slots:
    void on_btnGetDateTime_clicked();

private:
    Ui::ExDateTime *ui;
};

#endif // EXDATETIME_H
