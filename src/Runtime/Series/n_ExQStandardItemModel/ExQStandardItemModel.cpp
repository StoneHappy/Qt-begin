#include "ExQStandardItemModel.h"
#include "ui_ExQStandardItemModel.h"
#include <QToolButton>
#include <QStandardItemModel>
#include <QFileDialog>
#include <QTextStream>
#include "ExDelegate.h"
#define COLUMN 6  //���ݱ������

ExQStandardItemModel::ExQStandardItemModel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ExQStandardItemModel)
{
    ui->setupUi(this);
    setWindowTitle(QString::fromLocal8Bit("QTableView��QStandardItemModel���÷�"));

    ui->toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);     //��������������ͼ����ʽ���

    m_labCurrFile = new QLabel(QString::fromLocal8Bit("��ǰ�ļ���"), this);                       //����״̬��
    m_labCellPos = new QLabel(QString::fromLocal8Bit("��ǰ��Ԫ��"), this);
    m_labCellText = new QLabel(QString::fromLocal8Bit("��Ԫ�����ݣ�"), this);
    m_labCurrFile->setMinimumWidth(200);
    m_labCellPos->setMinimumWidth(200);
    m_labCellText->setMinimumWidth(200);
    ui->statusbar->addWidget(m_labCurrFile);
    ui->statusbar->addWidget(m_labCellPos);
    ui->statusbar->addWidget(m_labCellText);

    m_model = new QStandardItemModel(2, COLUMN, this);                          //��������ģ�ͣ�һ��ʼ����ΪĬ�ϵ�2��6�б��һ����    m_selectModet = new QItemSelectionModel(m_model, this);                //����ѡ��ģ��
    m_selectModet = new QItemSelectionModel(m_model, this);                //����ѡ��ģ��
    ui->tableView->setModel(m_model);                                      //��������ģ��
    ui->tableView->setSelectionModel(m_selectModet);                       //����ѡ��ģ��
    ui->tableView->setSelectionMode(QAbstractItemView::ExtendedSelection); //����ѡ��ģʽ
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectItems);   //����ѡ����Ϊ
    connect(m_selectModet, SIGNAL(currentChanged(QModelIndex, QModelIndex)), this, SLOT(onCurrentChanged(QModelIndex, QModelIndex)));  //ѡ��ǰ��Ԫ��仯ʱ���ź����
}

void ExQStandardItemModel::onCurrentChanged(const QModelIndex& current, const QModelIndex& previous)
{
    if (current.isValid()) {                                               //��ǰģ��������Ч
        m_labCellPos->setText(QString::fromLocal8Bit("��ǰ��Ԫ��%1��, %2��").arg(current.row()).arg(current.column()));
        QStandardItem* item = m_model->itemFromIndex(current);             //��ģ���������Item
        m_labCellText->setText(QString::fromLocal8Bit("��ǰ�ļ���%1").arg(item->text()));  //��ʾitem����������

        QFont font = item->font();
        ui->actBold->setChecked(font.bold());                              //����actFontBold��check״̬
    }
}

//action+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//�򿪺͵����ļ���������plainTextEdit������ʾ
void ExQStandardItemModel::on_actOpen_triggered()
{
    QString currPath = QCoreApplication::applicationDirPath();
    QString fileName = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("��һ���ļ�"), currPath, QString::fromLocal8Bit("���������ļ�(*txt);;�����ļ�(*.*)"));

    if (fileName.isEmpty())
        return;

    QStringList list;
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {                //ֻ����ʽ���ı��ļ�
        QTextStream stream(&file);                                         //���ı�����ȡ�ļ�
        ui->plainTextEdit->clear();

        while (!stream.atEnd()) {                                          //��ȡ�ı����ı�������
            QString str = stream.readLine();
            ui->plainTextEdit->appendPlainText(str);
            list.append(str);
        }

        file.close();                                                      //�ر�
        m_labCurrFile->setText("��ǰ�ļ���" + fileName);                    //����״̬��

        ui->actAppend->setEnabled(true);                                   //����action��Enabled������
        ui->actInsert->setEnabled(true);
        ui->actDelete->setEnabled(true);
        ui->actSave->setEnabled(true);
    }

    init(list);                                                            //��ʼ��.txt������
}

//��list��ʼ������ģ��QTableView����
void ExQStandardItemModel::init(QStringList& list)
{
    int rowCount = list.count();                                           //�ı���������һ��Ϊ��ͷ
    m_model->setRowCount(rowCount - 1);

    QString header = list.at(0);
    QStringList headerList = header.split(QRegExp("\\s+"), QString::SkipEmptyParts); //ͨ��һ�����߶���ո����tab�����и�
    m_model->setHorizontalHeaderLabels(headerList);                       //���ñ�ͷ

    QStandardItem* item = nullptr;                                        //�˴���ʼ�����ñ������
    QStringList tempList;
    int j = 0;

    for (int i = 1; i < rowCount; i++) {
        QString aLineText = list.at(i);
        tempList = aLineText.split(QRegExp("\\s+"), QString::SkipEmptyParts);//������ʽ��\sƥ���κοհ��ַ��������ո��Ʊ������ҳ���ȵ�, �ȼ���[ \f\n\r\t\v]

        for (j = 0; j < COLUMN - 1; j++) {                                     //����ǰ5�е�item

            if (j == 3) {
                ExDelegate* itemDelegate = new ExDelegate();
                ui->tableView->setItemDelegateForColumn(3, itemDelegate);
            }

            item = new QStandardItem(tempList.at(j));
            m_model->setItem(i - 1, j, item);
        }



        item = new QStandardItem(tempList.at(j));                          //���һ�е�item
        item->setCheckable(true);                                          //�����м���

        if (tempList.at(j) == "https://www.google.com")
            item->setCheckState(Qt::Unchecked);
        else
            item->setCheckState(Qt::Checked);

        m_model->setItem(i - 1, COLUMN - 1, item);
    }
}

ExQStandardItemModel::~ExQStandardItemModel()
{
    delete ui;
}
