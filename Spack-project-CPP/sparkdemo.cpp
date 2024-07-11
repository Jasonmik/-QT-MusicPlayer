#include "sparkdemo.h"

SparkDemo::SparkDemo()
{

}


QString SparkDemo::call(QString value)
{
    //这个是星火大模型实例调用的py文件地址
    QString pythonFilePath = "D:\\Code\\Spack-project-CPP/sparkAPI-1.py";

    QProcess pythonProcess;
    QStringList arguments;
    // 将函数名和参数添加到QStringList中，顺序入下：appid， api_key， api_secret
    QStringList functionArguments;
        functionArguments << "107dcf21"
                          << "2b8978cfc82aab5a9ae8ea60a1d952bd"
                          << "Y2VlMTU0MjNlZDdiNzk5NGE5ZmViNDhk"
                          << "wss://spark-api.xf-yun.com/v1.1/chat"
                          << value;

    arguments << pythonFilePath << "main" << functionArguments;


    //这里是python的环境地址，根据自己的python环境填写
    pythonProcess.start("E:\\work_software\\Python\\install\\python", arguments);

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

            pythonOutput.replace("None", "");
            // 返回输出内容
            return pythonOutput;
        }
        else
        {
            qDebug() << "Failed to execute Python file.";
            // 返回空字符串
            return QString();
        }
}
