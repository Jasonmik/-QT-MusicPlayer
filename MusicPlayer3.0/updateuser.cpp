#include "updateuser.h"
#include<QSqlDatabase>
#include<QSqlQuery>
#include <QSqlError>
upDateUser::upDateUser(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("LAPTOP-OA7F2RMO");
    db.setUserName("root");
    db.setPassword("123456");
    db.setDatabaseName("userbase");
    if(!db.open()){
        qDebug() <<db.lastError();
    }else{
        qDebug() <<"成功";
    }

}

