#include "widget.h"
#include "ui_widget.h"
#include "lyrics.h"
#include "login.h"
#include"sparkdemo.h"
#include<QMouseEvent>
#include<QPixmap>
#include<QFileDialog>
#include<QDebug>
#include<QDir>
#include<QIcon>
#include<QtMultimedia>
#include<QUrl>
#include<QAudioOutput>
#include<QMediaPlayer>
#include<QPaintEvent>
#include<QSlider>
#include<QListWidget>
#include<QMovie>
#include<QMenuBar>
#include<QPixmap>
#include <QImageReader>
#include <QThread>
#include <QScrollBar>
#include<QMessageBox>
#include<QNetworkRequest>
#include <QSqlError>
#include<QSqlQuery>
Widget::Widget(int id)
    : QWidget()
    , ui(new Ui::Widget)
{
    setAttribute(Qt::WA_TranslucentBackground);  //设置窗口背景透明
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinMaxButtonsHint);  //去掉窗口边框
    ui->setupUi(this);
    //output对象
    audioOutput=new QAudioOutput(this);
    //媒体播放对象
     mediaplayer =new QMediaPlayer(this);
     mediaplayer->setAudioOutput(audioOutput);
     mediaplayer->setSource(QUrl::fromLocalFile("D:\\qt\\MusicPlayer\\music"));

     //获取当前媒体长度
     connect(mediaplayer,&QMediaPlayer::durationChanged,this,[=](qint64 duration ){
         ui->totaltime->setText(QString("%1:%2").arg(duration/1000/60).arg(duration/1000%60));
         ui->currentSlider->setRange(0,duration);

     });
    //当前媒体进度
     connect(mediaplayer,&QMediaPlayer::positionChanged,this,[=](qint64 position){
         ui->currenttime->setText(QString("%1:%2").arg(position/1000/60).arg(position/1000%60));
         ui->currentSlider->setValue(position);
         positiontime=position;

         setPlayTime();
     });
     //判断自动播放下一首
     connect(mediaplayer,&QMediaPlayer::positionChanged,this,[=](qint64 posi){
         if(posi>=mediaplayer->duration()){
             if(playlist.empty()){
                 qDebug()<<"\a";
                 return;
             }
             PlayModeF();
             //元素改变
             changeElement();
         }
     });
    //拖动改变进度
     connect(ui->currentSlider,&QSlider::sliderMoved,mediaplayer,&QMediaPlayer::setPosition);
    //设置初始音量
     audioOutput->setVolume(0.5);
     //音量栏默认不可见
     ui->volumeSlider->setVisible(false);
     connect(ui->volumeSlider,&QSlider::sliderMoved,audioOutput,&QAudioOutput::setVolume);

     //音乐列表不可见
     //ui->listWidget->setVisible(false);
     //设置图片
     GIF=new QMovie(":/boy");
     ui->GIFlabel->setScaledContents(true);
     ui->GIFlabel->setMovie(GIF);
     GIF1=new QMovie(":/wave");
     ui->wavelabel->setScaledContents(true);
     ui->wavelabel->setMovie(GIF1);
     //默认模板顺序
     QFont font("黑体",10,5);
     QFont font1("华文中宋",30,20);
      QFont font2("华文中宋",40,20);
     ui->textlabel1->setFont(font1);
     ui->textlabel2->setFont(font2);
     ui->textlabel3->setFont(font1);
     //设置
     ui->listWidget->setContextMenuPolicy(Qt::CustomContextMenu);
     this->setContextMenuPolicy(Qt::NoContextMenu);
     //菜单栏
     QMenuBar *bar=new QMenuBar(this);
     //菜单项
     QMenu *menu=new QMenu("菜单1");
     bar->addMenu(menu);
     bar->setVisible(false);
     //子菜单
     menu->addAction(del);
     connect(del,&QAction::triggered,this,[=](){
         aItem=ui->listWidget->takeItem(ui->listWidget->currentRow());
         delete aItem;
     });
     //table、美化
     style();
     //初始化网络
     initNet();
     blur_effect=new QGraphicsBlurEffect();
     blur_effect->setBlurRadius(5);
     setBackGround();
     SGIF=new QMovie(":/image_/loading.gif");
     ui->searchstate->setMovie(SGIF);
     ui->Floading->setMovie(SGIF);
     ui->LikeState->setMovie(SGIF);
     ui->Floading->hide();
     ui->searchstate->hide();
     ui->LikeState->hide();
     userID=id;
     setWindowIcon(QIcon(":/image_/windowicon.png"));
}

Widget::~Widget()
{
    delete ui;
}

