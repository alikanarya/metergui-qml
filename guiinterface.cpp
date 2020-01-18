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

GuiInterfaceObject::GuiInterfaceObject(QObject *parent)
{

}

QString GuiInterfaceObject::getImagePath() const
{
    return imagePath;
}

double GuiInterfaceObject::getfilesInDirListSize() const
{
    return filesInDirListSize;
}

void GuiInterfaceObject::setImagePath(QString _inp)
{
    imagePath = _inp;
    emit imagePathChanged();
}

void GuiInterfaceObject::setfilesInDirListSize(int _inp)
{
    filesInDirListSize = _inp;
    emit filesInDirListSizeChanged();
}

void GuiInterfaceObject::setPath(QString _inp)
{
    folderPath = filePath = _inp;
    folderPath.replace("file:///","");
    //qDebug() << "filePath: " << filePath;
    //qDebug() << "folderPath" << folderPath;
    //fileOpenDir = QFileInfo(loadedFileNamewPath).absoluteDir();   // required for file open dialog
    fileOpenDir = QDir(folderPath);
    filesInDirList = fileOpenDir.entryList(fileFilters, QDir::Files);
    setfilesInDirListSize (filesInDirList.size());
    qDebug() << "filesInDirListSize: " << filesInDirListSize;
    /*
    if (filesInDirListSize != 0) sliderStep = 1.0 / filesInDirListSize;
    else sliderStep = 1.0;
    qDebug() << "sliderStep: " << sliderStep;
    */

    //foreach(QString temp, filesInDirList){ qDebug() << temp; }
    QString _imagePath = filePath + "/" + filesInDirList.at(0);
    //qDebug() << "imagePath: " << _imagePath;
    setImagePath(_imagePath);
}
