#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>
#include "guiinterface.h"

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

    return app.exec();
}
