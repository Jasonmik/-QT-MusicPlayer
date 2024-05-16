#pragma execution_character_set("utf-8")
#include "lyrics.h"

QList<QString> Lyrics::getListLyricsText() const  //获取歌词文本
{
    return listLyricsText;
}

QList<int> Lyrics::getListLyricsTime() const   //获取播放时间
{
    return listLyricsTime;
}

Lyrics::Lyrics(QString lyricsPath)  //获取歌词路径
{
    this->lyricsPath = lyricsPath;
}

Lyrics::Lyrics() {}

bool Lyrics::readLyricsFile(QString lyricsPath)  //导入歌词路径，解析文本内容
{
    QFile file(lyricsPath);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        listLyricsText.clear();
        listLyricsTime.clear();
        return false;
    }
    QString line="";
    while((line=file.readLine())>'0'){
        qDebug()<<line;
        analysisLyricsFile(line);//解析歌词文件内容
    }
    return true;
}

bool Lyrics::analysisLyricsFile(QString line)  //对每一行歌词进行解析
{
    if(line.isEmpty()){
        qDebug()<<"thie line is empty!";
        return false;
    }
    QRegularExpression regularExpression("\\[(\\d+)?:(\\d+)?(\\.\\d+)?\\](.*)?"); //正则表达式  获取歌词内容
    int index = 0;
    QRegularExpressionMatch match;
    match = regularExpression.match(line, index);
    if(match.hasMatch()) {
        int totalTime;
        totalTime = match.captured(1).toInt() * 60000 + match.captured(2).toInt() * 1000;                    /*  计算该时间点毫秒数            */
        QString currentText =QString::fromStdString(match.captured(4).toStdString());                       /*   获取歌词文本*/
        qDebug()<<totalTime;
        qDebug()<<currentText;
        listLyricsText.push_back(currentText);  //输出歌词
        listLyricsTime.push_back(totalTime);
        return true;
    }
    return false;
}
