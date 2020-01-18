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
    Q_PROPERTY(double filesInDirListSize READ getfilesInDirListSize WRITE setfilesInDirListSize NOTIFY filesInDirListSizeChanged)
    Q_PROPERTY(double sliderStep NOTIFY imagePathChanged)

public:
    QString filePath = "";
    QString imagePath = "";
    QString folderPath = "";
    QDir fileOpenDir;
    QStringList filesInDirList;
    QStringList fileFilters  = (QStringList() << "*.jpeg" << "*.jpg" << "*.png");
    int filesInDirListIndex = 0;
    double filesInDirListSize = 0;
    double sliderStep = 0;

    explicit GuiInterfaceObject(QObject *parent = nullptr);
    Q_INVOKABLE QString getImagePath() const;
    Q_INVOKABLE double getfilesInDirListSize() const;

signals:
    void imagePathChanged();
    void filesInDirListSizeChanged();

public slots:
    void setImagePath(QString _inp);
    void setfilesInDirListSize(int _inp);
    Q_INVOKABLE void setPath(QString _inp);

private:


};


#endif // GUIINTERFACE_H
