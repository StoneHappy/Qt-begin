#ifndef EXQCOMBOBOX_H
#define EXQCOMBOBOX_H

#include <QWidget>

namespace Ui {
class ExQcomboBox;
}

class ExQcomboBox : public QWidget
{
    Q_OBJECT

public:
    explicit ExQcomboBox(QWidget *parent = nullptr);
    ~ExQcomboBox();

private:
    Ui::ExQcomboBox *ui;
};

#endif // EXQCOMBOBOX_H