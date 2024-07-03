#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include<QMessageBox>
namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_Login_2_clicked();

    void on_Create_clicked();


    void on_checkBox_clicked(bool checked);

    void on_pushButton_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
