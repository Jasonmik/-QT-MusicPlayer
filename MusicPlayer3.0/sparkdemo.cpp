#include "sparkdemo.h"
#include<QRegularExpression>
SparkDemo::SparkDemo()
{

}

QString SparkDemo::call(QString value)
{
    //这个是星火大模型实例调用的py文件地址
    QString pythonFilePath = "D:\\qt\\xiangmu\\Spack-project-CPP\\sparkAPI-1.py";

    QProcess pythonProcess;
    QStringList arguments;
    // 将函数名和参数添加到QStringList中，顺序入下：appid， api_key， api_secret
    QStringList functionArguments;
    functionArguments << "be151e63"
                      << "780315cf3ec4c28a432c0e9238054ee4"
                      << "NGU5NGQzYjk1NjNhOGEyNWQzNGQ5ZGNl"
                      << "wss://spark-api.xf-yun.com/v4.0/chat"
                      << value;

    arguments << pythonFilePath << "main" << functionArguments;


    //这里是python的环境地址，根据自己的python环境填写
    pythonProcess.start("C:\\Users\\lenovo\\AppData\\Local\\Programs\\Python\\Python312\\python.exe", arguments);

    if (pythonProcess.waitForFinished(-1))
    {
        QByteArray output = pythonProcess.readAllStandardOutput();
        // 将输出内容转换为QString
        QString pythonOutput = QString::fromUtf8(output);

        QByteArray error = pythonProcess.readAllStandardError();

        if (!pythonOutput.isEmpty())
            qDebug() << "Python Output:" << pythonOutput;

        if (!error.isEmpty())
            qDebug() << "Python Error:" << error;


        // 使用正则表达式删除 "####" 符号及其后面的所有文本
        QRegularExpression re("(####|###).*");
        pythonOutput.remove(re); // 删除匹配的部分

        // 这里不需要再次赋值给 pythonOutput，因为 remove() 已经修改了原字符串
        pythonOutput = pythonOutput.trimmed(); //这行代码是多余的

        // 返回处理后的输出内容
        return pythonOutput;



        //pythonOutput.replace("None", "pythonOutput = pythonOutput.trimmed();");
        // 返回输出内容
        //return pythonOutput;
    }
    else
    {
        qDebug() << "Failed to execute Python file.";
        // 返回空字符串
        return QString();
    }
}
