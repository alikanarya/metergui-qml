#include "dbthread.h"

using namespace std;

dbThread::dbThread(){

    db.setHostName(clientAddress);
    db.setDatabaseName(dbName);
    db.setUserName(dbUser);
    db.setPassword(dbPass);
}

dbThread::~dbThread(){}

void dbThread::run(){

    if (cmdConnect){
        connectToDB();
        cmdConnect = false;
    }

    if (cmdInsert){
        insertToDB();
        cmdInsert = false;
    }

    verbose = false;
}

void dbThread::stop(){}

void dbThread::connectToDB(){

    if (!db.open()) {
        qDebug() <<  db.lastError().text() << db.lastError().number();
        emit unconnected();
    } else {
        emit connected();
    }
}

void dbThread::insertToDB()
{
    if (db.open()) {
        QString qryStr = "";
        if (!resultFixed)
            qryStr = QString( "INSERT INTO gas_reading (date, time, value) VALUES ('%1', '%2', %3)").arg(date).arg(time).arg(result);
        else
            qryStr = QString( "INSERT INTO gas_reading (date, time, value, note) VALUES ('%1', '%2', %3, '%4')").arg(date).arg(time).arg(result).arg(FIXED);

        //qDebug() << qryStr.toUtf8().constData();

        qry.prepare( qryStr );

        if( !qry.exec() ){
            qDebug() << qry.lastError().type();
            qDebug() << qry.lastError().databaseText();
        }
        else {
            qDebug( "Inserted!" );
        }
    }
    resultFixed = false;
}




