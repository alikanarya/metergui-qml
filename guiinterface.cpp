#include "guiinterface.h"
#include <QDebug>

extern QString webSvrFile;

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

QString GuiInterfaceObject::getFileName() const
{
    return fileName;
}

QString GuiInterfaceObject::get_lbl_dbConn() const
{
    return lbl_dbConn;
}

QString GuiInterfaceObject::get_lbl_weberverConn() const
{
    return lbl_webserverConn;
}

bool GuiInterfaceObject::getbusyIndicatorState() const
{
    return busyIndicatorState;
}

QString GuiInterfaceObject::get_result() const
{
    return result;
}

bool GuiInterfaceObject::get_resultFixed() const
{
    return resultFixed;
}

void GuiInterfaceObject::setIndex(double value)
{
    fileIndex = (int) value;
    //qDebug() << "fileIndex: " << fileIndex;
    setFileName(filesInDirList.at((int) fileIndex));
    setImagePath(filePath + "/" + fileName);
}

void GuiInterfaceObject::queryImage()
{
    /*
    setbusyIndicatorState(true);
    netX->makeRequest(6);
    setsliderFocus(true);
    */
    queryFolderInit();
}

void GuiInterfaceObject::setResult(QString _inp)
{
    result = _inp;
    dbThreadX->date = date;
    dbThreadX->time = time;
    dbThreadX->result = result.toFloat();
    dbThreadX->resultFixed = get_resultFixed();
    dbThreadX->cmdInsert = true;
    dbThreadX->start();
    setsliderFocus(true);
    //qDebug() << result;
}

void GuiInterfaceObject::queryFolderInit()
{
    setbusyIndicatorState(true);
    analysisList.clear();
    queryFolderActive = true;
    queryFolderIndex = 0;
    queryFolder();
}

void GuiInterfaceObject::queryFolder()
{
    if (queryFolderIndex<filesInDirListSize) {
        QString _fileName, _imagePath;
        data = new imageData();
        _fileName = filesInDirList.at(queryFolderIndex);
        data->date = _fileName.mid(6,2) + "/" + _fileName.mid(4,2) + "/" + _fileName.mid(2,2);
        data->time = _fileName.mid(9,2) + ":" + _fileName.mid(11,2) + ":" + _fileName.mid(13,2);
        analysisList.append(data);
        _imagePath = folderPath + "/" + _fileName;
        if (QFile::exists(webSvrFile)) {
            QFile::remove(webSvrFile);
        }
        if (!QFile::copy(_imagePath, webSvrFile)) {
            qDebug() << "file copy error";
        } else {
            netX->makeRequest(6);
        }
    }
}

void GuiInterfaceObject::connectedToDB()
{
    set_lbl_dbConn(MSG_DB_CON_YES);
}

void GuiInterfaceObject::unconnectedToDB()
{
    set_lbl_dbConn(MSG_DB_CON_NO);
}

void GuiInterfaceObject::connectedToWebSvr()
{
    set_lbl_webwerverConn(MSG_WEBSVR_CON_YES);
}

void GuiInterfaceObject::unconnectedToWebSvr()
{
    set_lbl_webwerverConn(MSG_WEBSVR_CON_NO);
}

void GuiInterfaceObject::dockerReplyBad()
{
    if (queryFolderActive) {
        analysisList.at(queryFolderIndex)->result = "-";
        qDebug() << analysisList.at(queryFolderIndex)->date << " " << analysisList.at(queryFolderIndex)->time << " " << analysisList.at(queryFolderIndex)->result;
        queryFolderIndex++;
        if (queryFolderIndex < filesInDirListSize) {
            queryFolder();
        } else {
            setbusyIndicatorState(false);
        }
    } else {
        setbusyIndicatorState(false);
    }
}

void GuiInterfaceObject::dockerReplyGood(QString _inp)
{
    result = _inp;
    if (queryFolderActive) {
        analysisList.at(queryFolderIndex)->result = result;
        qDebug() << analysisList.at(queryFolderIndex)->date << " " << analysisList.at(queryFolderIndex)->time << " " << analysisList.at(queryFolderIndex)->result;
        queryFolderIndex++;
        if (queryFolderIndex < filesInDirListSize) {
            queryFolder();
        } else {
            setbusyIndicatorState(false);
        }
    } else {
        emit resultChanged();
        setbusyIndicatorState(false);
    }
}

void GuiInterfaceObject::setImagePath(QString _inp)
{
    imagePath = _inp;
    emit imagePathChanged();
    QString _imagePath = folderPath + "/" + fileName;
    //qDebug() << "_imagePath: " << _imagePath;   //eg: "D:/Engineering/Repository Data/meter/ngmeter-data/2020-01/13/20200113_073001.jpeg"

    if (QFile::exists(webSvrFile)) {
        QFile::remove(webSvrFile);
    }
    if (!QFile::copy(_imagePath, webSvrFile))
        qDebug() << "file copy error";
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

void GuiInterfaceObject::setFileName(QString _inp)
{
    fileName = _inp;
    year = fileName.mid(2,2);
    month = fileName.mid(4,2);
    day = fileName.mid(6,2);
    date = day + "/" + month + "/" + year;
    hour = fileName.mid(9,2);
    min = fileName.mid(11,2);
    sec = fileName.mid(13,2);
    time = hour + ":" + min + ":" + sec;

    qDebug() << date << " " << time;
    emit fileNameChanged();
}

void GuiInterfaceObject::set_lbl_dbConn(QString _inp)
{
    lbl_dbConn = _inp;
    emit lbl_dbConnChanged();
}

void GuiInterfaceObject::set_lbl_webwerverConn(QString _inp)
{
    lbl_webserverConn = _inp;
    emit lbl_webserverConnChanged();
}

void GuiInterfaceObject::setbusyIndicatorState(bool _inp)
{
    busyIndicatorState = _inp;
    emit busyIndicatorStateChanged();
}

void GuiInterfaceObject::set_result(QString _inp)
{
    result = _inp;
    emit resultChanged();
}

void GuiInterfaceObject::set_resultFixed(bool _inp)
{
    resultFixed = _inp;
    emit resultFixedChanged();
}

void GuiInterfaceObject::setPath(QString _inp)
{
    folderPath = filePath = _inp;
    folderPath.replace("file:///","");
    //qDebug() << "filePath: " << filePath;   //eg: "file:///D:/Engineering/Repository Data/meter/ngmeter-data/2020-01/12"
    //qDebug() << "folderPath" << folderPath; //eg: "D:/Engineering/Repository Data/meter/ngmeter-data/2020-01/12"
    //fileOpenDir = QFileInfo(loadedFileNamewPath).absoluteDir();   // required for file open dialog
    fileOpenDir = QDir(folderPath);
    filesInDirList = fileOpenDir.entryList(fileFilters, QDir::Files);
    setfilesInDirListSize (filesInDirList.size());
    //qDebug() << "filesInDirListSize: " << filesInDirListSize;
    setfileIndex(0);

    //foreach(QString temp, filesInDirList){ qDebug() << temp; }
    setFileName(filesInDirList.at(fileIndex));
    QString _imagePath = filePath + "/" + fileName;
    //qDebug() << "imagePath: " << _imagePath;    //eg: "file:///D:/Engineering/Repository Data/meter/ngmeter-data/2020-01/12/20200112_012516.jpeg"
    setImagePath(_imagePath);
    setsliderFocus(true);
}
