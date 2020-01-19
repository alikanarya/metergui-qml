#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>
#include "guiinterface.h"
#include "dbthread.h"

#define _DB_NAME            "homeAutoDB"
#define _DB_USER            "ali"
#define _DB_PASS            "reyhan"
QString MSG_DB_CON_YES = "DB+";
QString MSG_DB_CON_NO = "DB-";
QString clientAddress = "192.168.2.48";
QString dbName = "homeAutoDB";
QString dbUser = "ali";
QString dbPass = "reyhan";
dbThread *dbThreadX;

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
    dbThreadX->start();
    QObject::connect(dbThreadX, SIGNAL(connected()),&GIO,SLOT(connectedToDB()));
    QObject::connect(dbThreadX, SIGNAL(unconnected()), &GIO, SLOT(unconnectedToDB()));
    return app.exec();
}
