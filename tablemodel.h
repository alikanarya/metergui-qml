#ifndef TABLEMODEL_H
#define TABLEMODEL_H
/*
#include <QObject>

class TableModel : public QObject
{
    Q_OBJECT
public:
    explicit TableModel(QObject *parent = nullptr);

signals:

public slots:
};
*/

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QAbstractTableModel>
#include <QStringListModel>

class TableModel : public QAbstractTableModel
{
    Q_OBJECT

public:

    int rowLength = 48;

    int rowCount(const QModelIndex & = QModelIndex()) const override
    {
        return rowLength;
    }

    int columnCount(const QModelIndex & = QModelIndex()) const override
    {
        return 4;
    }

    QVariant data(const QModelIndex &index, int role) const override
    {
        switch (role) {
            case Qt::DisplayRole:
                return QString("%1, %2").arg(index.column()).arg(index.row());
            default:
                break;
        }

        return QVariant();
    }

    QHash<int, QByteArray> roleNames() const override
    {
        return { {Qt::DisplayRole, "display"} };
    }

    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole);
private:
    QStringList stringList;
};



#endif // TABLEMODEL_H
