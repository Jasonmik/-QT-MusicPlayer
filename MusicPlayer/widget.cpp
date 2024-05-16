#pragma execution_character_set("utf-8")
#include "widget.h"
#include "ui_widget.h"
#include<QDebug>  //导入调试头文件
#include<QFileDialog>   //导入对话框头文件
#include<QDir>  //导入操作目录的一个类
#include <QtMultimedia/QMediaPlayer>  //播放音乐
#include<QAudioOutput> //输出音乐
#include<QUrl>
#include<QTimer>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer = new QTimer();  //创建一个定时器
    timer-> setInterval(2000);  //每隔两秒钟启动一次定时器事件
    timer-> start();

    QString fileName = "E:/Qt66/document/MusicPlayer/MusicPlay/music";
    QDir dir(fileName);
    m_playPath = fileName;
    //如何播放音乐 先导入multimedia模块
    //先new一个output对象
     audioOutput = new QAudioOutput(this);
    //再来一个媒体播放对象
     mediaPlayer = new QMediaPlayer(this);
    mediaPlayer->setAudioOutput(audioOutput);

    //获取当前媒体的时长 通过信号与槽来获取
    connect(mediaPlayer,&QMediaPlayer::durationChanged,this,[=](qint64 duration)
    {
        ui->totalLable->setText(QString("%1:%2").arg(duration/1000/60,2,10,QChar('0')).arg(duration/1000%60));
        //设置进度条
        ui->playCourseSlider->setRange(0,duration);

    });
    //获取当前播放时长
    connect(mediaPlayer,&QMediaPlayer::positionChanged,this,[=](qint64 pos)
    {
        ui->curLable->setText(QString("%1:%2").arg(pos/1000/60,2,10,QChar('0')).arg(pos/1000%60));
        //缓慢移动进度条
        ui->playCourseSlider->setValue(pos);

    });

    //拖动滑块，改变播放进度
    connect(ui->playCourseSlider,&QSlider::sliderMoved,mediaPlayer,&QMediaPlayer::setPosition);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_3_clicked()//展示歌曲目录
{
    //让用户打开文件对话框   让用户选择音乐
    auto path = QFileDialog::getExistingDirectory(this,"Select Music","E:/Qt66/document/MusicPlayer/MusicPlay/music");
    //qInfo()<<path;
    //根据路径获取mp3文件
    QDir dir(path);
    auto musicList = dir.entryList(QStringList()<<"*.mp3");
    //把音乐名字放到List展示
    ui->listWidget->addItems(musicList);

    //默认选中第一个音乐
    ui->listWidget->setCurrentRow(0);

    //把音乐完整路径保存起来
    for(auto file : musicList)
        playList.append(QUrl::fromLocalFile(path+"/"+file));
    //qInfo()<<playList;

}


void Widget::on_pushButton_8_clicked()  //switch实现暂停、播放状态
{
    //错误处理

    if(playList.empty()){
        return;
    }
    switch(mediaPlayer->playbackState()){
    case QMediaPlayer::PlaybackState::StoppedState:   //停滞状态
    {
        //如果没有播放，就播放当前选中的音乐
        //获取选中当前的序号
        curPlayindex = ui->listWidget->currentRow();
        //播放对应下标的音乐
        mediaPlayer->setSource(playList[curPlayindex]);
        mediaPlayer->play();
        break;
    }
    case QMediaPlayer::PlaybackState::PlayingState:  //播放状态
         //若在现在正在播放
        mediaPlayer->pause();
        break;
    case QMediaPlayer::PlaybackState::PausedState:   //暂停状态
        //如果现在是暂停
        mediaPlayer->play();
        break;
    }





  }


void Widget::on_pushButton_6_clicked()//上一曲
{
    curPlayindex = (curPlayindex-1)%playList.size();
    ui->listWidget->setCurrentRow(curPlayindex);
    mediaPlayer->setSource(playList[curPlayindex]);
    mediaPlayer->play();
}


void Widget::on_pushButton_7_clicked()//下一曲
{
    //让list选中下一行
    curPlayindex = (curPlayindex+1)%playList.size();
    ui->listWidget->setCurrentRow(curPlayindex);
    mediaPlayer->setSource(playList[curPlayindex]);
    mediaPlayer->play();
}


void Widget::on_listWidget_doubleClicked(const QModelIndex &index)//双击实现切歌
{
        curPlayindex = index.row();
        mediaPlayer->setSource(playList[index.row()]);
        mediaPlayer->play();
}


void Widget::on_pushButton_5_clicked()   //单击暂停
{
    mediaPlayer->pause();
}


QString Widget::settime(int time)  //将时间转化为正常格式
{
    int h,m,s;
    time /= 1000;  //获得的时间是以毫秒为单位的
    h = time/3600;
    m = (time-h*3600)/60;
    s = time-h*3600-m*60;
    return QString("%1:%2:%3").arg(h).arg(m).arg(s);
}

void Widget::setPlayTime()  //设置歌词显示时间   间断显示
{
    if(!lyrics.getListLyricsTime().empty()&&mediaPlayer->position()>=lyrics.getListLyricsTime().at(lyricsID)){
        ui->lblLyrics1->setText(lyrics.getListLyricsText().at(lyricsID));
        ui->lblLyrics2->setText(lyrics.getListLyricsText().at(lyricsID+1));
        lyricsID++;
    }
    ui->curLable->setText(settime(mediaPlayer->position()));
}


void Widget::on_verticalSlider_sliderMoved(int position)  //设置调节音量
{
    //mediaPlayer->setVolume(position);
}

void Widget::setSliderValue(){  //调节音量滑块
    ui->playCourseSlider->setValue(mediaPlayer->position()*100/mediaPlayer->duration());
    if(mediaPlayer->position()>=mediaPlayer->duration()){
        on_pushButton_7_clicked();
    }
}

void Widget::getduration(){   //获取当前演奏时长
    playtime = mediaPlayer->duration();
    ui->curLable->setText(settime(playtime));
}


void Widget::on_listWidget_itemDoubleClicked(QListWidgetItem *item)  //导入歌词文件
{
    m_PlayRow = ui->listWidget->row(item);
    mediaPlayer->stop();
    mediaPlayer->setSource(QUrl::fromLocalFile(m_playPath+"/"+item->text()));
    mediaPlayer->play();

    QString name = item->text().left(item->text().lastIndexOf("."));

    lyrics.readLyricsFile(m_playPath+"/"+name+".lrc");  //传入歌词文件名

        // ui->lblLyrics1->setText("未检测到歌词文件");
        // ui->lblLyrics2->setText("请检查歌词文件是否存在");
    QString::fromLocal8Bit("");
    qInfo()<<"6666"<<m_playPath+"/"+name+".lrc"<<"66666"<<name;
    lyricsID = 0;
    ui->playCourseSlider->setValue(mediaPlayer->position());

    connect(timer, SIGNAL(timeout()), this, SLOT(setSliderValue())); //获取qt框架中信号与槽机制之间的通信
    connect(mediaPlayer,SIGNAL(durationChanged(qint64)),this,SLOT(getduration())); //实现更新滑块时   歌词显示发生改变
    connect(mediaPlayer,SIGNAL(positionChanged(qint64)),this,SLOT(setPlayTime()));

}

