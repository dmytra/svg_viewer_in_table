
#include "mygraphicview.h"

MyGraphicView::MyGraphicView(QWidget *parent)
    : QGraphicsView(parent)
{

    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Disable scroll horizontally
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   // Disable scroll vertically
    this->setAlignment(Qt::AlignCenter);                        // Make the contents of binding to the center
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);    // Stretch the widget content

    this->setMinimumHeight(100);
    this->setMinimumWidth(100);

    scene = new QGraphicsScene();   // Initialize the scene to render
    this->setScene(scene);          // Set the scene in a widget

    group_1 = new QGraphicsItemGroup(); // Initialize the first group of elements
    group_2 = new QGraphicsItemGroup(); // Initialize the elements of the second group

    scene->addItem(group_1);            // Add the first group into the scene
    scene->addItem(group_2);            // Add the second group into the scene

    timer = new QTimer();               // Initialize Timer
    timer->setSingleShot(true);

    connect(timer, SIGNAL(timeout()), this, SLOT(slotAlarmTimer()));
    timer->start(50);
}

MyGraphicView::~MyGraphicView()
{

}

void MyGraphicView::slotAlarmTimer()
{
    /* We remove all items from the stage if they are facing a new rendering
     * */
    this->deleteItemsFromGroup(group_1);
    this->deleteItemsFromGroup(group_2);

    int width = this->width();
    int height = this->height();

    /* Set the stage size to size the widget.
     * The first coordinate - it is the top left corner,
     * and the second - is the lower right corner
     * */
    scene->setSceneRect(0,0,width,height);

    /* Getting started drawing random pictures
     * */
    QPen penBlack(Qt::black);
    QPen penRed(Qt::red);

    /* Draw a black rectangle
     * */
    group_1->addToGroup(scene->addLine(20,20, width - 20, 20, penBlack));
    group_1->addToGroup(scene->addLine(width - 20, 20, width - 20, height -20, penBlack));
    group_1->addToGroup(scene->addLine(width - 20, height -20, 20, height -20, penBlack));
    group_1->addToGroup(scene->addLine(20, height -20, 20, 20, penBlack));

    /* Draw a red rectangle
     * */
    int sideOfSquare = (height > width) ? (width - 60) : (height - 60);
    int centerOfWidget_X = width/2;
    int centerOfWidget_Y = height/2;

    group_2->addToGroup(scene->addLine(centerOfWidget_X - (sideOfSquare/2),
                                       centerOfWidget_Y - (sideOfSquare/2),
                                       centerOfWidget_X + (sideOfSquare/2),
                                       centerOfWidget_Y - (sideOfSquare/2),
                                       penRed));

    group_2->addToGroup(scene->addLine(centerOfWidget_X + (sideOfSquare/2),
                                       centerOfWidget_Y - (sideOfSquare/2),
                                       centerOfWidget_X + (sideOfSquare/2),
                                       centerOfWidget_Y + (sideOfSquare/2),
                                       penRed));

    group_2->addToGroup(scene->addLine(centerOfWidget_X + (sideOfSquare/2),
                                       centerOfWidget_Y + (sideOfSquare/2),
                                       centerOfWidget_X - (sideOfSquare/2),
                                       centerOfWidget_Y + (sideOfSquare/2),
                                       penRed));

    group_2->addToGroup(scene->addLine(centerOfWidget_X - (sideOfSquare/2),
                                       centerOfWidget_Y + (sideOfSquare/2),
                                       centerOfWidget_X - (sideOfSquare/2),
                                       centerOfWidget_Y - (sideOfSquare/2),
                                       penRed));
}

/* This method catches widget resize event
 * */
void MyGraphicView::resizeEvent(QResizeEvent *event)
{
    timer->start(50);   // As soon as we start the timer event has occurred to render
    QGraphicsView::resizeEvent(event);  //Run event the parent class
}


/* Method for removing all the elements from the group
 * */
void MyGraphicView::deleteItemsFromGroup(QGraphicsItemGroup *group)
{
    /* Loop through all the elements of the scene,
     * and if they belong to the group, passed into the method, then delete them
     * */
    foreach( QGraphicsItem *item, scene->items(group->boundingRect())) {
       if(item->group() == group ) {
          delete item;
       }
    }
}
