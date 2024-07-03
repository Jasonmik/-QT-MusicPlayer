#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Login_clicked()
{
    if(ui->userName->text()==tr("")&&ui->userID->text()==tr(""))
    {

    }
    else
    {
       // QMessageBox::warning(this,tr("warning"),tr("userName or password Error !"),QMessageBox::Yes);
        QMessageBox msgBox;
       msgBox.setText("用户名或密码输入错误");
       msgBox.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
       msgBox.exec();
    }
}

