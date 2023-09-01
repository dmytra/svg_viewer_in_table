#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include "mygraphicview.h"
#include "newfileclass.h"

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QSvgGenerator>
#include <QFileDialog>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QString filePathMain, QWidget *parent = nullptr);
    ~MainWindow();

    int sizeN;
    QString textsvg;
    QList<QString> rectList;
    void setPath(QString);
    QString getPath();

private:
    Ui::MainWindow *ui;

    QString path;

    QGraphicsScene *scene;  // Графическая сцена

    QStandardItemModel *m_model;                        //модель данных
    QItemSelectionModel *m_seleModel;

    void on_load(QString filePathMain);
    void on_loadButton_clickedSVG();

private slots:
    void on_loadButton_clicked();

    void on_currentSelect(const QModelIndex &current, const QModelIndex &previous);
};
#endif // MAINWINDOW_H