//点击关闭窗口
void Widget::on_pushButton_8_clicked()
{
    this->close();
}
//窗口最小化
void Widget::on_pushButton_10_clicked()
{
    this->showMinimized();
}
//本地文件导入
void Widget::on_pushButton_clicked()
{
    //点击打开默认文件夹选择音乐
    path=QFileDialog::getExistingDirectory(this,"请选择音乐所在的目录","D:\\qt\\MusicPlayer\\music");
    qDebug()<<path;
    QDir dir(path);
    auto MusicList =dir.entryList(QStringList()<<"*.mp3"<<"*.WAV"<<"*.ogg"<<"*.mgg");
    if(MusicList.empty()){
        return;
    }
    currentFlag=2;
    currentPlayIndex=0;
    //音乐名字展示在listWidget
    for(int i=0;i<ui->listWidget->count();i++){
        ui->listWidget->takeItem(i);
    }
    ui->listWidget->clear();
    ui->listWidget->addItems(MusicList);
    //默认位置
    ui->listWidget->setCurrentRow(0);

    //播放列表初始化
    playlist.clear();
    l_listResult.clear();
     //把音乐名字的完整路径保存起来
    for(auto file:MusicList){
        playlist.append(QUrl::fromLocalFile(path+"/"+ file));
    }
    qDebug()<<playlist;
}
//暂停/播放按钮
void Widget::on_pushButton_2_clicked()
{

    setPlayTime();
    changeElement();
    if(playlist.empty()){
        qDebug()<<"\a";
        return;
    }
    if(!isSongValid(QString(playlist[currentPlayIndex].toString()))){

    }
    switch(mediaplayer->playbackState()){
    case QMediaPlayer::PlaybackState::StoppedState:
    {
        currentPlayIndex =ui->listWidget->currentRow();
        mediaplayer->setSource(playlist[currentPlayIndex]);
        ui->pushButton_2->setStyleSheet("image :url(:/star)");
        if(currentFlag==1){
            ui->star->setStyleSheet("image :url(:/star)");
        }
        GIF->start();
        GIF1->start();
        mediaplayer->play();
        lyricsDate();
        break;
    }
    case QMediaPlayer::PlaybackState::PlayingState:
    {
        mediaplayer->pause();
        ui->pushButton_2->setStyleSheet("image :url(:/pause)");
        if(currentFlag==1){
            ui->star->setStyleSheet("image :url(:/pause)");
        }
        GIF->stop();
        GIF1->stop();
        break;
    }
    case QMediaPlayer::PlaybackState::PausedState:
    {
        ui->pushButton_2->setStyleSheet("image :url(:/star)");
        if(currentFlag==1){
            ui->star->setStyleSheet("image :url(:/star)");
        }
        GIF->start();
        GIF1->start();
        mediaplayer->play();
        break;
    }
    }

}
//上一曲
void Widget::on_pushButton_11_clicked()
{
    pre=true;
    if(playlist.empty()){
        qDebug()<<"\a";
        return;
    }
    ui->pushButton_2->setStyleSheet("image :url(:/star)");
    if(currentFlag==1){
        ui->star->setStyleSheet("image :url(:/star)");
    }
    if(currentPlayIndex==0){
        currentPlayIndex=playlist.size();
    }
    if(playflag==2){
        currentPlayIndex=rand()%playlist.size();
    }
    else{
        currentPlayIndex=(currentPlayIndex-1)%playlist.size();
    }
    ui->listWidget->setCurrentRow(currentPlayIndex);
    mediaplayer->setSource(playlist[currentPlayIndex]);
    mediaplayer->play();
    lyricsDate();
    if(GIF->Paused){
        GIF->start();
        GIF1->start();
    }
    //元素改变
    changeElement();
}
//下一曲
void Widget::on_pushButton_5_clicked()
{

    next =true;
    if(playlist.empty()){
        qDebug()<<"\a";
        return;
    }
    ui->pushButton_2->setStyleSheet("image :url(:/star)");
    if(currentFlag==1){
        ui->star->setStyleSheet("image :url(:/star)");
    }
    if(playflag==2){
        currentPlayIndex=rand()%playlist.size();
    }
    else{
        currentPlayIndex=(currentPlayIndex+1)%playlist.size();
    }
    ui->listWidget->setCurrentRow(currentPlayIndex);
    mediaplayer->setSource(playlist[currentPlayIndex]);  
    mediaplayer->play();
    lyricsDate();
    if(GIF->Paused){
        GIF->start();
        GIF1->start();
    }
    //元素改变
    changeElement();
}
//双击播放
void Widget::on_listWidget_doubleClicked(const QModelIndex &index)
{
    ui->pushButton_2->setStyleSheet("image :url(:/star)");
    if(currentFlag==1){
        ui->star->setStyleSheet("image :url(:/star)");
    }
    ui->star->setStyleSheet("image :url(:/star)");
    currentPlayIndex=index.row();
    mediaplayer->setSource(playlist[currentPlayIndex]);
    mediaplayer->play();
    //元素改变
    changeElement();
    GIF->start();
    GIF1->start();
    lyricsDate();

}
//窗口透明和圆角
void Widget::paintEvent(QPaintEvent* event){
    // painter.begin(this);
    // QPainterPath path;
    //  //设置边框为圆角15px
    // path.addRoundedRect(rect(),15, 15);
    // painter.setRenderHint(QPainter::Antialiasing,true);  // 反锯齿;
    // painter.setClipPath(path);
    // //画图片
    // painter.drawPixmap(rect(), QPixmap(":/image_/backGround"+QString::number(bkChange)+".png"));
    // painter.end();
}
//背景设置
void Widget::setBackGround(){
    QPixmap pixmap_userIcon;
    //搜索
    if(coverFlag&&currentFlag==0){
        if(m_listResult.empty()){
            return;
        }
        pixmap_userIcon.load("D:\\qt\\MusicPlayer\\cover\\"+QString::number(m_listResult.at(currentPlayIndex).hash));
    }
    //飙升榜
    else if(coverFlag&&currentFlag==1){
        if(Soar->SoarList.empty()){
            return;
        }
        pixmap_userIcon.load("D:\\qt\\MusicPlayer\\Soar_pic\\"+QString::number(Soar->SoarList.at(currentPlayIndex).id));
    }
    //皮肤
    else{
        pixmap_userIcon.load(":/image_/backGround"+QString::number(bkChange)+".png");
    }
    QPixmap fitpixmap_userIcon = pixmap_userIcon.scaled(1100, 700, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    fitpixmap_userIcon = round(fitpixmap_userIcon, 20);
    ui->backGround->setPixmap(fitpixmap_userIcon);
}
//图片圆角
QPixmap Widget::round(const QPixmap& img_in, int radius)
{
    if (img_in.isNull())
    {
        qDebug()<<"11";
        return QPixmap();
    }
    QSize size(img_in.size());
    QBitmap mask(size);
    QPainter painter(&mask);
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.fillRect(mask.rect(), Qt::white);
    painter.setBrush(QColor(0, 0, 0));
    painter.drawRoundedRect(mask.rect(), radius, radius);
    QPixmap image = img_in;// .scaled(size);
    image.setMask(mask);
    return image;
}

//鼠标事件接收
void Widget::mousePressEvent(QMouseEvent *event)
{
    this->windowPos = this->pos();       // 获得部件当前位置
    this->mousePos = event->globalPosition().toPoint(); // 获得鼠标位置
    this->dPos = mousePos - windowPos;   // 移动后部件所在的位置
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos() - this->dPos);
}
//静音
void Widget::on_pushButton_3_clicked()
{

    if(num%2==0){
        audioOutput->setVolume(0);
        num++;
        ui->pushButton_3->setStyleSheet("image :url(:/silence)");
    }
    else{
        ui->pushButton_3->setStyleSheet("image :url(:/sound)");
        audioOutput->setVolume(0.5);
        num++;
    }

}
//音量滑条
void Widget::on_pushButton_6_clicked()
{
    if(ui->volumeSlider->isVisible()){
        ui->volumeSlider->setVisible(false);
    }
    else{
        ui->volumeSlider->setVisible(true);
    }
}

void Widget::on_volumeSlider_sliderMoved(int position)
{
    audioOutput->setVolume(position);

}

//播放模式
void Widget::on_pushButton_7_clicked()
{
    Playmode++;
    if(Playmode%3==2){
        ui->pushButton_7->setStyleSheet("image :url(:/image_/rand.png)");
        playflag=2;
    }
    if(Playmode%3==0){
        ui->pushButton_7->setStyleSheet("image :url(:/image_/play-cycle.png)");
        playflag=1;
    }
    if(Playmode%3==1)
    {
        ui->pushButton_7->setStyleSheet("image :url(:/image_/play-order.png)");
        playflag=0;
    }
}
//循环播放
void Widget::PlayModeCirculate(){
    currentPlayIndex=currentPlayIndex;
    ui->listWidget->setCurrentRow(currentPlayIndex);
    mediaplayer->setSource(playlist[currentPlayIndex]);
    mediaplayer->play();
}
//顺序播放
void Widget::PlayModeOrder(){
    currentPlayIndex=(currentPlayIndex+1)%playlist.size();
    ui->listWidget->setCurrentRow(currentPlayIndex);
    mediaplayer->setSource(playlist[currentPlayIndex]);
    mediaplayer->play();
}
//随机播放
void Widget::PlayModeRand(){
    currentPlayIndex=rand()%playlist.size();
    ui->listWidget->setCurrentRow(currentPlayIndex);
    mediaplayer->setSource(playlist[currentPlayIndex]);
    mediaplayer->play();
}

