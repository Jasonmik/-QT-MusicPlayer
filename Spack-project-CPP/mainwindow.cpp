#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sparkdemo.h"

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


void MainWindow::on_pushButton_clicked()
{
    QString value = this->ui->textEdit->toPlainText();
    SparkDemo demo;
    QString answer = demo.call(value);
    this->ui->textBrowser_2->setText(answer);
}
