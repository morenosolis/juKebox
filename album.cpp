#include "album.h"
#include "QDebug"
#include "QJsonArray"
#include "catalog.h"
Album::Album()
{

}

void Album::SetArtist(QString Artist)
{
    this->Artist = Artist;
}

void Album::SetTitle(QString Title)
{
    this->Title = Title;
}

void Album::AddTrack(Track track)
{
    //this->Tracks[CurrentPosition] = track;
    this->Tracks.append(track);
    CurrentPosition++;
}

Track Album::GetTrack(int32_t index)
{
    /*
    if(index > CurrentPosition){
        return NULL;
    }
    return this->Tracks[index];
    */
    return this->Tracks.at(index);
}

QString Album::GetTitle()
{
    return this->Title;
}

int32_t Album::GetSize()
{
    return this->Tracks.count();
}

QVariantMap Album::toVariantMap()
{
    QVariantMap map;
    // TODO: Limpiar este desmadre
    /*

    map.insert("Artist", QVariant(this->Artist));
    map.insert("Title", QVariant(this->Title));
    QList<QVariantMap> _Tracks;
    for(int i = 0; i < CurrentPosition; i++){
        _Tracks.append(this->Tracks[i]->toVariantMap());
    }
    //map.insert("Tracks", QVariant::fromValue(_Tracks));
    qDebug() << "B";
    QVariant qvList = QVariant::fromValue(_Tracks);
    qDebug() << "A";
    map.insert("Tracks", qvList);
    */
    return map;
}

QJsonObject Album::toJsonObject(int32_t ID){
    QJsonObject Obj;
    Obj.insert("Artist", QJsonValue(this->Artist));
    Obj.insert("Title", QJsonValue(this->Title));
    if(ID >= 0 ){
        Obj.insert("ID", QJsonValue(ID));
    }

    QJsonArray JsArr;
    /*
    for(int i = 0; i < CurrentPosition; i++){
        JsArr.append( this->Tracks[i]->toJsonObject());
    }
    */
    foreach(Track track, this->Tracks){
        JsArr.append( track.toJsonObject());
    }
    Obj.insert("Tracks", QJsonValue(JsArr));
    return Obj;
}

bool Album::operator==(Album album)
{
    return (this->Title == album.GetTitle() && this->Artist == album.Artist && this->Tracks.count() == album.Tracks.count());
}

QJsonObject Album::toJsonObject()
{
    return this->toJsonObject(-1);
}

bool TrackLessThan(const Track &Track1, const Track &Track2)
{
    return Track1.GetTrackNumber() < Track2.GetTrackNumber();
}

void Album::Sort()
{
    qSort(Tracks.begin(), Tracks.end(), TrackLessThan);
    //this->Tracks.

}