void Widget::PlayModeF(){
    //重写代码复用
    //顺序播放
    if(playflag==0){
        PlayModeOrder();
        lyricsDate();
    }
    //单曲循环
    else if(playflag==1){
        PlayModeCirculate();
        lyricsDate();
    }
    //随机播放
    else{
        PlayModeRand();
        lyricsDate();
    }
}
//歌词时间判断
void Widget::setPlayTime(){
    if(lyricsID>=lyrics.getListLyricsText().count()){
        return;
    }
    if(positiontime>=lyrics.listLyricsTime.last()){
        return ;
    }
    if(!lyrics.getListLyricsTime().empty()&&mediaplayer->position()>lyrics.getListLyricsTime().at(lyricsID)){
        if(lyricsID>=1){
            ui->textlabel1->setText(lyrics.getListLyricsText().at(lyricsID-1));
        }
        ui->textlabel2->setText(lyrics.getListLyricsText().at(lyricsID));
        ui->textlabel3->setText(lyrics.getListLyricsText().at(lyricsID+1));
        lyricsID++;
    }
}
//歌词载入与初始化
void Widget::lyricsDate(){
    ui->textlabel1->setText(" ");
    ui->textlabel2->setText(" ");
    ui->textlabel3->setText(" ");
    lyricsID=0;
    //本地
    if(currentFlag==2){
        QDir dir1;
        auto MusicList1 =dir1.entryList(QStringList()<<"*.lrc");
        QString name=ui->listWidget->currentItem()->text().left(ui->listWidget->currentItem()->text().lastIndexOf("."));
        if(!lyrics.readLyricsFile(path+"/"+name+".lrc")){
            ui->textlabel2->setText("未检出歌词");
            ui->textlabel3->setText("请检查路径");
        }
        if(lyrics.getListLyricsTime().empty()&&lyrics.readLyricsFile(path+"/"+name+".lrc")){
            ui->textlabel2->setText("此歌曲为没有填词的纯音乐");
            ui->textlabel3->setText("此歌曲为没有填词的纯音乐");
        }
        qDebug()<<ui->listWidget->currentItem()->text().left(ui->listWidget->currentItem()->text().lastIndexOf("."));
    }
    //飙升榜
    else if(currentFlag==1){
        QString name="D:\\qt\\MusicPlayer\\Soar_lyrics\\";
        if(!lyrics.readLyricsFile(name+Soar->SoarList.at(ui->listWidget->currentRow()).name+
                                   QString::number(Soar->SoarList.at(ui->listWidget->currentRow()).id)+".txt")){
            ui->textlabel2->setText("暂无歌词");
            ui->textlabel3->setText("暂无歌词");
        }
        if(lyrics.getListLyricsTime().empty()
            &&lyrics.readLyricsFile(name+Soar->SoarList.at(ui->listWidget->currentRow()).name+
                                     QString::number(Soar->SoarList.at(ui->listWidget->currentRow()).id)+".txt")){
            ui->textlabel2->setText("此歌曲为没有填词的纯音乐");
            ui->textlabel3->setText("此歌曲为没有填词的纯音乐");
        }
        qDebug()<<name+Soar->SoarList.at(ui->listWidget->currentRow()).name+
                        QString::number(Soar->SoarList.at(ui->listWidget->currentRow()).id);
    }
    //搜索
    else if(currentFlag==0){
        QString name="D:\\qt\\MusicPlayer\\lyrics\\";
        if(!lyrics.readLyricsFile(name+l_listResult.at(ui->listWidget->currentRow()).songname+
                                  QString::number(l_listResult.at(ui->listWidget->currentRow()).hash)+".txt")){
            ui->textlabel2->setText("暂无歌词");
            ui->textlabel3->setText("暂无歌词");
        }
        if(lyrics.getListLyricsTime().empty()
            &&lyrics.readLyricsFile(name+l_listResult.at(ui->listWidget->currentRow()).songname+
                                     QString::number(l_listResult.at(ui->listWidget->currentRow()).hash)+".txt")){
            ui->textlabel2->setText("此歌曲为没有填词的纯音乐");
            ui->textlabel3->setText("此歌曲为没有填词的纯音乐");
        }
        qDebug()<<name+l_listResult.at(ui->listWidget->currentRow()).songname+
                                     QString::number(l_listResult.at(ui->listWidget->currentRow()).hash);
    }
    //Like
    else if(currentFlag==3){
        QString name="D:\\qt\\MusicPlayer\\lyrics\\";
        if(!lyrics.readLyricsFile(name+Like.at(ui->listWidget->currentRow()).songname+
                                   QString::number(Like.at(ui->listWidget->currentRow()).hash)+".txt")){
            ui->textlabel2->setText("暂无歌词");
            ui->textlabel3->setText("暂无歌词");
        }
        if(lyrics.getListLyricsTime().empty()
            &&lyrics.readLyricsFile(name+Like.at(ui->listWidget->currentRow()).songname+
                                     QString::number(Like.at(ui->listWidget->currentRow()).hash)+".txt")){
            ui->textlabel2->setText("此歌曲为没有填词的纯音乐");
            ui->textlabel3->setText("此歌曲为没有填词的纯音乐");
        }
        qDebug()<<name+Like.at(ui->listWidget->currentRow()).songname+
                        QString::number(Like.at(ui->listWidget->currentRow()).hash);
    }
}


//listItem右键功能
void Widget::on_listWidget_customContextMenuRequested(const QPoint &pos)
{
    QMenu *ptr=new QMenu(this);
    ptr->addAction(del);
    ptr->exec(QCursor::pos());
    int index=ui->listWidget->currentRow();
    if(l_listResult.empty()){
         playlist.removeAt(index);
    }
    else{
        playlist.removeAt(index);
        l_listResult.remove(index);
    }
    qDebug()<<"删除成功！";
    //qDebug()<<playlist;
    delete ptr;
}



//换壁纸
void Widget::on_pushButton_9_clicked()
{
    backchange++;
    if(backchange%4==1){
        bkChange=2;
        setBackGround();
        //update();
    }
    else if(backchange%4==2){
        bkChange=3;
        setBackGround();
        //update();
    }
    else if(backchange%4==3){
        bkChange=1;
        setBackGround();
        //update();
    }
    // else if(backchange%4==0){

    // }
}
//初始化网络
void Widget::initNet(){
    Soar=new Soaring_list();
    //音乐
    network_manager = new QNetworkAccessManager(this);
    network_request = new QNetworkRequest();
    connect(network_manager, &QNetworkAccessManager::finished, this, &Widget::replyFinished);
    //图片
    pic_manager= new QNetworkAccessManager(this);
    pic_request =new QNetworkRequest();
    connect(pic_manager,&QNetworkAccessManager::finished,this,&Widget::pic_Finished);
    //歌词
    lrc_request =new QNetworkRequest();
    lrc_manager= new QNetworkAccessManager(this);
    connect(lrc_manager,&QNetworkAccessManager::finished,this,&Widget::lrc_Finished);
    //设置图片
    setpic_manager = new QNetworkAccessManager(this);
    setpic_request=new QNetworkRequest();
    connect(setpic_manager,&QNetworkAccessManager::finished,this,&Widget::setpic_Finished);
}

//搜索
void Widget::on_search_clicked()
{
    ui->searchstate->show();
    SGIF->start();
    ui->search->setEnabled(false);
    ui->LikeUpDate->setEnabled(false);
    while(ui->tableWidget->rowCount()){
        ui->tableWidget->removeRow(0);
    }
    m_listResult.clear();
    like.clear();
    QString strInput = ui->lineEdit->text();
    QString KGAPISTR1 =QString("https://music.163.com/api/search/get/web?csrf_token=hlpretag=&hlposttag=&s="
                                + strInput + "&type=1&offset=0&total=true&limit=15");
    network_request->setUrl(QUrl(KGAPISTR1));
    network_manager->get(*network_request);
}

