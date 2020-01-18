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
    Q_PROPERTY(int fileIndex READ getfileIndex WRITE setfileIndex NOTIFY fileIndexChanged)
    Q_PROPERTY(bool sliderFocus READ getsliderFocus WRITE setsliderFocus NOTIFY sliderFocusChanged)

public:
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

    explicit GuiInterfaceObject(QObject *parent = nullptr);
    Q_INVOKABLE QString getImagePath() const;
    Q_INVOKABLE double getfilesInDirListSize() const;
    Q_INVOKABLE int getfileIndex() const;
    Q_INVOKABLE bool getsliderFocus() const;

signals:
    void imagePathChanged();
    void filesInDirListSizeChanged();
    void fileIndexChanged();
    void sliderFocusChanged();

public slots:
    void setImagePath(QString _inp);
    void setfilesInDirListSize(int _inp);
    void setfileIndex(int _inp);
    void setsliderFocus(bool _inp);

    Q_INVOKABLE void setPath(QString _inp);
    Q_INVOKABLE void setIndex(double value);

private:


};


#endif // GUIINTERFACE_H
