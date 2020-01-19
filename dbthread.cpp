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




