#include "create.h"
#include "ui_create.h"
#include "widget.h"
#include "login.h"
Create::Create(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Create)
{
    ui->setupUi(this);
    this->setWindowTitle("用户注册");
    ui->userName_2->setEchoMode(QLineEdit::Password);
    ui->userName->setEchoMode(QLineEdit::Password);

}


Create::~Create()
{
    delete ui;
}


//用户注册
void Create::on_Create_2_clicked()
{
    //将获取的注册的用户名、密码存入数据库


    //返回登录页面，开始登录
    Login *w = new Login();
    w->show();
    this->hide();
}

//显示密码

void Create::on_checkBox_clicked(bool checked)
{
    if(checked){
        ui->userName_2->setEchoMode(QLineEdit::Normal);
        ui->userName->setEchoMode(QLineEdit::Normal);
    }
    else{
        ui->userName_2->setEchoMode(QLineEdit::Password);
        ui->userName->setEchoMode(QLineEdit::Password);
    }
}

