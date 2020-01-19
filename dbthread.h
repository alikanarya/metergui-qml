#ifndef DBTHREAD_H
#define DBTHREAD_H

#include <QThread>
#include <QtSql>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>


extern QString clientAddress;
extern QString dbName;
extern QString dbUser;
extern QString dbPass;

extern int totalTime;

class dbThread: public QThread{

    Q_OBJECT

public:

    dbThread();
    ~dbThread();

    void stop();
    void connectToDB();

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    QSqlQuery qry;
    QList<int> timeDiffList;
    QList<int> timeDiffListOn;
    QList<int> timeDiffListOff;
    QList<int> stateList;
    QList<int> thresholdIndexList;

    QString beginDate;
    QString endDate;
    QString beginTime;
    QString endTime;
    QString beginTimeDelimiter;
    QString endTimeDelimiter;
    QString queryBeginTime;

    bool delimiterEncountered;


    bool verbose = false;
    bool cmdConnect = false;



    struct tempData {
        int timeDiff;
        float value;
    };



public slots:


protected:

    void run();

private:

    volatile bool stopped;

signals:

    void connected();
    void unconnected();

};

#endif // DBTHREAD_H
