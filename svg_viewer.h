#ifndef SVG_VIEWER_H
#define SVG_VIEWER_H

#include <QWidget>
#include <QList>

class svg_viewer : public QWidget
{
    Q_OBJECT

public:
    svg_viewer(QWidget *parent = nullptr);
    ~svg_viewer();

private:
    QString path;
    QString textsvg;
    QList<QString> rectList;

private:
     void on_loadButton_clicked();

};
#endif // SVG_VIEWER_H
