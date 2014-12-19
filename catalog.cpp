#include "catalog.h"
#include <QJsonArray>
Catalog::Catalog()
{
}

Album Catalog::GetAlbum(int32_t index)
{
    /*
    if(index > CurrentAlbum){
        return NULL;
    }
    */
    return this->Albums.at(index);
}

void Catalog::AddAlbum(Album album)
{
    //this->Albums[CurrentAlbum] = album;
    this->Albums.append(album);

    //CurrentAlbum++;
}

int32_t Catalog::GetSize()
{
    return this->Albums.count();
    //return CurrentAlbum;
}
/*
QList<QVariantMap> Catalog::ToList()
{

    QList<QVariantMap> list;
    for(int i = 0; i< CurrentAlbum; i++){
        list.append(this->Albums[i]->toVariantMap());
    }
    return list;

    return this->Albums;
}
*/
QJsonObject Catalog::ToJsonObject()
{
    QJsonObject Obj;
    QJsonArray _Albums;
    /*
    for(int i = 0; i< CurrentAlbum; i++){
        _Albums.append(this->Albums[i]->toJsonObject());
    }
    */
    /*
    foreach (Album album, this->Albums) {
        _Albums.append(album.toJsonObject());
    }*/
    QListIterator<Album> albumIterator( this->Albums);
    while(albumIterator.hasNext()){
        Album alb= albumIterator.next();
        _Albums.append(alb.toJsonObject(this->Albums.indexOf(alb)));
    }
    Obj.insert("Albums", _Albums);
    return Obj;
}

int32_t Catalog::GetAlbumPosition(Album album)
{
    return this->Albums.indexOf( album);
}

void Catalog::Sort()
{

}