//歌曲
void Widget::replyFinished(QNetworkReply *reply)
{

    //获取响应的信息，状态码为200表示正常
    QVariant status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    qDebug()<<"歌曲"<<status_code;
    //无错误返回
    if(reply->error() == QNetworkReply::NoError)
    {
        QByteArray bytes = reply->readAll();  //获取字节
        QString result(bytes);  //转化为字符串
        //qDebug()<<result;//结果
        ParseJson(result);//该函数用于解析api接口返回的json
        lrcCount=0;
        picCount=0;
        setLikePic=false;
        for(int i=0;i<m_listResult.size();i++){
            lyric(i);
            picture(i);
        }
        insertItem();//向table widget添加搜索结果
        setpicture();

    }
    else
    {
        //处理错误
        qDebug()<<"歌曲搜索失败";
    }

}

//歌曲
void Widget::ParseJson(QString json){
    QJsonDocument parse_doucment = QJsonDocument::fromJson(json.toUtf8());
    QJsonObject jsonObj=parse_doucment.object();
    QJsonObject resultObj=jsonObj["result"].toObject();
    QJsonArray songsArray =resultObj["songs"].toArray();
    for(int i=0;i<songsArray.size();i++){
        findResult set;
        QJsonObject songsObj=songsArray[i].toObject();
        set.hash=songsObj["id"].toInt();
        int id =songsObj["id"].toInt();
        if(id==0){
            continue;
        }
        QJsonArray artistArray=songsObj["artists"].toArray();
        for(int j=0;j<artistArray.size();j++){
            QJsonObject artistObj=artistArray[j].toObject();
            set.singername=artistObj["name"].toString();
        }
        QJsonObject albumObj=songsObj["album"].toObject();
        set.albumid=albumObj["id"].toInt();
        set.songname=songsObj["name"].toString();
        set.duration=songsObj["duration"].toInt();
        QUrl url="https://music.163.com/song/media/outer/url?id="+QString::number(id)+".mp3";
        QString U="https://music.163.com/song/media/outer/url?id="+QString::number(id)+".mp3";
        set.U=U;
        set.play_url=url;
        set.picUrl="";
        m_listResult.append(set);
        like.append(0);


    }
}

//歌词
void Widget::lyric(int i){
    int hash;
    if(setLikePic){
        hash=Like.at(i).hash;
    }
    else{
        hash=m_listResult.at(i).hash;
    }
    strinput = QString::number(hash);
    QString KGAPISTR1 =QString("http://music.163.com/api/song/lyric?id="+strinput+"&lv=1&kv=1&tv=-1");
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
    tmpTimer->start(1000);
    eventLoop.exec();
    tmpTimer->stop();
}

