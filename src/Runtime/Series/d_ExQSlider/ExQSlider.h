#ifndef EXQSLIDER_H
#define EXQSLIDER_H

#include <QWidget>

namespace Ui {
class ExQSlider;
}

class ExQSlider : public QWidget
{
    Q_OBJECT

public:
    explicit ExQSlider(QWidget *parent = nullptr);
    ~ExQSlider();

private slots:
    void onSetClolor(int val);

private:
    Ui::ExQSlider *ui;
};

#endif // EXQSLIDER_H
