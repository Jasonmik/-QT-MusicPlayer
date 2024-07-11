#ifndef SOARING_LIST_H
#define SOARING_LIST_H
#include<QNetworkReply>
#include<QTimer>
#include<QNetworkAccessManager>
#include<QNetworkRequest>
#include <QWidget>

class Soaring_list :public QWidget
{
public:
    Soaring_list();
    QNetworkAccessManager* Soaring_manager;
    QNetworkRequest *Soaring_request;
    QNetworkAccessManager* Soaring_pic_manager;
    QNetworkRequest *Soaring_pic_request;
    QNetworkAccessManager *lrc_manager;
    QNetworkRequest *lrc_request;
    void Soaring_songs();
    void Soaring_json(QString json);
    void Soaring_pic();
    void lrc_json(QString json);
    void lyric(int i);
    void round();
    bool isSongValid(const QString &songPath);
    struct Soar{
        QString picUrl;
        QString url;
        QString name;
        QString auther;
        int id;
    };
    QList<Soar> SoarList;
private slots:
    void Soaring_songs_finished(QNetworkReply *reply);

    void Soaring_pic_finished(QNetworkReply *reply);

     void lrc_Finished(QNetworkReply *reply);
private:
    int Count=0;
    int lrcCount=0;
};

#endif // SOARING_LIST_H
