#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include "mygraphicview.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString path;
    int sizeN;
    QString textsvg;
    QList<QString> rectList;

private:
    Ui::MainWindow *ui;

    MyGraphicView   *myPicture;

    QStandardItemModel *m_model;                        //модель данных
    QItemSelectionModel *m_seleModel;

private slots:
    void on_loadButton_clicked();
    void on_currentSelect(const QModelIndex &current, const QModelIndex &previous);
};
#endif // MAINWINDOW_H
