#include <QHBoxLayout>
#include <QTableWidget>
#include "svg_viewer.h"
#include <QFileDialog>
#include <QDomDocument>
#include <QDebug>


svg_viewer::svg_viewer(QWidget *parent)
    : QWidget(parent)
{
    on_loadButton_clicked();

    QHBoxLayout *hbox = new QHBoxLayout(this);

    QTableWidget *table = new QTableWidget(111, 2, this);

    hbox->addWidget(table);

//       foreach (QList *item, rectList) {
//            QList *rect = item;
            //scene->addItem(rect);


    table->setHorizontalHeaderLabels({"Name", "Age"});

//    QTableWidgetItem *item1 = new QTableWidgetItem("John");
//    QTableWidgetItem *item2 = new QTableWidgetItem("30");
//    table->setItem(0, 0, item1);
//    table->setItem(0, 1, item2);

        int i=0;
    foreach( QString item, rectList )
    {

                QTableWidgetItem *item1 = new QTableWidgetItem(QString::number(i));
                QTableWidgetItem *item2 = new QTableWidgetItem(item);

            table->setItem(i, 0, item1);
                  table->setItem(i, 1, item2);
            i++;

        qDebug() << item;
        // will items always be processed in numerical order by index?
        // do something with "item";
    }

}

svg_viewer::~svg_viewer()
{
}


void svg_viewer::on_loadButton_clicked()
{
    QString newPath = QFileDialog::getOpenFileName(this,  "Open SVG",
                                                   path, "SVG files (*.svg)");
    if (newPath.isEmpty())
        return;

    //QList<QString> rectList;

    path = newPath;
    QDomDocument doc;


    QFile file(path);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    while (!file.atEnd()) {
            QString line = file.readLine();
    rectList << line;
    }


    file.close();

 //   foreach (QGraphicsRectItem *item, rectList) {
//        QGraphicsRectItem *rect = item;
//        scene->addItem(rect);

}

