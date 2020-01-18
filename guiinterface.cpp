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

int GuiInterfaceObject::getfileIndex() const
{
    return fileIndex;
}

bool GuiInterfaceObject::getsliderFocus() const
{
    return sliderFocus;
}

void GuiInterfaceObject::setIndex(double value)
{
    fileIndex = (int) value;
    qDebug() << "fileIndex: " << fileIndex;
    setImagePath(filePath + "/" + filesInDirList.at((int) fileIndex));

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

void GuiInterfaceObject::setfileIndex(int _inp)
{
    fileIndex = _inp;
    emit fileIndexChanged();
}

void GuiInterfaceObject::setsliderFocus(bool _inp)
{
    sliderFocus = _inp;
    emit sliderFocusChanged();
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
    setfileIndex(0);

    //foreach(QString temp, filesInDirList){ qDebug() << temp; }
    QString _imagePath = filePath + "/" + filesInDirList.at(fileIndex);
    //qDebug() << "imagePath: " << _imagePath;
    setImagePath(_imagePath);
    setsliderFocus(true);
}