//歌词
void Widget::lrc_Finished(QNetworkReply *reply){
    //获取响应的信息，状态码为200表示正常
    QVariant status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    qDebug()<<"歌词："<<status_code;
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
void Widget::lrc_json(QString json){
    QJsonDocument parse_doucment = QJsonDocument::fromJson(json.toUtf8());
    QJsonObject jsonObj=parse_doucment.object();
    QJsonObject lrcObj = jsonObj["lrc"].toObject();
    QString lyric = lrcObj["lyric"].toString();
    QString path="D:\\qt\\MusicPlayer\\lyrics\\";
    QFile file;
    if(setLikePic){
        file.setFileName(path+Like.at(lrcCount).songname+QString::number(Like.at(lrcCount).hash)+".txt");
    }
    else{
        file.setFileName(path+m_listResult.at(lrcCount).songname+QString::number(m_listResult.at(lrcCount).hash)+".txt");
    }
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
//图片
void Widget::picture(int i){
    //https://music.163.com/api/album/90743831
    int albumid=m_listResult.at(i).albumid;
    QString albumId = QString::number(albumid);
    QString KGAPISTR1 =QString("https://music.163.com/api/album/"+albumId);
    //歌词
    pic_request->setUrl(QUrl(KGAPISTR1));
    pic_manager->get(*pic_request);
    //开启一个局部的事件循环，等待响应结束，退出
    QEventLoop eventLoop;
    QObject::connect(pic_manager,&QNetworkAccessManager::finished, &eventLoop, &QEventLoop::quit);
    //add timeout deal
    QTimer *tmpTimer = new QTimer();
    connect(tmpTimer,SIGNAL(timeout()),&eventLoop, SLOT(quit()));
    tmpTimer->setSingleShot(true);
    tmpTimer->start(1000);
    eventLoop.exec();
    tmpTimer->stop();
}
//图片
void Widget::pic_Finished(QNetworkReply *reply){
    //获取响应的信息，状态码为200表示正常
    QVariant status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    qDebug()<<"图片："<<status_code;
    //无错误返回
    if(reply->error() == QNetworkReply::NoError)
    {
        QByteArray bytes = reply->readAll();  //获取字节
        QString result(bytes);  //转化为字符串
        pic_json(result);
    }
    else
    {
        //处理错误
        qDebug()<<"图片搜索失败";
    }
    qDebug()<<picCount;

}
//图片
void Widget::pic_json(QString json){
    QJsonDocument parse_doucment = QJsonDocument::fromJson(json.toUtf8());
    QJsonObject jsonObj=parse_doucment.object();
    QJsonObject picObj = jsonObj["album"].toObject();
    findResult set;
    set.picUrl=picObj["picUrl"].toString();
    set.albumid=m_listResult[picCount].albumid;
    set.duration=m_listResult[picCount].duration;
    set.hash=m_listResult[picCount].hash;
    set.play_url=m_listResult[picCount].play_url;
    set.singername=m_listResult[picCount].singername;
    set.songname=m_listResult[picCount].songname;
    set.U=m_listResult[picCount].U;
    m_listResult.replace(picCount,set);
    picCount++;
    qDebug()<<set.picUrl;

}
//封面
void Widget::setpicture(){
    setpicCount=0;
    if(setLikePic){
        for(int i=0;i<Like.size();i++){
            QString path=Like.at(i).picUrl;
            setpic_request->setUrl(QUrl(path));
            setpic_manager->get(*setpic_request);
            //开启一个局部的事件循环，等待响应结束，退出
            QEventLoop eventLoop;
            QObject::connect(setpic_manager,&QNetworkAccessManager::finished, &eventLoop, &QEventLoop::quit);
            //add timeout deal
            QTimer *tmpTimer = new QTimer();
            connect(tmpTimer,SIGNAL(timeout()),&eventLoop, SLOT(quit()));
            tmpTimer->setSingleShot(true);
            tmpTimer->start(1500);
            eventLoop.exec();
            tmpTimer->stop();
        }
    }
    else{
        for(int i=0;i<m_listResult.size();i++){
            setLikePic=false;
            QString path=m_listResult.at(i).picUrl;
            setpic_request->setUrl(QUrl(path));
            setpic_manager->get(*setpic_request);
            //开启一个局部的事件循环，等待响应结束，退出
            QEventLoop eventLoop;
            QObject::connect(setpic_manager,&QNetworkAccessManager::finished, &eventLoop, &QEventLoop::quit);
            //add timeout deal
            QTimer *tmpTimer = new QTimer();
            connect(tmpTimer,SIGNAL(timeout()),&eventLoop, SLOT(quit()));
            tmpTimer->setSingleShot(true);
            tmpTimer->start(1500);
            eventLoop.exec();
            tmpTimer->stop();
        }
    }


}
//封面
void Widget::setpic_Finished(QNetworkReply *reply){
    QPixmap pixmap;
    pixmap.loadFromData(reply->readAll());//获取字节
    // 将 QPixmap 转换为 QImage
    QImage image(pixmap.toImage());
    // 设置保存的文件名和路径
    QString fileName;
    if(setLikePic){
        fileName = "D:\\qt\\MusicPlayer\\cover\\"+QString::number(Like.at(setpicCount).hash)+".jpg";

    }
    else{
         fileName = "D:\\qt\\MusicPlayer\\cover\\"+QString::number(m_listResult.at(setpicCount).hash)+".jpg";
    }
    // 保存 QImage 到文件
    image.save(fileName, "JPG", 75); // 75 是 JPEG 的质量因子（1-100）
    QLabel *label=new QLabel();
    label->setPixmap(pixmap);
    label->setMaximumSize(80,80);
    label->setAlignment(Qt::AlignHCenter);     //设置居中
    label->setScaledContents(true);
    if(setLikePic){
        if(Like.at(setpicCount).picUrl==""){
            QPixmap pix(":/image_/picture.png");
            QLabel *label1=new QLabel();
            label1->setPixmap(pix);
            label1->setMaximumSize(80,80);
            label1->setAlignment(Qt::AlignHCenter);     //设置居中
            label1->setScaledContents(true);
            ui->tableWidget_2->setCellWidget(setpicCount,0,label1);
        }
        else{
            ui->tableWidget_2->setCellWidget(setpicCount,0,label);
        }
    }
    else{
        if(m_listResult.at(setpicCount).picUrl==""){
            QPixmap pix(":/image_/picture.png");
            QLabel *label1=new QLabel();
            label1->setPixmap(pix);
            label1->setMaximumSize(80,80);
            label1->setAlignment(Qt::AlignHCenter);     //设置居中
            label1->setScaledContents(true);
            ui->tableWidget->setCellWidget(setpicCount,0,label1);
        }
        else{
            ui->tableWidget->setCellWidget(setpicCount,0,label);
        }
    }
    setpicCount++;
}

//table双击
void Widget::on_tableWidget_cellDoubleClicked(int row, int column)
{
    //歌曲请求 row 是行号
    if(column==0){
        currentFlag=0;
        currentPlayIndex=row;
        for(int i=0;i<ui->listWidget->count();i++){
            ui->listWidget->takeItem(i);
        }
        ui->listWidget->clear();
        playlist.clear();
        l_listResult.clear();
        for(int i=0;i<m_listResult.size();i++){
            playlist.append(m_listResult.at(i).play_url);
            findResult set;
            set.U=m_listResult.at(i).U;
            set.albumid=m_listResult.at(i).albumid;
            set.duration=m_listResult.at(i).duration;
            set.hash=m_listResult.at(i).hash;
            set.picUrl=m_listResult.at(i).picUrl;
            set.play_url=m_listResult.at(i).play_url;
            set.singername=m_listResult.at(i).singername;
            set.songname=m_listResult.at(i).songname;
            l_listResult.append(set);
            ui->listWidget->insertItem(i,QString::number(i+1)+"、"+m_listResult.at(i).songname+"  "+m_listResult.at(i).singername);
            ui->listWidget->setCurrentRow(row);
        }
        mediaplayer->setSource(playlist[row]);
        audioOutput->setVolume(0.5);
        ui->pushButton_2->setStyleSheet("image :url(:/star)");
        ui->songname->setText(m_listResult.at(row).songname);
        QPixmap pix="D:\\qt\\MusicPlayer\\cover\\"+QString::number(m_listResult.at(row).hash)+".jpg";
        ui->lyrics_view->setIconSize(QSize(70,70));
        ui->lyrics_view->setIcon(pix);
        mediaplayer->play();
        GIF->start();
        GIF1->start();
        lyricsDate();
        qDebug()<<"音乐播放";
    }
    else{
        return;
    }



}

QString Widget::getcontains(QJsonObject Object, QString strInfo){
    if (Object.contains(strInfo))
    {
        QJsonValue value = Object.take(strInfo);
        if (value.isString())
        {
            return value.toString();
        }
    }
    return "";
}
//切换stark widget
void Widget::switchpage(){
    QString style=" color: #FFFFFF;"
                    "background-color: #718093;"
                    "border-color: #2f3640;"
                    "border: 2px solid #555;"
                    "font: 16pt 华文琥珀;";
    QString stylee="*{background-color:transparent;"
                    "font: 16pt 华文琥珀;}"
                     "QPushButton::hover{"
                     "color: #FFFFFF;"
                     "background-color: #718093;"
                     "border-color: #2f3640;"
                     "border: 2px solid #555;"
                     "}";
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if(button==ui->List_of_lyrics){
        ui->stackedWidget->setCurrentIndex(1);
        ui->List_of_lyrics->setStyleSheet(style);
        ui->Song_Search->setStyleSheet(stylee);
        ui->Song_Search_2->setStyleSheet(stylee);
        ui->lyrics_view->setStyleSheet(stylee);
        ui->likeBtn->setStyleSheet(stylee);
    }
    else if(button==ui->Song_Search){
        ui->stackedWidget->setCurrentIndex(0);
        ui->Song_Search->setStyleSheet(style);
        ui->Song_Search_2->setStyleSheet(stylee);
        ui->lyrics_view->setStyleSheet(stylee);
        ui->List_of_lyrics->setStyleSheet(stylee);
        ui->likeBtn->setStyleSheet(stylee);

    }
    else if(button==ui->lyrics_view){
        if(onlyricsView){
            ui->stackedWidget->setCurrentIndex(2);
            //按键隐藏
            ui->Song_Search->hide();
            ui->Song_Search_2->hide();
            ui->likeBtn->hide();
            ui->reLogin->hide();
            ui->pushButton_4->hide();
            onlyricsView=0;
            coverFlag=1;
            blur_effect->setBlurRadius(30);
            ui->backGround->setGraphicsEffect(blur_effect);
            setBackGround();
        }
        else{
            ui->stackedWidget->setCurrentIndex(0);
            onlyricsView=1;
            coverFlag=0;
            //按键展示
            ui->Song_Search->show();
            ui->Song_Search_2->show();
            ui->likeBtn->show();
            ui->reLogin->show();
            ui->pushButton_4->show();
            blur_effect->setBlurRadius(0);
            ui->backGround->setGraphicsEffect(blur_effect);
            setBackGround();
        }
        ui->lyrics_view->setStyleSheet(style);
        ui->Song_Search->setStyleSheet(stylee);
        ui->Song_Search_2->setStyleSheet(stylee);
        ui->List_of_lyrics->setStyleSheet(stylee);
        ui->likeBtn->setStyleSheet(stylee);
    }
    else if(button==ui->Song_Search_2){
        ui->stackedWidget->setCurrentIndex(3);
        ui->Song_Search_2->setStyleSheet(style);
        ui->Song_Search->setStyleSheet(stylee);
        ui->List_of_lyrics->setStyleSheet(stylee);
        ui->lyrics_view->setStyleSheet(stylee);
        ui->likeBtn->setStyleSheet(stylee);
    }
    else if(button==ui->star){

    }
    else if(button==ui->likeBtn){
        ui->stackedWidget->setCurrentIndex(4);
        ui->likeBtn->setStyleSheet(style);
        ui->Song_Search_2->setStyleSheet(stylee);
        ui->Song_Search->setStyleSheet(stylee);
        ui->List_of_lyrics->setStyleSheet(stylee);
        ui->lyrics_view->setStyleSheet(stylee);

    }
    else if(button==ui->pushButton_4){
        ui->stackedWidget->setCurrentIndex(5);
        ui->label_2->setStyleSheet(stylee);
        ui->label_3->setStyleSheet(stylee);
        ui->pushButton_12->setStyleSheet(stylee);
        ui->textEdit->setStyleSheet(stylee);
        ui->textBrowser_2->setStyleSheet(stylee);
    }
}

void Widget::on_List_of_lyrics_clicked()
{
    switchpage();
}


void Widget::on_Song_Search_clicked()
{
    switchpage();
}


void Widget::on_lyrics_view_clicked()
{

    switchpage();
    AnimationViewBtn();
}

void Widget::on_likeBtn_clicked()
{
    switchpage();

}
//插入table widget
void Widget::insertItem(){
    if(!m_listResult.isEmpty())
    {
        const int tableRow = m_listResult.count();
        for(int row=0; row<tableRow; row++)
        {
            QFont font("黑体",15,10);
            font.setBold(true);
            findResult info = m_listResult.at(row);
            int rownum = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(rownum);
            QTableWidgetItem *item=new QTableWidgetItem(info.songname);
            item->setFont(font);
            ui->tableWidget->setItem(row, 1,item);
            ui->tableWidget->setItem(row, 2, new QTableWidgetItem(info.singername));
            int Time=info.duration/1000;
            QString time=QString("%1:%2").arg(Time/60).arg(Time%60);
            ui->tableWidget->setItem(row, 3, new QTableWidgetItem(time));
            //ui->tableWidget->setItem(row, 4, new QTableWidgetItem(QString::number(info.hash)));
            ui->tableWidget->setRowHeight(row, 100);
        }
        ui->tableWidget->horizontalHeader()->setFixedHeight(30);
        ui->tableWidget->setColumnWidth(0,80);
        ui->tableWidget->setColumnWidth(1,400);
        ui->tableWidget->setColumnWidth(2,200);
        for(int i=0;i<tableRow;i++){
            QPixmap pix(":/image_/dislike.png");
            QLabel *label1=new QLabel();
            label1->setPixmap(pix);
            label1->setMaximumSize(60,60);
            label1->setScaledContents(true);
            ui->tableWidget->setCellWidget(i,4,label1);

        }
    }
    ui->search->setEnabled(true);//取消搜索按钮失能
    ui->LikeUpDate->setEnabled(true);//取消Like更新按钮失能
    SGIF->stop();
    ui->searchstate->hide();
}


//Soar刷新
void Widget::on_fresh_clicked()
{
    ui->Floading->show();
    SGIF->start();
    Soar->round();
    if(Soar->SoarList.empty()){
        qDebug()<<"Soar no songs";
        return;
    }
    QString path="D:\\qt\\MusicPlayer\\Soar_pic\\"+QString::number(Soar->SoarList.at(0).id)+".jpg";
    QPixmap pix(path);
    ui->Soaring_cover->setPixmap(pix.scaled(250,250));
    ui->Soaring_song_name->setText(Soar->SoarList.at(0).name);
    ui->star->show();
    ui->Floading->hide();
    SGIF->stop();
}
//Soar播放
void Widget::on_star_clicked()
{
    playState();
    ui->pushButton_2->setStyleSheet("image :url(:/star)");
    if(Soar->SoarList.empty()){
        qDebug()<<"Soar no songs";
        return;
    }
    if(currentFlag!=1){
        for(int i=0;i<ui->listWidget->count();i++){
            ui->listWidget->takeItem(i);
        }
        ui->listWidget->clear();
        playlist.clear();
        l_listResult.clear();
        for(int i=0;i<Soar->SoarList.size();i++){
            playlist.append(Soar->SoarList.at(i).url);
            ui->listWidget->insertItem(i,QString::number(i+1)+"、"+Soar->SoarList.at(i).name+"  "+Soar->SoarList.at(i).auther);
            ui->listWidget->setCurrentRow(0);
        }
        currentFlag=1;
        currentPlayIndex=0;
        ui->listWidget->setCurrentRow(0);
        mediaplayer->setSource(playlist[currentPlayIndex]);
        mediaplayer->play();
        changeElement();
        qDebug()<<playlist;
    }

}

void Widget::on_Song_Search_2_clicked()
{
    switchpage();
}
//表格美化
void Widget::style(){
    //设置图标
    del->setIcon(QIcon(":/delete"));
    //搜索表格整行选中的方式
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    //搜索表格禁止编辑
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //搜索表格去除选中虚线框
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);
    ui->tableWidget_2->setFocusPolicy(Qt::NoFocus);
    //搜索表格不显示网格线
    ui->tableWidget->setShowGrid(false);
    ui->tableWidget->setFrameShape(QFrame::NoFrame); //设置无边框
    ui->tableWidget_2->setShowGrid(false);
    ui->tableWidget_2->setFrameShape(QFrame::NoFrame); //设置无边框
    // 设置滚动条样式
    QString scrollBarStyle = "QScrollBar:vertical {"
                             "    background-color:#F0F0F0;"
                             "    width: 15px;"
                             "}"
                             "QScrollBar::handle:vertical {"
                             "    background-color: #C0C0C0;"
                             "    border-radius: 7px;"
                             "    max-height: 15px;"
                             "}"
                             "QScrollBar::add-line:vertical,"
                             "QScrollBar::sub-line:vertical {"
                             "    height: 0px;}";


    QString stye="QScrollBar:horizontal {"
                   "    background-color: #F0F0F0;"
                   "    width: 15px;"
                   "}"
                   "QScrollBar::handle:horizontal {"
                   "    background-color: #C0C0C0;"
                   "    border-radius: 7px;"
                   "    min-height: 30px;"
                   "}"
                   "QScrollBar::add-line:horizontal,"
                   "QScrollBar::sub-line:horizontal {"
                   "    height: 0px;"
                   "}";
    ui->tableWidget->horizontalScrollBar()->setStyleSheet(stye);
    ui->tableWidget->verticalScrollBar()->setStyleSheet(scrollBarStyle);
    ui->tableWidget_2->horizontalScrollBar()->setStyleSheet(stye);
    ui->tableWidget_2->verticalScrollBar()->setStyleSheet(scrollBarStyle);
    ui->listWidget->verticalScrollBar()->setStyleSheet(scrollBarStyle);
    ui->listWidget->horizontalScrollBar()->setStyleSheet(stye);
    QIcon icon(":/image_/home.png");
    ui->Song_Search_2->setIconSize(QSize(30,30));
    ui->Song_Search_2->setIcon(icon);
    ui->Song_Search_2->setLayoutDirection(Qt::LeftToRight);
    QIcon icon1(":/image_/search.png");
    ui->Song_Search->setIconSize(QSize(30,30));
    ui->Song_Search->setIcon(icon1);
    ui->Song_Search->setLayoutDirection(Qt::LeftToRight);
    QIcon icon2(":/image_/picture.png");
    ui->lyrics_view->setIconSize(QSize(80,80));
    ui->lyrics_view->setIcon(icon2);
    ui->lyrics_view->setLayoutDirection(Qt::LeftToRight);
    QIcon icon3(":/image_/music-list.png");
    ui->List_of_lyrics->setIconSize(QSize(50,50));
    ui->List_of_lyrics->setIcon(icon3);
    ui->List_of_lyrics->setLayoutDirection(Qt::LeftToRight);
    //隐藏行号
    QHeaderView* headerView = ui->tableWidget->verticalHeader();
    headerView->setHidden(true);
    headerView=ui->tableWidget_2->verticalHeader();
    headerView->setHidden(true);
    ui->star->hide();

}

//改变元素
void Widget::changeElement(){
    //搜索
    ui->Soaring_cover_1->setGraphicsEffect(blur_effect);
    ui->Soaring_cover_2->setGraphicsEffect(blur_effect);
    if(currentFlag==0){
        if(l_listResult.empty()){
            return;
        }
        ui->songname->setText(l_listResult.at(currentPlayIndex).songname);
        CoverBtnPath="D:\\qt\\MusicPlayer\\cover\\"+QString::number(l_listResult.at(currentPlayIndex).hash)+".jpg";
        QPixmap pix=CoverBtnPath;

        ui->lyrics_view->setIconSize(QSize(70,70));
        ui->lyrics_view->setIcon(pix);
    }
    //飙升榜
    else if(currentFlag==1){
        if(Soar->SoarList.empty()){
            return;
        }
        ui->Soaring_song_name->setText(Soar->SoarList.at(currentPlayIndex).name);
        CoverBtnPath="D:\\qt\\MusicPlayer\\Soar_pic\\"+QString::number(Soar->SoarList.at(currentPlayIndex).id)+".jpg";
        QPixmap pix=CoverBtnPath;
        ui->lyrics_view->setIconSize(QSize(70,70));
        ui->lyrics_view->setIcon(pix);
        ui->Soaring_cover->setPixmap(pix.scaled(250,250));
        ui->songname->setText(Soar->SoarList.at(currentPlayIndex).name);
        if(currentPlayIndex+1>Soar->SoarList.size()-1||currentPlayIndex==0){
            if(currentPlayIndex+1>Soar->SoarList.size()-1){
                QPixmap pix1="D:\\qt\\MusicPlayer\\Soar_pic\\"+QString::number(Soar->SoarList.at(0).id)+".jpg";
                ui->Soaring_cover_2->setPixmap(pix1.scaled(250,250));
                QPixmap pix2="D:\\qt\\MusicPlayer\\Soar_pic\\"+QString::number(Soar->SoarList.at(currentPlayIndex-1).id)+".jpg";
                ui->Soaring_cover_1->setPixmap(pix2.scaled(250,250));
            }
            else{
                int index=Soar->SoarList.size()-1;
                QPixmap pix1="D:\\qt\\MusicPlayer\\Soar_pic\\"+QString::number(Soar->SoarList.at(index).id)+".jpg";
                ui->Soaring_cover_1->setPixmap(pix1.scaled(250,250));
                QPixmap pix2="D:\\qt\\MusicPlayer\\Soar_pic\\"+QString::number(Soar->SoarList.at(currentPlayIndex+1).id)+".jpg";
                ui->Soaring_cover_2->setPixmap(pix2.scaled(250,250));
                qDebug()<<currentPlayIndex;
            }
        }
        else{
            QPixmap pix1="D:\\qt\\MusicPlayer\\Soar_pic\\"+QString::number(Soar->SoarList.at(currentPlayIndex-1).id)+".jpg";
            ui->Soaring_cover_1->setPixmap(pix1.scaled(250,250));
            QPixmap pix2="D:\\qt\\MusicPlayer\\Soar_pic\\"+QString::number(Soar->SoarList.at(currentPlayIndex+1).id)+".jpg";
            ui->Soaring_cover_2->setPixmap(pix2.scaled(250,250));
        }
        Animation();
    }
    //本地
    else if(currentFlag==2){
        ui->songname->setText(ui->listWidget->currentItem()->text());
        QPixmap pix(":/image_/picture.png");
        ui->lyrics_view->setIconSize(QSize(70,70));
        ui->lyrics_view->setIcon(pix);
    }
    else if(currentFlag==3){
        if(Like.empty()){
            return;
        }
        ui->songname->setText(Like.at(currentPlayIndex).songname);
        CoverBtnPath="D:\\qt\\MusicPlayer\\cover\\"+QString::number(Like.at(currentPlayIndex).hash)+".jpg";
        QPixmap pix=CoverBtnPath;
        ui->lyrics_view->setIconSize(QSize(70,70));
        ui->lyrics_view->setIcon(pix);
    }
    //背景切换
    setBackGround();
}


//动画
void Widget::Animation(){
    if(animation.state()==QPropertyAnimation::Running){
        return;
    }
    animation.setTargetObject(ui->Soaring_cover);
    animation.setPropertyName("geometry");
    // 设置动画的持续时间（毫秒）
    animation.setDuration(1000);
    // 设置动画的起始和结束值
    animation.setStartValue(QRect(0,0, 50, 50));
    animation.setEndValue(QRect(310, 60, 250, 250));
    // 设置动画的缓和曲线，使过渡更加平滑
    animation.setEasingCurve(QEasingCurve::OutElastic);
    // 开始动画
    if(animation.state()==QPropertyAnimation::Stopped){
        animation.start();
    }

}

void Widget::AnimationViewBtn(){
    if(animationViewBtn.state()==QPropertyAnimation::Running){
        return;
    }
    animationViewBtn.setTargetObject(ui->lyrics_view);
    animationViewBtn.setPropertyName("geometry");
    // 设置动画的持续时间（毫秒）
    animationViewBtn.setDuration(800);
    // 设置动画的起始和结束值
    animationViewBtn.setStartValue(QRect(550,350, 1, 1));
    animationViewBtn.setEndValue(QRect(60, 580, 80, 80));
    // 设置动画的缓和曲线，使过渡更加平滑
    animationViewBtn.setEasingCurve(QEasingCurve::OutElastic);
    // 开始动画
    if(animationViewBtn.state()==QPropertyAnimation::Stopped){
        animationViewBtn.start();
    }
}


bool Widget::isSongValid(const QString &songPath) {
    QFileInfo check_file(songPath);
    // 检查文件是否存在且可读
    return check_file.exists() && check_file.isReadable();
}
//切换账号
void Widget::on_reLogin_clicked()
{
    QString styleSheet="QMessageBox {"
                         "background-color: #4096EE;"
                         "border:none; "
                         "}"
                         "QLabel {"
                         "color: white;"
                         "font-size: 14px;"
                         "}"
                         "QPushButton {"
                         "background-color: #FFA500;"
                         "border: none;"
                         "color: white;"
                         "font-size: 14px;"
                         "padding: 5px 10px;"
                         "}"
                         "QPushButton:hover {"
                         "background-color: #FF8C00;"
                         "}"
                         "QPushButton:pressed {"
                         "background-color: #FF7F00;"
                         "}";
    QMessageBox msgBox;
    msgBox.setStyleSheet(styleSheet);
    msgBox.setWindowTitle("账号");
    msgBox.setText("确定重新登录？");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Ok);

    int result = msgBox.exec();
    if (result == QMessageBox::Ok) {
        if(mediaplayer->playbackState()==QMediaPlayer::PlayingState){
            mediaplayer->stop();
        }
        Login *L = new Login();
        L->show();
        this->close();
    } else {
        return;
    }
}

