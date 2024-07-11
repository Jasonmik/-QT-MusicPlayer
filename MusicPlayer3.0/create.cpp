#include "create.h"
#include "ui_create.h"
#include "login.h"
#include "widget.h"
#include<QPainter>

Create::Create(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Create)
{
    ui->setupUi(this);
    this->setWindowTitle("用户注册");
    ui->userName_2->setEchoMode(QLineEdit::Password);
    ui->userName->setEchoMode(QLineEdit::Password);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinMaxButtonsHint);  //去掉窗口边框
    setAttribute(Qt::WA_TranslucentBackground);  //设置窗口背景透明
    setWindowIcon(QIcon(":/image_/windowicon.png"));
}


Create::~Create()
{
    delete ui;
}


//用户注册
void Create::on_Create_2_clicked()
{
    // 创建一个QSqlQuery对象
    QSqlQuery query;
    int id;
    int idc=ui->userID->text().toInt();
    // 执行一个查询已有用户名和密码的SQL语句
    QString selectQuery = "SELECT id FROM login2;";
    query.exec(selectQuery);
    while(query.next()){
        id =query.value("id").toInt();
        if(id==idc){
            QMessageBox::information(nullptr,"致命错误！","账号重复");
            return;
        }
    }
    if(ui->userName->text()!=ui->userName_2->text()){
        QMessageBox::information(nullptr,"致命错误！","密码不匹配");
        return;
    }
    if(ui->userID->text()==""){
        QMessageBox::information(nullptr,"致命错误！","账号不能为空");
        return;
    }
    if(ui->userName->text()==""){
        QMessageBox::information(nullptr,"致命错误！","密码不能为空");
        return;
    }
    int passWordc=ui->userName->text().toInt();
    QString createTableQuery ="INSERT INTO login2 (id, passWord) VALUES (:id, :passWord);";
    query.prepare(createTableQuery);
    query.bindValue(":id",idc);
    query.bindValue(":passWord",passWordc);
    if (query.exec()) {
        qDebug() << "插入成功";
    } else {
        qDebug() << "插入失败：" << query.lastError();
    }
    //返回登录页面，开始登录
    Login *w = new Login();
    w->show();
    this->close();

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


void Create::on_pushButton_clicked()
{
    //返回登录页面，开始登录
    Login *w = new Login();
    w->show();
    this->hide();
}

//窗口透明和圆角
void Create::paintEvent(QPaintEvent* event){
    QPainter painter(this);
    painter.drawPixmap(0, 0, width(), height(), QPixmap(":/image_/beijing.png"));
    painter.setRenderHint(QPainter::Antialiasing);  // 反锯齿;
    //painter.setBrush(QBrush(QColor(255, 255, 255)));
    //painter.setPen(Qt::transparent);
    QRect rect = this->rect();
    painter.drawRoundedRect(rect, 15, 15);  //设置窗口圆角 15px
}

void Create::mousePressEvent(QMouseEvent *event)
{
    this->windowPos = this->pos();       // 获得部件当前位置
    this->mousePos = event->globalPosition().toPoint(); // 获得鼠标位置
    this->dPos = mousePos - windowPos;   // 移动后部件所在的位置
}
void Create::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos() - this->dPos);
}
