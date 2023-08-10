#ifndef MYGRAPHICVIEW_H
#define MYGRAPHICVIEW_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QTimer>


// Extend the class QGraphicsView
class MyGraphicView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MyGraphicView(QWidget *parent = 0);
    ~MyGraphicView();

signals:

private slots:
    void slotAlarmTimer();  /* slot timer overflow handler there will be repainting the widget
                             * */

private:
    QGraphicsScene      *scene;
    QGraphicsItemGroup  *group_1;
    QGraphicsItemGroup  *group_2;

    /* Timer for delayed rendering.
     * The fact is that when you create a window and the widget
     * needs some time to parent layer turned to take
     * from him adequate width and height settings
     * */
    QTimer              *timer;

private:
    void resizeEvent(QResizeEvent *event);
    void deleteItemsFromGroup(QGraphicsItemGroup *group_1);
};

#endif // MYGRAPHICVIEW_H
