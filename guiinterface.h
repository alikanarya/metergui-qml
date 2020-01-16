#ifndef GUIINTERFACE_H
#define GUIINTERFACE_H

#include <QObject>
#include <QDir>



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


class guiInterfaceObject : public QObject
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

    explicit guiInterfaceObject(QObject *parent = nullptr);

signals:
    void updatePicture();

public slots:
    void setPath(QString _inp);
};


#endif // GUIINTERFACE_H
