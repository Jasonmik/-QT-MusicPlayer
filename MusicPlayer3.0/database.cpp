#include "database.h"
#include<QSqlQuery>
DataBase::DataBase(QWidget *parent)
    : QWidget{parent}
{
    //172.18.13.6
    //172.18.22.87
    //10.18.4.5

}

void DataBase::login(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("muou");
    db.setUserName("root");
    db.setPassword("123456");
    db.setDatabaseName("muou");
    if(!db.open()){
        qDebug() <<db.lastError();
    }else{
        qDebug() <<"成功";
    }
}

void DataBase::userbase(int id){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("muou");
    db.setUserName("root");
    db.setPassword("123456");
    db.setDatabaseName("userbase");
    if(!db.open()){
        qDebug() <<db.lastError();
    }else{
        qDebug() <<"成功";
    }
    QString tableName = QString::number(id);
    QSqlQuery query(db);
    query.exec("SELECT COUNT(*) FROM information_schema.tables WHERE table_schema = 'userbase' AND table_name = '" + tableName + "'");
    if (query.next()) {
        int count = query.value(0).toInt();
        if (count > 0) {
            qDebug() << "表存在";
        } else {
            QString createTableQuery = "CREATE TABLE t"+QString::number(id)+" (hash int,picUrl VARCHAR(255),"
                                                                                "playUrl VARCHAR(255),singername VARCHAR(255),"
                                                                                "songname VARCHAR(255),"
                                                                                "duration int, PRIMARY KEY (hash))";
            QSqlQuery query(db);
            if (!query.exec(createTableQuery)) {
                qDebug()<<id;
            } else {
                qDebug() << "表创建成功";
            }
        }
    }
    else {
        qDebug() << "查询失败：" << query.lastError().text();
    }


}
