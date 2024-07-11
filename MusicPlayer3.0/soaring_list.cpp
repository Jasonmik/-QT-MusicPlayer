#include "soaring_list.h"
#include<QEventLoop>
#include<QNetworkAccessManager>
#include<QNetworkReply>
#include<QJsonDocument>
#include<QJsonObject>
#include<QFile>
#include<QFileInfo>
Soaring_list::Soaring_list() {
    Soaring_manager = new QNetworkAccessManager();
    Soaring_request=new QNetworkRequest();
    connect(Soaring_manager,&QNetworkAccessManager::finished,this,&Soaring_list::Soaring_songs_finished);
    Soaring_pic_manager = new QNetworkAccessManager();
    Soaring_pic_request=new QNetworkRequest();
    connect(Soaring_pic_manager,&QNetworkAccessManager::finished,this,&Soaring_list::Soaring_pic_finished);
    lrc_manager=new QNetworkAccessManager();
    lrc_request =new QNetworkRequest();
    connect(lrc_manager,&QNetworkAccessManager::finished,this,&Soaring_list::lrc_Finished);
}

void Soaring_list::round(){
    lrcCount=0;
    for(int i=0;i<20;i++){
        Soaring_songs();
    }
    for(int i=0;i<SoarList.size();i++){
        Count=i;
        Soaring_pic();
        lyric(i);
    }
}
void Soaring_list::Soaring_songs(){
    QString KGAPISTR1="https://api.vvhan.com/api/wyMusic/飙升榜?type=json";
    Soaring_request->setUrl(QUrl(KGAPISTR1));
    Soaring_manager->get(*Soaring_request);
    //开启一个局部的事件循环，等待响应结束，退出
    QEventLoop eventLoop;
    QObject::connect(Soaring_manager,&QNetworkAccessManager::finished, &eventLoop, &QEventLoop::quit);
    //add timeout deal
    QTimer *tmpTimer = new QTimer();
    QAbstractSocket::connect(tmpTimer,SIGNAL(timeout()),&eventLoop, SLOT(quit()));
    tmpTimer->setSingleShot(true);
    tmpTimer->start(1000);
    eventLoop.exec();
    tmpTimer->stop();
}

void Soaring_list::Soaring_songs_finished(QNetworkReply *reply){
    //获取响应的信息，状态码为200表示正常
    QVariant status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    qDebug()<<"飙升："<<status_code;
    //无错误返回
    if(reply->error() == QNetworkReply::NoError)
    {
        QByteArray bytes = reply->readAll();  //获取字节
        QString result(bytes);  //转化为字符串
        Soaring_json(result);
    }
    else
    {
        //处理错误
        qDebug()<<"飙升搜索失败";
    }

}

void Soaring_list::Soaring_json(QString json){
    QJsonDocument jsonDoc = QJsonDocument::fromJson(json.toUtf8());
    QJsonObject jsonObj = jsonDoc.object();
    QJsonObject infoObj = jsonObj["info"].toObject();
    QString picUrl = infoObj["picUrl"].toString();
    QString url = infoObj["url"].toString();
    int id=infoObj["id"].toInt();
    if(id==0){
        return;
    }
    if(isSongValid(url)){
        return;
    }
    QString name=infoObj["name"].toString();
    QString auther=infoObj["auther"].toString();
    Soar S;
    S.picUrl=picUrl;
    S.url=url;
    S.auther=auther;
    S.id=id;
    S.name=name;
    SoarList.append(S);
}


//cover
void Soaring_list::Soaring_pic(){
    QString KGAPISTR1=SoarList.at(Count).picUrl;
     qDebug()<<SoarList.at(Count).picUrl;
    Soaring_pic_request->setUrl(QUrl(KGAPISTR1));
    Soaring_pic_manager->get(*Soaring_pic_request);
    //开启一个局部的事件循环，等待响应结束，退出
    QEventLoop eventLoop;
    QObject::connect(Soaring_pic_manager,&QNetworkAccessManager::finished, &eventLoop, &QEventLoop::quit);
    //add timeout deal
    QTimer *tmpTimer = new QTimer();
    QAbstractSocket::connect(tmpTimer,SIGNAL(timeout()),&eventLoop, SLOT(quit()));
    tmpTimer->setSingleShot(true);
    tmpTimer->start(3000);
    eventLoop.exec();
    tmpTimer->stop();
}
//cover
void Soaring_list::Soaring_pic_finished(QNetworkReply *reply){
    QPixmap pixmap;
    pixmap.loadFromData(reply->readAll());//获取字节
    // 将 QPixmap 转换为 QImage
    QImage image(pixmap.toImage());
    // 设置保存的文件名和路径
    QString fileName="D:\\qt\\MusicPlayer\\Soar_pic\\"+QString::number(SoarList.at(Count).id)+".jpg";
    QFile file(fileName);
    if(file.open(QIODevice::WriteOnly)){
        file.write(reply->readAll());
        file.close();
    }
    // 保存 QImage 到文件
    image.save(fileName, "JPG", 90); // 75 是 JPEG 的质量因子（1-100）
    qDebug()<<"图片保存成功";
    qDebug()<<Count;
}


//歌词
void Soaring_list::lyric(int i){
    int hash=SoarList.at(i).id;
    QString KGAPISTR1 =QString("http://music.163.com/api/song/lyric?id="+QString::number(hash)+"&lv=1&kv=1&tv=-1");
    //歌词
    lrc_request->setUrl(QUrl(KGAPISTR1));
    lrc_manager->get(*lrc_request);
    //开启一个局部的事件循环，等待响应结束，退出
    QEventLoop eventLoop;
    QObject::connect(lrc_manager,&QNetworkAccessManager::finished, &eventLoop, &QEventLoop::quit);
    //add timeout deal
    QTimer *tmpTimer = new QTimer();
    connect(tmpTimer,SIGNAL(timeout()),&eventLoop, SLOT(quit()));
    tmpTimer->setSingleShot(true);
    tmpTimer->start(3000);
    eventLoop.exec();
    tmpTimer->stop();
}

//歌词
void Soaring_list::lrc_Finished(QNetworkReply *reply){
    //获取响应的信息，状态码为200表示正常
    QVariant status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    qDebug()<<"飙升歌词："<<status_code;
    //无错误返回
    if(reply->error() == QNetworkReply::NoError)
    {
        QByteArray bytes = reply->readAll();  //获取字节
        QString result(bytes);  //转化为字符串
        lrc_json(result);
    }
    else
    {
        //处理错误
        qDebug()<<"歌词搜索失败";
    }

}

//歌词
void Soaring_list::lrc_json(QString json){
    QJsonDocument parse_doucment = QJsonDocument::fromJson(json.toUtf8());
    QJsonObject jsonObj=parse_doucment.object();
    QJsonObject lrcObj = jsonObj["lrc"].toObject();
    QString lyric = lrcObj["lyric"].toString();
    QString path="D:\\qt\\MusicPlayer\\Soar_lyrics\\";
    QFile file(path+SoarList.at(lrcCount).name+QString::number(SoarList.at(lrcCount).id)+".txt");
    if (file.open(QIODevice::WriteOnly)) {
        file.write(lyric.toUtf8());
        file.close();
        qDebug() << "File created successfully.";
    }
    else {
        qDebug() << "Failed to create file.";
    }
    lrcCount++;
}


bool Soaring_list::isSongValid(const QString &songPath) {
    QFileInfo check_file(songPath);
    // 检查文件是否存在且可读
    return check_file.exists() && check_file.isReadable();
}











