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

    QString newPath = QFileDialog::getOpenFileName(this,  "Open SVG",
                                                   path, "SVG files (*.svg)");
    if (newPath.isEmpty())
        return;

    path = newPath;
    QDomDocument doc;

    //    QDomDocument d;
    //    QString someXML;
    //    d.setContent(someXML);
    //    QDomNode n = d.firstChild();
    //    while (!n.isNull()) {
    //        if (n.isElement()) {
    //            QDomElement e = n.toElement();
    //            cout << "Element name: " << qPrintable(e.tagName()) << '\n';
    //            break;
    //        }
    //        n = n.nextSibling();
    //    }

    QFile file(path);
    //if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    if (file.open(QIODevice::ReadOnly) | doc.setContent(&file))
    {
        // Ищем в документе все объекты с тегом g
        QDomNodeList gList = doc.elementsByTagName("g");
        // Начинаем их перебирать

        sizeN = gList.size();
        for (int i = 0; i < gList.size(); i++) {

            //QDomText text = gList.at(i).toText();

            QDomNode gNode = gList.item(i);     // Выделяем из списка ноду

            QString line;
            QTextStream stream(&line);
            gNode.save(stream, 0);

            qDebug() << line;
            rectList << line;
        }
    }

    QHBoxLayout *hbox = new QHBoxLayout(this);

    QTableWidget *table = new QTableWidget(sizeN, 2, this);

        file.close();

    hbox->addWidget(table);

//       foreach (QList *item, rectList) {
//            QList *rect = item;
            //scene->addItem(rect);


    table->setHorizontalHeaderLabels({"Name", "Age"});


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


}
