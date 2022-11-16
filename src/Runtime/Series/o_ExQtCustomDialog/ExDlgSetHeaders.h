#ifndef EXDLGSETHEADERS_H
#define EXDLGSETHEADERS_H

#include <QDialog>

class QStringListModel;

namespace Ui {
class ExDlgSetHeaders;
}

class ExDlgSetHeaders : public QDialog
{
    Q_OBJECT

public:
    explicit ExDlgSetHeaders(QWidget *parent = nullptr);
    ~ExDlgSetHeaders();

    void setHeaderList(QStringList& headers);
    QStringList headerList();

private:
    Ui::ExDlgSetHeaders *ui;

    QStringListModel* m_model;
};

#endif // EXDLGSETHEADERS_H
