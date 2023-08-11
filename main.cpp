#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    QTranslator translator;
//    const QStringList uiLanguages = QLocale::system().uiLanguages();
//    for (const QString &locale : uiLanguages) {
//        const QString baseName = "svg_viewer_in_table_v3_" + QLocale(locale).name();
//        if (translator.load(":/i18n/" + baseName)) {
//            a.installTranslator(&translator);
//            break;
//        }
//    }

//    QString filePathMain;

//    if (argc == 1)
//        filePathMain = QLatin1String(":/two_block.svg");
//    else if (argc == 2)
//        filePathMain = argv[1];
//    else {
//        qDebug() << QLatin1String("Please specify an svg file!");
//        return -1;
//    }

//    newFileClass newFilesMain;
//    newFilesMain.setPath(filePathMain);

    MainWindow w;

    w.show();
    w.resize(1000,800);
    return a.exec();
}
