#include "track.h"

Track::Track()
{

}

void Track::SetTitle(QString title)
{
    this->Title = title;
}

void Track::SetArtist(QString Artist)
{
    this->Artist=Artist;
}

void Track::SetTrackNumber(int32_t TrackNumber)
{
    this->TrackNumber = TrackNumber;
}

void Track::SetPath(QString path)
{
    this->Path = path;
}

QString Track::GetPath()
{
    return this->Path;
}

QString Track::GetTitle()
{
    return this->Title;
}

QString Track::GetArtist()
{
    return this->Artist;
}

int32_t Track::GetTrackNumber() const
{
    return this->TrackNumber;
}

QVariantMap Track::toVariantMap()
{
    QVariantMap map;
    map.insert("Title", QVariant(this->Title));
    map.insert("Artist", QVariant(this->Artist));
    map.insert("TrackNumber", QVariant(this->TrackNumber));
    return map;

}

QJsonObject Track::toJsonObject()
{
    QJsonObject Obj;
    Obj.insert("Title", QJsonValue(this->Title));
    Obj.insert("Artist", QJsonValue(this->Artist));
    Obj.insert("TrackNumber", QJsonValue(this->TrackNumber));
    return Obj;
}


