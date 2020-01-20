#ifndef NETOPS_H
#define NETOPS_H

#define RequestID   "RequestID"

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QImage>
#include <iostream>
#include <QString>
#include <QByteArray>
#include <QTextCodec>
#include <QImageWriter>
#include <QDir>
#include <QProcess>
//#include "datathread.h"
#define MAX 64

using namespace std;

//extern dataThread *dataX;

extern QString RequestUrl[];
extern QString webDir;
extern QString webUrl;

class netOps : public QObject
{
    Q_OBJECT
    QNetworkAccessManager manager;

public:
    QUrl url;
    int requestMode = 0;
    char line[MAX];
    char dateInfo[MAX];
    char timeInfo[MAX];
    char dirName[MAX];
    char dirName1[MAX];
    char dirName2[MAX];
    char dirNameF[MAX];
    char fileName[MAX];
    char fileNameBare[MAX];
    bool dockerHostLive = false;
    bool camNgLive = false;
    bool dockerRunning = false;
    bool localWebServerRunning = false;

    explicit netOps(QObject *parent = 0);
    netOps(QString _url);
    ~netOps();
    void makeRequest(unsigned int id);
    bool checkHost(QString ip);

signals:

public slots:
    void downloadFinished(QNetworkReply *reply);

};

#endif // NETOPS_H
