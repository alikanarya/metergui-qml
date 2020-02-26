#ifndef GUIINTERFACE_H
#define GUIINTERFACE_H

#include <QObject>
#include <QDir>
#include "netops.h"
#include "dbthread.h"

extern netOps *netX;
extern dbThread *dbThreadX;

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
    Q_PROPERTY(bool busyIndicatorState READ getbusyIndicatorState WRITE setbusyIndicatorState NOTIFY busyIndicatorStateChanged)
    Q_PROPERTY(QString result READ get_result WRITE set_result NOTIFY resultChanged)
    Q_PROPERTY(bool resultFixed READ get_resultFixed WRITE set_resultFixed NOTIFY resultFixedChanged)
    Q_PROPERTY(QString autoResult READ get_autoResult WRITE set_autoResult NOTIFY autoResultChanged)
    Q_PROPERTY(QString autoDate READ get_autoDate WRITE set_autoDate NOTIFY autoDateChanged)
    Q_PROPERTY(QString autoTime READ get_autoTime WRITE set_autoTime NOTIFY autoTimeChanged)
    Q_PROPERTY(bool autoResultFixed READ get_autoResultFixed WRITE set_autoResultFixed NOTIFY autoResultFixedChanged)

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
    int fileIndex = 0, fileIndexDB = 0;
    double filesInDirListSize = 0;
    //double sliderStep = 0;
    bool sliderFocus = true;
    QString fileName = "";
    QString year, month, day, hour, min, sec;
    QString date = "", time = "";
    QString lbl_dbConn = MSG_DB_CON_NO;
    QString lbl_webserverConn = MSG_WEBSVR_CON_NO;
    bool busyIndicatorState = false;
    QString result = "";
    bool resultFixed = false;
    bool queryFolderActive = false;
    bool queryFolderFinished = true;
    int queryFolderIndex = 0;

    struct imageData {
        QString date = "";
        QString time = "";
        QString result = "";
        bool fixed = false;
    };

    imageData *data;
    QList<imageData *> analysisList;

    QString autoResult = "";
    QString autoDate = "";
    QString autoTime = "";
    bool autoResultFixed = false;

    explicit GuiInterfaceObject(QObject *parent = nullptr);
    Q_INVOKABLE QString getImagePath() const;
    Q_INVOKABLE double getfilesInDirListSize() const;
    Q_INVOKABLE int getfileIndex() const;
    Q_INVOKABLE bool getsliderFocus() const;
    Q_INVOKABLE QString getFileName() const;
    Q_INVOKABLE QString get_lbl_dbConn() const;
    Q_INVOKABLE QString get_lbl_weberverConn() const;
    Q_INVOKABLE bool getbusyIndicatorState() const;
    Q_INVOKABLE QString get_result() const;
    Q_INVOKABLE bool get_resultFixed() const;
    Q_INVOKABLE QString get_autoResult() const;
    Q_INVOKABLE QString get_autoDate() const;
    Q_INVOKABLE QString get_autoTime() const;
    Q_INVOKABLE bool get_autoResultFixed() const;

signals:
    void imagePathChanged();
    void filesInDirListSizeChanged();
    void fileIndexChanged();
    void sliderFocusChanged();
    void fileNameChanged();
    void lbl_dbConnChanged();
    void lbl_webserverConnChanged();
    void busyIndicatorStateChanged();
    void resultChanged();
    void resultFixedChanged();
    void autoResultChanged();
    void autoDateChanged();
    void autoTimeChanged();
    void autoResultFixedChanged();

public slots:
    void setImagePath(QString _inp);
    void setfilesInDirListSize(int _inp);
    void setfileIndex(int _inp);
    void setsliderFocus(bool _inp);
    void setFileName(QString _inp);
    void set_lbl_dbConn(QString _inp);
    void set_lbl_webwerverConn(QString _inp);
    void setbusyIndicatorState(bool _inp);
    void set_result(QString _inp);
    void set_resultFixed(bool _inp);
    void set_autoResult(QString _inp);
    void set_autoDate(QString _inp);
    void set_autoTime(QString _inp);
    void set_autoResultFixed(bool _inp);

    void queryFolder();

    Q_INVOKABLE void setPath(QString _inp);
    Q_INVOKABLE void setIndex(double value);
    Q_INVOKABLE void queryImage();
    Q_INVOKABLE void setResult(QString _inp);
    Q_INVOKABLE void queryFolderInit();
    Q_INVOKABLE void setAutoResultFixed(bool _inp);
    Q_INVOKABLE void setAutoResult(QString _inp);
    Q_INVOKABLE void insertFolderResults();

    void connectedToDB();
    void unconnectedToDB();
    void connectedToWebSvr();
    void unconnectedToWebSvr();
    void dockerReplyBad();
    void dockerReplyGood(QString _inp);
    void nextData();

private:


};


#endif // GUIINTERFACE_H
