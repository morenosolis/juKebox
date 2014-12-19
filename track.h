#ifndef TRACK_H
#define TRACK_H


#include <QString>
#include <QVariant>
#include <QJsonObject>

class Track
{
public:
    Track();
    void SetTitle(QString title);
    void SetArtist(QString Artist);
    void SetTrackNumber(int32_t TrackNumber);
    void SetPath(QString path);
    QString GetPath();
    QString GetTitle();
    QString GetArtist();
    int32_t GetTrackNumber() const;
    QVariantMap toVariantMap();
    QJsonObject toJsonObject();
private:
    QString Title;
    QString Artist;
    int32_t TrackNumber;
    QString Path;

};

#endif // TRACK_H
