#include "guiinterface.h"
#include <QDebug>

guiInterfaceFns::guiInterfaceFns(QObject *parent) : QObject(parent)
{

}

void guiInterfaceFns::test()
{
    qDebug() << "Hello C++";
}

void guiInterfaceFns::setPath(QString _inp)
{
    folderPath = filePath = _inp;
    folderPath.replace("file:///","");
    qDebug() << "filePath: " << filePath;
    qDebug() << "folderPath" << folderPath;
    //fileOpenDir = QFileInfo(loadedFileNamewPath).absoluteDir();   // required for file open dialog
    fileOpenDir = QDir(folderPath);
    filesInDirList = fileOpenDir.entryList(fileFilters, QDir::Files);

    //foreach(QString temp, filesInDirList){ qDebug() << temp; }
    imagePath = filePath + "/" + filesInDirList.at(0);
    qDebug() << "imagePath" << imagePath;

}

void guiInterfaceObject::setPath(QString _inp)
{
    folderPath = filePath = _inp;
    folderPath.replace("file:///","");
    qDebug() << "filePath: " << filePath;
    qDebug() << "folderPath" << folderPath;
    //fileOpenDir = QFileInfo(loadedFileNamewPath).absoluteDir();   // required for file open dialog
    fileOpenDir = QDir(folderPath);
    filesInDirList = fileOpenDir.entryList(fileFilters, QDir::Files);

    //foreach(QString temp, filesInDirList){ qDebug() << temp; }
    imagePath = filePath + "/" + filesInDirList.at(0);
    qDebug() << "imagePath" << imagePath;

}
