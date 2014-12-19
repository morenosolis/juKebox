#ifndef CATALOG_H
#define CATALOG_H

#include "album.h"
#include <QList>
#include <QJsonObject>
class Catalog
{

public:
    Catalog();
    Album GetAlbum(int32_t index);
    void AddAlbum(Album album);
    Q_INVOKABLE int32_t GetSize();
    //QList<QVariantMap> ToList();
    QJsonObject ToJsonObject();
    int32_t GetAlbumPosition(Album album);
    void Sort();
private:
    //Album *Albums[5000];
    QList<Album> Albums;
    int32_t CurrentAlbum = 0;



};

#endif // CATALOG_H
