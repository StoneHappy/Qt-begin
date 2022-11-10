#ifndef EXQFILESYSTEMMODEL_H
#define EXQFILESYSTEMMODEL_H

#include <QMainWindow>

namespace Ui {
class ExQFileSystemModel;
}

class QLabel;
class QCheckBox;
class QFileSystemModel;

class ExQFileSystemModel : public QMainWindow
{
    Q_OBJECT

public:
    explicit ExQFileSystemModel(QWidget *parent = nullptr);
    ~ExQFileSystemModel();

private slots:
    void on_treeView_clicked(const QModelIndex& index);

private:
    void init();

private:
    Ui::ExQFileSystemModel *ui;

    QLabel* m_labFileName;       //文件名
    QLabel* m_labFileSize;       //文件大小
    QLabel* m_labFileType;       //文件类型
    QLabel* m_labPath;           //路径
    QCheckBox* m_chkBoxIsFile;   //当前是否为文件或文件夹
    QFileSystemModel* m_model;   //设置文件系统的模型
};

#endif // EXQFILESYSTEMMODEL_H
