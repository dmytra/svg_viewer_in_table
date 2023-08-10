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

    m_model = new QStandardItemModel(11111, 1, this);                    //Создать модель данных
    m_seleModel = new QItemSelectionModel(m_model);                      //Модель выбора предметов

    connect(m_seleModel, SIGNAL(currentChanged(QModelIndex,QModelIndex)), this,SLOT(on_currentSelect(QModelIndex,QModelIndex)));

    QPushButton* pushButton = new QPushButton("open SVG file：",this);

    ui->toolBar->addWidget(pushButton);
    ui->tableView->setModel(m_model);
    ui->tableView->setSelectionModel(m_seleModel);
    ui->tableView->setColumnWidth(0, 950);

    connect(pushButton, SIGNAL(clicked()), this, SLOT(on_loadButton_clicked() ) );


    /* Initialize a widget with graphics */
    myPicture   = new MyGraphicView();
    /* and add it to a layer */
    ui->gridLayout->addWidget(myPicture);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_currentSelect(const QModelIndex &current, const QModelIndex &previous) {
        if (current.isValid()) { //状态栏的显示
            QStandardItem* item;

            //QModelIndex index = m_model->index(current);

            item = m_model->itemFromIndex(current);
            ui->textEdit->setText(item->text());
            qDebug() << item->text();



        }
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

        int i=0;
        foreach( QString item, rectList )
        {
            QModelIndex index = m_model->index(i, 0);
            m_seleModel->clearSelection();
            m_seleModel->setCurrentIndex(index, QItemSelectionModel::Select);
            m_model->setData(index, item, Qt::DisplayRole);                    //установить строку ячейки

            i++;
        }
    }
    file.close();
}