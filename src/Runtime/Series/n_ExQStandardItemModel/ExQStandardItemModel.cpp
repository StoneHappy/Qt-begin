#include "ExQStandardItemModel.h"
#include "ui_ExQStandardItemModel.h"
#include <QToolButton>
#include <QStandardItemModel>
#include <QFileDialog>
#include <QTextStream>
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
   
}

ExQStandardItemModel::~ExQStandardItemModel()
{
    delete ui;
}
