#ifndef LYRICS_H
#define LYRICS_H
#include <QWidget>
#include <QString>
#include <QMap>
#include <QFile>
#include <QDebug>
#include <QList>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
class Lyrics
{

public:
    Lyrics();
    Lyrics(QString lyricsPath);
    bool readLyricsFile(QString lyricsPath);
    bool analysisLyricsFile(QString line);
    QList<QString> getListLyricsText() const;
    QList<int> getListLyricsTime() const;
    QString lyricsPath;
    QList<QString> listLyricsText;
    QList<int> listLyricsTime;
};

#endif // LYRICS_H
