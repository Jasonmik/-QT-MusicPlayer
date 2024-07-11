#ifndef CREATE_H
#define CREATE_H

#include <QWidget>
#include "database.h"
namespace Ui {
class Create;
}

class Create : public QWidget
{
    Q_OBJECT

public:
    explicit Create(QWidget *parent = nullptr);
    ~Create();
    void paintEvent(QPaintEvent* event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
private slots:
    void on_Create_2_clicked();

    void on_checkBox_clicked(bool checked);

    void on_pushButton_clicked();



private:
    Ui::Create *ui;
    QPoint windowPos;
    QPoint mousePos;
    QPoint dPos;

};

#endif // CREATE_H
