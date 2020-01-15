#ifndef GUIINTERFACE_H
#define GUIINTERFACE_H

#include <QObject>
#include <QDir>

class guiInterface : public QObject
{
    Q_OBJECT
public:

    QString guiString = "";

    QString loadedFileName = "";
    QString loadedFileNamewPath = "";
    QDir fileOpenDir;
    QStringList filesInDirList;
    QStringList fileFilters  = (QStringList() << "*.jpeg" << "*.jpg" << "*.png");
    int filesInDirListIndex = 0;
    explicit guiInterface(QObject *parent = nullptr);

    Q_INVOKABLE void test();
    Q_INVOKABLE void test(QString _inp);

signals:

public slots:
};

#endif // GUIINTERFACE_H
