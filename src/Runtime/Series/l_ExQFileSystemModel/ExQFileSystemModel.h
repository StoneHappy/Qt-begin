#ifndef EXQFILESYSTEMMODEL_H
#define EXQFILESYSTEMMODEL_H

#include <QMainWindow>

namespace Ui {
class ExQFileSystemModel;
}

class ExQFileSystemModel : public QMainWindow
{
    Q_OBJECT

public:
    explicit ExQFileSystemModel(QWidget *parent = nullptr);
    ~ExQFileSystemModel();

private:
    Ui::ExQFileSystemModel *ui;
};

#endif // EXQFILESYSTEMMODEL_H
