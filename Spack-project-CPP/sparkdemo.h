#ifndef SPARKDEMO_H
#define SPARKDEMO_H
#include <QCoreApplication>
#include <QProcess>
#include <QDebug>
#include <QFile>

class SparkDemo
{
public:
    SparkDemo();
    QString call(QString value);
};

#endif // SPARKDEMO_H
