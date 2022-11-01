#ifndef EXQSTRING_H
#define EXQSTRING_H

#include <QWidget>

namespace Ui {
class ExQString;
}

class ExQString : public QWidget
{
    Q_OBJECT

public:
    explicit ExQString(QWidget *parent = nullptr);
    ~ExQString();

private:
    Ui::ExQString *ui;
};

#endif // EXQSTRING_H
