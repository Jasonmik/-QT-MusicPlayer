#ifndef LYRICS_H
#define LYRICS_H

#pragma execution_character_set("utf-8")
#include <QWidget>
#include <QString>
#include <QMap>
#include <iostream>
#include <QFile>
#include <QDebug>
#include <QRegularExpression>
#include <QList>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
using namespace std;

class Lyrics
{

private:
    QString lyricsPath;
    QList<QString> listLyricsText;
    QList<int> listLyricsTime;
public:
    Lyrics(QString lyricsPath);
    Lyrics();
    bool readLyricsFile(QString lyricsPath);
    bool analysisLyricsFile(QString line);
    QList<QString> getListLyricsText() const;
    QList<int> getListLyricsTime() const;
};


#endif // LYRICS_H