void Widget::playState(){
    if(mediaplayer->playbackState()==QMediaPlayer::PlayingState){
        ui->pushButton_2->setStyleSheet("image :url(:/star)");
        if(currentFlag==1){
            ui->star->setStyleSheet("image :url(:/star)");
        }
    }
    else if(mediaplayer->playbackState()==QMediaPlayer::StoppedState){
        ui->pushButton_2->setStyleSheet("image :url(:/pause)");
        if(currentFlag==1){
            ui->star->setStyleSheet("image :url(:/pause)");
        }
    }
    else{
        ui->pushButton_2->setStyleSheet("image :url(:/star)");
        if(currentFlag==1){
            ui->star->setStyleSheet("image :url(:/star)");
        }
    }
}

//喜欢
void Widget::on_tableWidget_cellClicked(int row, int column)
{
    QPixmap pix1(":/image_/dislike.png");
    QPixmap pix2(":/image_/like.png");
    QLabel *label1=new QLabel(this);
    qDebug()<<row;
    qDebug()<<like.size();
    if(column==4){
        if(row>=0&&row<=like.size()-1){
            //like
            if(like.at(row)==0){
                like.replace(row,1);
                label1->setPixmap(pix2);
                likeChange(row,1);

            }
            //dislike
            else if(like.at(row)==1){
                like.replace(row,0);
                label1->setPixmap(pix1);
                likeChange(row,0);

            }
            label1->setMaximumSize(60,60);
            label1->setScaledContents(true);
            ui->tableWidget->setCellWidget(row,4,label1);
        }
        else{
            qDebug()<<"out of range";
        }
    }

}

