#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include<QMessageBox>
#include<QSqlQuery>
#include "database.h"
namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    void paintEvent(QPaintEvent* event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
private slots:
    void on_Login_2_clicked();

    void on_Create_clicked();

    void on_checkBox_clicked(bool checked);

    void on_pushButton_clicked();


private:
    Ui::Login *ui;
    DataBase Data;
    QPoint windowPos;
    QPoint mousePos;
    QPoint dPos;
};

#endif // LOGIN_H
