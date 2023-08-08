#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QStandardItemModel>
#include <QItemSelectionModel>

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

    QStandardItemModel *m_model;                        //модель данных
    QItemSelectionModel *m_seleModel;

private slots:
    void on_loadButton_clicked();

};
#endif // MAINWINDOW_H
