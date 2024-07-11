#include "login.h"
#include "ui_login.h"
#include "widget.h"
#include "create.h"
Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinMaxButtonsHint);  //去掉窗口边框
    setAttribute(Qt::WA_TranslucentBackground);  //设置窗口背景透明
    ui->setupUi(this);
    this->setWindowTitle("用户登录");
    ui->userID->setEchoMode(QLineEdit::Password);
    Data.login();
    setWindowIcon(QIcon(":/image_/windowicon.png"));

}

Login::~Login()
{
    delete ui;
}


void Login::on_Login_2_clicked()//登录
{

    //遍历数据库数据while
    QSqlQuery query;
    //执行已有的表
    QString sql="SELECT *FROM login2;";
    query.exec(sql);
    int id;
    int passWord;
    while(query.next()){
        id =query.value("id").toInt();
        passWord=query.value("passWord").toInt();
        if(id==ui->userName->text().toInt()&&passWord==ui->userID->text().toInt()){
            break;
        }
    }
    //如果用户正确
    if(ui->userName->text().toInt()==id&&ui->userID->text().toInt()==passWord)
    {
        //进入播放器主页面
        Widget *w = new Widget(id);
        w->show();
        this->hide();
        Data.userbase(id);
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

//窗口透明和圆角
void Login::paintEvent(QPaintEvent* event){
    QPainter painter(this);
    painter.drawPixmap(0, 0, width(), height(), QPixmap(":/image_/beijing.png"));
    painter.setRenderHint(QPainter::Antialiasing);  // 反锯齿;
    //painter.setBrush(QBrush(QColor(255, 255, 255)));
    //painter.setPen(Qt::transparent);
    QRect rect = this->rect();
    painter.drawRoundedRect(rect, 15, 15);  //设置窗口圆角 15px
}

void Login::mousePressEvent(QMouseEvent *event)
{
    this->windowPos = this->pos();       // 获得部件当前位置
    this->mousePos = event->globalPosition().toPoint(); // 获得鼠标位置
    this->dPos = mousePos - windowPos;   // 移动后部件所在的位置
}
void Login::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos() - this->dPos);
}

