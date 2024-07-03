#include "login.h"
#include "ui_login.h"
#include "widget.h"
#include "create.h"
Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinMaxButtonsHint);  //去掉窗口边框
    ui->setupUi(this);
    this->setWindowTitle("用户登录");
    ui->userID->setEchoMode(QLineEdit::Password);
}

Login::~Login()
{
    delete ui;
}


void Login::on_Login_2_clicked()//登录
{

    //遍历数据库数据while

    //如果用户正确
    if(ui->userName->text()==tr("123")&&ui->userID->text()==tr("123"))
    {

        //进入播放器主页面
        Widget *w = new Widget;
        w->show();
        this->hide();
    }
    else
    {

       //弹出  密码错误提示
        QMessageBox msgBox;
        msgBox.setText("用户名或密码输入错误");
        msgBox.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
        msgBox.exec();
    }
}


void Login::on_Create_clicked()//注册
{
    Create *c = new Create();
    c->show();
    this->hide();
}



//显示密码
void Login::on_checkBox_clicked(bool checked)
{

    if(checked){
        ui->userID->setEchoMode(QLineEdit::Normal);
    }
    else{
        ui->userID->setEchoMode(QLineEdit::Password);
    }
}

//退出
void Login::on_pushButton_clicked()
{
    this->close();
}