//改变like
void Widget::likeChange(int row,int flag){
    LikeList L;
    L.hash=m_listResult.at(row).hash;
    L.duration=m_listResult.at(row).duration;
    L.picUrl=m_listResult.at(row).picUrl;
    L.play_url=m_listResult.at(row).U;
    L.singername=m_listResult.at(row).singername;
    L.songname=m_listResult.at(row).songname;
    bool F=true;
    if(flag){
        for(int i=0;i<Like.size();i++){
            if(L.hash==Like.at(i).hash){
                F=false;
                break;
            }
        }
        if(F){
            Like.append(L);
            qDebug()<<"插入Like";
        }

    }
    else{
        for(int i=0;i<Like.size();i++){
            if(L.hash==Like.at(i).hash){
                Like.removeAt(i);
                qDebug()<<"从Like删除";
                break;
            }
        }
    }
}

//插入数据库
void Widget::updateLike(int ID){
    QSqlQuery query;
    for(int i=0;i<Like.size();i++){
        //hash int,picUrl VARCHAR(255),playUrl VARCHAR(255),singername VARCHAR(255),songname VARCHAR(255),duration int
        QString createTableQuery ="INSERT INTO t"+QString::number(ID)+" (hash,picUrl,playUrl,singername,songname,duration) VALUES (:hash,:picUrl,:playUrl,:singername,:songname,:duration);";
        query.prepare(createTableQuery);
        query.bindValue(":hash",Like.at(i).hash);
        query.bindValue(":picUrl",Like.at(i).picUrl);
        query.bindValue(":playUrl",Like.at(i).play_url);
        query.bindValue(":singername",Like.at(i).singername);
        query.bindValue(":songname",Like.at(i).songname);
        query.bindValue(":duration",Like.at(i).duration);
        if (query.exec()) {
            qDebug() << "插入成功";
        } else {
            qDebug() << "插入失败：" << query.lastError();
        }
    }
}
//从数据库插入Like
void Widget::insertLike(){
    Like.clear();
    QSqlQuery query;
    QString selectQuery = "SELECT * FROM t"+QString::number(userID)+";";
    query.exec(selectQuery);
    LikeList L;
    while(query.next()){
        L.hash=query.value("hash").toInt();
        L.duration=query.value("duration").toInt();
        L.picUrl=query.value("picUrl").toString();
        L.play_url=query.value("playUrl").toString();
        L.singername=query.value("singername").toString();
        L.songname=query.value("songname").toString();
        Like.append(L);
    }
}

