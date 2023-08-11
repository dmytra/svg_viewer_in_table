#ifndef NEWFILECLASS_H
#define NEWFILECLASS_H

#include <QMainWindow>

class newFileClass
{
public:
    newFileClass();

    QString tmpFiles;

    void setPath(QString);
    QString getPath();
};

#endif // NEWFILECLASS_H
