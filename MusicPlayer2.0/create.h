#ifndef CREATE_H
#define CREATE_H

#include <QWidget>

namespace Ui {
class Create;
}

class Create : public QWidget
{
    Q_OBJECT

public:
    explicit Create(QWidget *parent = nullptr);
    ~Create();

private slots:
    void on_Create_2_clicked();

    void on_checkBox_clicked(bool checked);

private:
    Ui::Create *ui;
};

#endif // CREATE_H
