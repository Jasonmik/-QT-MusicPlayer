#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QUrl>
#include<QPaintEvent>
#include<QMovie>
#include<QListWidgetItem>
#include "lyrics.h"
#include "soaring_list.h"
#include "database.h"
#include<QNetworkAccessManager>
#include<QNetworkRequest>
#include<QThread>
#include<QPainter>
#include<QGraphicsBlurEffect>
#include <QPropertyAnimation>
class QMediaPlayer;
class QAudioOutput;
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(int id);
    ~Widget();
    void paintEvent(QPaintEvent* event);
    QPoint windowPos;
    QPoint mousePos;
    QPoint dPos;
    int num=2;
    bool pre;
    bool next;
    QMovie *GIF,*GIF1;
    QMovie *GIFB;
    QMovie *SGIF;
    QAction *del=new QAction("删除");
    //添加net成员
    //歌曲信息API
    QNetworkAccessManager * network_manager;
    QNetworkRequest * network_request;
    //picture
    QNetworkAccessManager * pic_manager;
    QNetworkRequest * pic_request;
    //歌词
    QNetworkAccessManager * lrc_manager;
    QNetworkRequest * lrc_request;
    //图片设置
    QNetworkAccessManager *setpic_manager;
    QNetworkRequest*  setpic_request;
    //Json数据保存
    struct findResult{
        int hash;//歌曲id
        QString songname;//歌曲名字
        QString singername;//歌手
        int duration;//时长
        int albumid;//图片
        QString picUrl;
        QUrl play_url;//MP3地址
        QString U;
    }stResultList;
    QList<findResult> m_listResult;
    QList<findResult> l_listResult;
    //LikeList
    struct LikeList{
        int hash;//歌曲id
        QString songname;//歌曲名字
        QString singername;//歌手
        int duration;//时长
        QString picUrl;//封面地址
        QString play_url;//MP3地址
    };
    QList<LikeList>Like;// 1 like 0 dislike
    QList<int>like;
    //QList<LikeList>Like_list;
    void ParseJson(QString json);
    int lrcCount=0;
    int picCount=0;
    //int picCountf=0;
    int setpicCount=0;
    bool setLikePic=false;
    QStringList lrcFile;
    //歌词
    QString strinput;
    QString strname;
    QString getcontains(QJsonObject Object, QString strInfo);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void PlayModeOrder();
    void PlayModeCirculate();
    void PlayModeRand();
    void PlayModeF();
    void setPlayTime();
    void lyricsDate();
    //table设置
    void style();
    //播放切换元素改变
    void changeElement();
    //页面切换
    void switchpage();
    //插入表格
    void insertItem();
    //net初始化
    void initNet();
    //图片
    void picture(int i);

    void pic_json(QString json);
    //歌词
    void lyric(int i);

    void lrc_json(QString json);
    //设置图片
    void setpicture();
    //背景
    void setBackGround();
    //设置图片圆角
    QPixmap round(const QPixmap& img_in, int radius);
    //animation
    void Animation();

    void AnimationViewBtn();

    //判断歌曲可读
    bool isSongValid(const QString &songPath);
    //播放状态
    void playState();
    //
    void likeChange(int row,int flag);
    //更新like
    void updateLike(int ID);
    //insertLike
    void insertLike();
private slots:
    //槽函数
    void replyFinished(QNetworkReply *reply);

    void lrc_Finished(QNetworkReply *reply);

    void pic_Finished(QNetworkReply *reply);

    void setpic_Finished(QNetworkReply *reply);

    void on_pushButton_8_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_5_clicked();

    void on_listWidget_doubleClicked(const QModelIndex &index);

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_volumeSlider_sliderMoved(int position);

    void on_pushButton_7_clicked();

    void on_listWidget_customContextMenuRequested(const QPoint &pos);

    void on_pushButton_9_clicked();

    void on_search_clicked();

    void on_List_of_lyrics_clicked();

    void on_Song_Search_clicked();

    void on_lyrics_view_clicked();

    void on_tableWidget_cellDoubleClicked(int row, int column);

    void on_pushButton_10_clicked();

    void on_fresh_clicked();

    void on_Song_Search_2_clicked();

    void on_star_clicked();

    void on_likeBtn_clicked();

    void on_reLogin_clicked();

    void on_tableWidget_cellClicked(int row, int column);

    void on_LikeUpDate_clicked();

    void on_tableWidget_2_cellDoubleClicked(int row, int column);

    void on_pushButton_4_clicked();

    void on_pushButton_12_clicked();

private:
    Ui::Widget *ui;
    QList<QUrl> playlist;//播放列表
    QAudioOutput *audioOutput;
    QMediaPlayer *mediaplayer;
    QString path;
    int currentPlayIndex=0;
    int positiontime=0;
    int Playmode=1;
    int playflag=0;
    Lyrics lyrics;
    int lyricsID=0;
    QListWidgetItem *aItem;
    QPainter painter;
    QGraphicsBlurEffect *blur_effect;
    int bkChange =3;
    int backchange=0;
    int onlyricsView=1;
    int coverFlag=0;
    Soaring_list *Soar;
    int currentFlag=-1;//0 搜索 1 飙升  2本地 3Like
    QPropertyAnimation animation;
    QPropertyAnimation animationViewBtn;
    QString CoverBtnPath="";//封面地址
    DataBase data;
    int userID;
};

#endif // WIDGET_H
