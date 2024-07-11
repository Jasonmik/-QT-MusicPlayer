#include "widget.h"
#include <QApplication>
#include "login.h"
#include "create.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Login w;
    w.show();
    return a.exec();
}
