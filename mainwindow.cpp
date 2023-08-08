#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QDomDocument>
#include <QDebug>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(QObject::tr("Просмотр SVG"));

    m_model = nullptr;

    //    hbox = new QHBoxLayout(this);
    //    clickBtn = new QPushButton("Open SVG file", this);
    //    hbox->addWidget(clickBtn, 0, Qt::AlignLeft | Qt::AlignTop);

    m_model = new QStandardItemModel(111, 1, this);                       //Создать модель данных
    m_seleModel = new QItemSelectionModel(m_model);                      //Модель выбора предметов
    //connect(m_seleModel, SIGNAL(currentChanged(QModelIndex,QModelIndex)), this,SLOT(on_currentChanged(QModelIndex,QModelIndex)));

    QPushButton* pushButton = new QPushButton("open SVG file：",this);

    ui->toolBar->addWidget(pushButton);
    ui->tableView->setModel(m_model);
    ui->tableView->setSelectionModel(m_seleModel);
    ui->tableView->setColumnWidth(0, 950);

    connect(pushButton, SIGNAL(clicked()), this, SLOT(on_loadButton_clicked() ) );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loadButton_clicked()
{
    QString newPath = QFileDialog::getOpenFileName(this,  "Open SVG",
                                                   path, "SVG files (*.svg)");
    if (newPath.isEmpty())
        return;

    path = newPath;

    QDomDocument doc;

    QFile file(path);
    if (file.open(QIODevice::ReadOnly) | doc.setContent(&file))
    {
        QDomNodeList gList = doc.elementsByTagName("g");

        sizeN = gList.size();
        for (int i = 0; i < gList.size(); i++) {

            QDomNode gNode = gList.item(i);

            QString line;
            QTextStream stream(&line);
            gNode.save(stream, 0);

            qDebug() << line;
            rectList << line;
        }

        //        table = new QTableWidget(sizeN, 2, this);
        //        hbox->addWidget(table);

        //        table->setHorizontalHeaderLabels({"Name", "Age"});

        int i=0;
        foreach( QString item, rectList )
        {
//            QTableWidgetItem *item1 = new QTableWidgetItem(QString::number(i));
//            QTableWidgetItem *item2 = new QTableWidgetItem(item);

//            table->setItem(i, 0, item1);
//            table->setItem(i, 1, item2);


            QModelIndex index = m_model->index(i, 0);

//            m_model->appendColumn();

//            QStandardItemModel model;
//            QStandardItem *parentItem = model.invisibleRootItem();
//            for (int i = 0; i < 4; ++i) {
//                QStandardItem *item = new QStandardItem(QString("item %0").arg(i));
//                parentItem->appendRow(item);
//                parentItem = item;
//            }


            m_seleModel->clearSelection();
            m_seleModel->setCurrentIndex(index, QItemSelectionModel::Select);
            m_model->setData(index, item, Qt::DisplayRole);                    //установить строку ячейки

            i++;

            qDebug() << item;
        }

//        //Перейдите к ячейке и установите строку
//        void ExCustomMainWin::setACellText(int row, int col, QString text)
//        {
//            QModelIndex index = m_model->index(row, col);
//            m_seleModel->clearSelection();
//            m_seleModel->setCurrentIndex(index, QItemSelectionModel::Select);
//            m_model->setData(index, text, Qt::DisplayRole);                    //установить строку ячейки
//        }

    }
    file.close();
}
