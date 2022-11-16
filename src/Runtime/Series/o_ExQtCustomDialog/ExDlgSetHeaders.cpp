#include "ExDlgSetHeaders.h"
#include "ui_ExDlgSetHeaders.h"

#include <QStringListModel>
#include <QMessageBox>
ExDlgSetHeaders::ExDlgSetHeaders(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExDlgSetHeaders)
{
    ui->setupUi(this);
    m_model = new QStringListModel(this);
    ui->listView->setModel(m_model);
}

ExDlgSetHeaders::~ExDlgSetHeaders()
{
    QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("设置表头消息框被删除"));
    delete ui;
}

void ExDlgSetHeaders::setHeaderList(QStringList& headers)
{
    m_model->setStringList(headers);
}

QStringList ExDlgSetHeaders::headerList()
{
    return m_model->stringList();
}
