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


class GuiInterfaceObject : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString imagePath READ getImagePath WRITE setImagePath NOTIFY imagePathChanged)

public:
    QString filePath = "";
    QString imagePath = "";
    QString folderPath = "";
    QDir fileOpenDir;
    QStringList filesInDirList;
    QStringList fileFilters  = (QStringList() << "*.jpeg" << "*.jpg" << "*.png");
    int filesInDirListIndex = 0;

    explicit GuiInterfaceObject(QObject *parent = nullptr);
    Q_INVOKABLE QString getImagePath() const;

signals:
    void updatePicture();
    void imagePathChanged();

public slots:
    void setImagePath(QString _inp);
    Q_INVOKABLE void setPath(QString _inp);

private:


};


#endif // GUIINTERFACE_H
