#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>
#include "guiinterface.h"
#include "dbthread.h"
#include "netops.h"
//#include "tablemodel.h"

#define _DB_NAME            "homeAutoDB"
#define _DB_USER            "ali"
#define _DB_PASS            "reyhan"
QString clientAddress = "192.168.2.48";
QString dbName = "homeAutoDB";
QString dbUser = "ali";
QString dbPass = "reyhan";
dbThread *dbThreadX;
netOps *netX;
QString RequestUrl[8] = {
    /*0*/   "http://192.168.2.49/capture_with_flashlight",
    /*1*/   "http://192.168.2.49/capture",
    /*2*/   "http://192.168.2.11:3000/wasserzaehler.html?url=http://192.168.2.48:8080/ngmeter.jpeg&single",
    /*3*/   "http://192.168.2.11:3000/wasserzaehler.html?url=http://192.168.2.49/capture_with_flashlight&single",
    /*4*/   "http://192.168.2.11:3000/wasserzaehler.html?url=http://192.168.2.49/capture&single",
    /*5*/   "http://192.168.2.10/meter/capture.jpg",
    /*6*/   "http://192.168.2.11:3000/wasserzaehler.html?url=http://192.168.2.10/meter/ngmeter.jpeg&single",
    /*7*/   "http://127.0.0.1/meter/ngmeter.jpeg"
    };
QString webSvrFile = "C:/xampp/htdocs/meter/ngmeter.jpeg";
QString webUrl = "http://192.168.2.48:8080/";

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QScopedPointer<guiInterfaceFns> guiFns(new guiInterfaceFns);
    //qmlRegisterType<TableModel>("TableModel", 0, 1, "TableModel");

    QQmlApplicationEngine engine;

    //qmlRegisterType<GuiInterfaceObject>("com.guiobject",1,0,"GuiObject");

    //engine.rootContext()->setContextProperty("guiFns", guiFns.data());
    GuiInterfaceObject GIO;
    engine.rootContext()->setContextProperty("GIO", &GIO);


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    dbThreadX = new dbThread();
    dbThreadX->cmdConnect = true;
    QObject::connect(dbThreadX, SIGNAL(connected()), &GIO, SLOT(connectedToDB()));
    QObject::connect(dbThreadX, SIGNAL(unconnected()), &GIO, SLOT(unconnectedToDB()));

    dbThreadX->start();

    netX = new netOps("");
    QObject::connect(netX, SIGNAL(connectedToWebSvr()), &GIO, SLOT(connectedToWebSvr()));
    QObject::connect(netX, SIGNAL(unconnectedToWebSvr()), &GIO, SLOT(unconnectedToWebSvr()));
    QObject::connect(netX, SIGNAL(dockerReplyBad()), &GIO, SLOT(dockerReplyBad()));
    QObject::connect(netX, SIGNAL(dockerReplyGood(QString)), &GIO, SLOT(dockerReplyGood(QString)));
    netX->makeRequest(7);    //check local web server is runnning


    return app.exec();
}
