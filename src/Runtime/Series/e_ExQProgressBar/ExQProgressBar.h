#ifndef EXQPROGRESSBAR_H
#define EXQPROGRESSBAR_H

#include <QWidget>
#include <qobjectdefs.h>

namespace Ui {
class ExQProgressBar;
}

class ExQProgressBar : public QWidget
{
    Q_OBJECT

public:
    explicit ExQProgressBar(QWidget *parent = nullptr);
    ~ExQProgressBar();

private slots:
    void onValChange(int val);

private:
    Ui::ExQProgressBar *ui;
};

#endif // EXQPROGRESSBAR_H
