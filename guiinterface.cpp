#include "guiinterface.h"
#include <QDebug>

guiInterface::guiInterface(QObject *parent) : QObject(parent)
{

}

void guiInterface::test()
{
    qDebug() << "Hello C++";
}

void guiInterface::test(QString _inp)
{
    guiString = _inp;
    loadedFileNamewPath = guiString.replace("file:///","");
    //qDebug() << loadedFileNamewPath;
    //fileOpenDir = QFileInfo(loadedFileNamewPath).absoluteDir();
    fileOpenDir = QDir(loadedFileNamewPath);
    filesInDirList = fileOpenDir.entryList(fileFilters, QDir::Files);

    foreach(QString temp, filesInDirList){ qDebug() << temp; }

}
