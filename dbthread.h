#ifndef DBTHREAD_H
#define DBTHREAD_H

#include <QThread>
#include <QtSql>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>

#define FIXED   "fixed"

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
    void insertToDB();

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    QSqlQuery qry;
    QString date = "", time = "";
    float result = 0;
    bool resultFixed = false;
    bool insertFolderData = false;


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
    bool cmdInsert = false;

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
    void nextData();

};

#endif // DBTHREAD_H
