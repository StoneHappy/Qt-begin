#ifndef EXWIDGET_H
#define EXWIDGET_H

#include <QWidget>

namespace Ui {
class ExWidget;
}

class ExWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ExWidget(QWidget *parent = nullptr);
    ~ExWidget();

private:
    Ui::ExWidget *ui;
};

#endif // EXWIDGET_H
