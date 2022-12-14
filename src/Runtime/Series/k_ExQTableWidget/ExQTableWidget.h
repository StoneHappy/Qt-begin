#ifndef EXQTABLEWIDGET_H
#define EXQTABLEWIDGET_H

#include <QMainWindow>
#include <qdatetime.h>
#include <qlabel.h>
namespace Ui {
class ExQTableWidget;
}

class QLabel;
class QDate;
class ExQTableWidget : public QMainWindow
{
    Q_OBJECT
private:
    enum cellType {                                       //自定义表格单元格TYPE的类型,创建item时使用
        ctName,                                           //姓名
        ctSex,                                            //性别
        ctBirth,                                          //出生日期
        ctNation,                                         //籍贯
        ctScore,                                          //分数
        ctLikeAnime                                       //是否喜欢二次元
    };
    enum fieldColNum {                                    //自定义各个表段在表格中的列号
        colName,
        colSex,
        colBirth,
        colNation,
        colScore,
        colLikeAnime
    };
public:
    explicit ExQTableWidget(QWidget *parent = nullptr);
    ~ExQTableWidget();

private slots:
    void on_btnSetHeader_clicked();
    void on_btnInitTable_clicked();
    void on_btnSetRow_clicked();
    void on_btnInsertRow_clicked();
    void on_btnAddRow_clicked();
    void on_btnDelRow_clicked();
    void on_btnAutoHeight_clicked();
    void on_btnAutoWidth_clicked();
    void on_btnReadToEdit_clicked();
    void on_chkBoxHeadEdit_clicked(bool checked);        //表格可编辑模式
    void on_chkBoxRowColor_clicked(bool checked);        //间隔行底色
    void on_chkBoxHeadRow_clicked(bool checked);         //显示行表头
    void on_chkBoxHeadCol_clicked(bool checked);         //显示列表头
    void on_radioBtnSelectItem_clicked();                //单元格选择
    void on_radioBtnSelectRow_clicked();                 //行选择
    void on_tableWidget_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn);

private:
    void createItemsARow(int row, QString name, QString sex, QDate birth, QString nation, int score, bool isAnime);

private:
    Ui::ExQTableWidget *ui;
    QLabel *m_labCellIndex;                              //状态栏上用来显示单元格的行号、列号
    QLabel *m_labCellType;                               //状态栏上用来显示单元格的type
    QLabel *m_labStudID;                                 //状态栏上用来显示单元格的学号
};

#endif // EXQTABLEWIDGET_H
