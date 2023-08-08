#include "svg_viewer.h"
#include <QFileDialog>
#include <QDomDocument>
#include <QDebug>

svg_viewer::svg_viewer(QWidget *parent)
    : QWidget(parent)
{
    hbox = new QHBoxLayout(this);

    clickBtn = new QPushButton("Open", this);
    hbox->addWidget(clickBtn, 0, Qt::AlignLeft | Qt::AlignTop);

    connect(clickBtn, SIGNAL(clicked()), this, SLOT(on_loadButton_clicked() ) );


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

        table = new QTableWidget(sizeN, 2, this);
        hbox->addWidget(table);

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
        }

    }
    file.close();
}
