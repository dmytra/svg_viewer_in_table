#ifndef SVG_VIEWER_H
#define SVG_VIEWER_H

#include <QWidget>
#include <QList>
#include <QPushButton>
#include <QHBoxLayout>
#include <QHBoxLayout>
#include <QTableWidget>

class svg_viewer : public QWidget
{
    Q_OBJECT

public:
    svg_viewer(QWidget *parent = nullptr);
    ~svg_viewer();

    QString path;
    int sizeN;
    QString textsvg;
    QList<QString> rectList;
    QPushButton *clickBtn;
    QHBoxLayout *hbox;
    QTableWidget *table;


private slots:
    void on_loadButton_clicked();

};
#endif // SVG_VIEWER_H
