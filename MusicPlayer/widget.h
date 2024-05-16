#ifndef WIDGET_H
#define WIDGET_H
#pragma execution_character_set("utf-8")
#include <QWidget>
#include<QUrl>
#include <QtMultimedia/QMediaPlayer> // 包含头文件
#include <QTimer>
#include <QListWidgetItem>
#include <QString>
#include <QFileDialog>
#include <lyrics.h>
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class  QAudioOutput;
class  QMediaPlayer;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QString settime(int time);

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void setPlayTime();//判断歌词显示时间

    void on_listWidget_doubleClicked(const QModelIndex &index);

    void on_pushButton_5_clicked();

    void on_verticalSlider_sliderMoved(int position);

    void getduration();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void setSliderValue();
private:
    Ui::Widget *ui;

    QList<QUrl>playList; //播放列表
    int curPlayindex=0;//当前播放列表

    QAudioOutput* audioOutput;
    QMediaPlayer* mediaPlayer;
    QMediaPlayer *mp = new QMediaPlayer();
    QString m_playPath;
    QTimer *timer;//定时器
    Lyrics lyrics;

    int m_PlayRow;
    int playtime;
    int lyricsID = 0;
};
#endif // WIDGET_H
