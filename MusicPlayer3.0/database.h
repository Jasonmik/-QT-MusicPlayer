#ifndef DATABASE_H
#define DATABASE_H

#include <QWidget>
#include<QSqlDatabase>
#include <QSqlError>
class DataBase : public QWidget
{
    Q_OBJECT
public:
    explicit DataBase(QWidget *parent = nullptr);
    //链接数据库
    void login();
    void userbase(int id);
signals:
};

#endif // DATABASE_H
