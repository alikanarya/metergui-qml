#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>
#include "guiinterface.h"
#include "dbthread.h"
#include "netops.h"

#define _DB_NAME            "homeAutoDB"
#define _DB_USER            "ali"
#define _DB_PASS            "reyhan"
QString clientAddress = "192.168.2.48";
QString dbName = "homeAutoDB";
QString dbUser = "ali";
QString dbPass = "reyhan";
dbThread *dbThreadX;
QString RequestUrl[8] = {
    /*0*/   "http://192.168.2.49/capture_with_flashlight",
    /*1*/   "http://192.168.2.49/capture",
    /*2*/   "http://192.168.2.11:3000/wasserzaehler.html?url=http://192.168.2.48:8080/ngmeter.jpeg&single",
    /*3*/   "http://192.168.2.11:3000/wasserzaehler.html?url=http://192.168.2.49/capture_with_flashlight&single",
    /*4*/   "http://192.168.2.11:3000/wasserzaehler.html?url=http://192.168.2.49/capture&single",
    /*5*/   "http://192.168.2.10/meter/capture.jpg",
    /*6*/   "http://192.168.2.11:3000/wasserzaehler.html?url=http://192.168.2.10/meter/capture.jpg&single",
    /*7*/   "http://192.168.2.10/meter/capture.jpg"
    };
QString webDir = "/var/www/html/";
QString webUrl = "http://192.168.2.48:8080/";

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QScopedPointer<guiInterfaceFns> guiFns(new guiInterfaceFns);

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
    QObject::connect(dbThreadX, SIGNAL(connected()),&GIO,SLOT(connectedToDB()));
    QObject::connect(dbThreadX, SIGNAL(unconnected()), &GIO, SLOT(unconnectedToDB()));

    dbThreadX->start();

    netOps _net("");
    _net.makeRequest(7);    //check local web server is runnning


    return app.exec();
}
