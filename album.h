#ifndef ALBUM_H
#define ALBUM_H

#include <QString>
#include "track.h"
#include <QJsonObject>
#include <QList>



class Album
{
public:
    Album();
    void SetArtist( QString Artist);
    void SetTitle(QString Title);
    void AddTrack(Track track);
    Track GetTrack(int32_t index);
    QString GetTitle();
    int32_t GetSize();
    QVariantMap toVariantMap();
    QJsonObject toJsonObject();
    QString Artist;
    void Sort();
    //void SetCatalog(Catalog catalog);

    //bool TrackLessThan(const Track &Track1, const Track &Track2) const;
    QJsonObject toJsonObject(int32_t ID);
    bool operator==(Album album);


private:
    //Catalog _Catalog;
    QString Title;
    //Track *Tracks[1000];
    QList<Track> Tracks;
    int32_t CurrentPosition = 0;

};

#endif // ALBUM_H
