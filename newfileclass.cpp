#include "newfileclass.h"

newFileClass::newFileClass()
{

}

void newFileClass::setPath(QString files){
    tmpFiles = files;
}

QString newFileClass::getPath(){
    return tmpFiles;
}
