#ifndef GUIINTERFACE_H
#define GUIINTERFACE_H

#include <QObject>
#include <QDir>
#include "netops.h"

extern netOps *netX;

class guiInterfaceFns : public QObject
{
    Q_OBJECT

public:
    QString filePath = "";
    QString imagePath = "";
    QString folderPath = "";
    QDir fileOpenDir;
    QStringList filesInDirList;
    QStringList fileFilters  = (QStringList() << "*.jpeg" << "*.jpg" << "*.png");
    int filesInDirListIndex = 0;

    explicit guiInterfaceFns(QObject *parent = nullptr);
    Q_INVOKABLE void test();
    Q_INVOKABLE void setPath(QString _inp);

signals:

public slots:
};


class GuiInterfaceObject : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString imagePath READ getImagePath WRITE setImagePath NOTIFY imagePathChanged)
    Q_PROPERTY(double filesInDirListSize READ getfilesInDirListSize WRITE setfilesInDirListSize NOTIFY filesInDirListSizeChanged)
    Q_PROPERTY(int fileIndex READ getfileIndex WRITE setfileIndex NOTIFY fileIndexChanged)
    Q_PROPERTY(bool sliderFocus READ getsliderFocus WRITE setsliderFocus NOTIFY sliderFocusChanged)
    Q_PROPERTY(QString fileName READ getFileName WRITE setFileName NOTIFY fileNameChanged)
    Q_PROPERTY(QString lbl_dbConn READ get_lbl_dbConn WRITE set_lbl_dbConn NOTIFY lbl_dbConnChanged)
    Q_PROPERTY(QString lbl_webserverConn READ get_lbl_weberverConn WRITE set_lbl_webwerverConn NOTIFY lbl_webserverConnChanged)

public:
    QString MSG_DB_CON_YES = "DB +";
    QString MSG_DB_CON_NO = "DB -";
    QString MSG_WEBSVR_CON_YES = "WEB +";
    QString MSG_WEBSVR_CON_NO = "WEB -";

    QString filePath = "";
    QString imagePath = "";
    QString folderPath = "";
    QDir fileOpenDir;
    QStringList filesInDirList;
    QStringList fileFilters  = (QStringList() << "*.jpeg" << "*.jpg" << "*.png");
    int fileIndex = 0;
    double filesInDirListSize = 0;
    //double sliderStep = 0;
    bool sliderFocus = true;
    QString fileName = "";
    QString year, month, day, hour, min, sec;
    QString date = "", time = "";
    QString lbl_dbConn = MSG_DB_CON_NO;
    QString lbl_webserverConn = MSG_WEBSVR_CON_NO;

    explicit GuiInterfaceObject(QObject *parent = nullptr);
    Q_INVOKABLE QString getImagePath() const;
    Q_INVOKABLE double getfilesInDirListSize() const;
    Q_INVOKABLE int getfileIndex() const;
    Q_INVOKABLE bool getsliderFocus() const;
    Q_INVOKABLE QString getFileName() const;
    Q_INVOKABLE QString get_lbl_dbConn() const;
    Q_INVOKABLE QString get_lbl_weberverConn() const;

signals:
    void imagePathChanged();
    void filesInDirListSizeChanged();
    void fileIndexChanged();
    void sliderFocusChanged();
    void fileNameChanged();
    void lbl_dbConnChanged();
    void lbl_webserverConnChanged();

public slots:
    void setImagePath(QString _inp);
    void setfilesInDirListSize(int _inp);
    void setfileIndex(int _inp);
    void setsliderFocus(bool _inp);
    void setFileName(QString _inp);
    void set_lbl_dbConn(QString _inp);
    void set_lbl_webwerverConn(QString _inp);

    Q_INVOKABLE void setPath(QString _inp);
    Q_INVOKABLE void setIndex(double value);
    Q_INVOKABLE void queryImage();

    void connectedToDB();
    void unconnectedToDB();
    void connectedToWebSvr();
    void unconnectedToWebSvr();

private:


};


#endif // GUIINTERFACE_H