//Like更新
void Widget::on_LikeUpDate_clicked()
{
    ui->LikeState->show();
    SGIF->start();
    ui->LikeUpDate->setEnabled(false);
    while(ui->tableWidget_2->rowCount()){
        ui->tableWidget_2->removeRow(0);
    }
    lrcCount=0;
    setLikePic=true;
    updateLike(userID);
    insertLike();
    qDebug()<<Like.size();
    for(int row=0; row<Like.size(); row++)
    {
        QFont font("黑体",15,10);
        font.setBold(true);
        LikeList info = Like.at(row);
        ui->tableWidget_2->insertRow(row);
        QTableWidgetItem *item=new QTableWidgetItem(info.songname);
        item->setFont(font);
        ui->tableWidget_2->setItem(row, 1,item);
        ui->tableWidget_2->setItem(row, 2, new QTableWidgetItem(info.singername));
        int Time=info.duration/1000;
        QString time=QString("%1:%2").arg(Time/60).arg(Time%60);
        ui->tableWidget_2->setItem(row, 3, new QTableWidgetItem(time));
        ui->tableWidget_2->setRowHeight(row, 100);
    }
    ui->tableWidget_2->horizontalHeader()->setFixedHeight(30);
    ui->tableWidget_2->setColumnWidth(0,80);
    ui->tableWidget_2->setColumnWidth(1,400);
    ui->tableWidget_2->setColumnWidth(2,200);
    for(int i=0;i<Like.size();i++){
        QPixmap pix(":/image_/like.png");
        QLabel *label1=new QLabel();
        label1->setPixmap(pix);
        label1->setMaximumSize(60,60);
        label1->setScaledContents(true);
        ui->tableWidget_2->setCellWidget(i,4,label1);
        lyric(i);
    }
    setpicture();
    ui->LikeUpDate->setEnabled(true);
    ui->LikeState->hide();
    SGIF->stop();
}


void Widget::on_tableWidget_2_cellDoubleClicked(int row, int column)
{

    if(column==0){
        currentFlag=3;
        currentPlayIndex=row;
        for(int i=0;i<ui->listWidget->count();i++){
            ui->listWidget->takeItem(i);
        }
        ui->listWidget->clear();
        playlist.clear();
        for(int i=0;i<Like.size();i++){
            QString hash=QString::number(Like.at(i).hash);
            QUrl url="https://music.163.com/song/media/outer/url?id="+hash+".mp3";
            playlist.append(url);
            //qDebug()<<url;
            ui->listWidget->insertItem(i,QString::number(i+1)+"、"+Like.at(i).songname+"  "+Like.at(i).singername);
            ui->listWidget->setCurrentRow(row);
        }
        mediaplayer->setSource(playlist[row]);
        audioOutput->setVolume(0.5);
        ui->pushButton_2->setStyleSheet("image :url(:/star)");
        ui->songname->setText(Like.at(row).songname);
        QPixmap pix="D:\\qt\\MusicPlayer\\cover\\"+QString::number(Like.at(row).hash)+".jpg";
        ui->lyrics_view->setIconSize(QSize(70,70));
        ui->lyrics_view->setIcon(pix);
        mediaplayer->play();
        GIF->start();
        GIF1->start();
        lyricsDate();
        qDebug()<<"音乐播放";
    }
    else{
        return;
    }
}




void Widget::on_pushButton_4_clicked()
{
    switchpage();
}


void Widget::on_pushButton_12_clicked()
{
    QString value = this->ui->textEdit->toPlainText();
    SparkDemo demo;
    QString answer = demo.call(value);
    this->ui->textBrowser_2->setText(answer);
}

