#ifndef QUEUE_H
#define QUEUE_H
#include <QList>
#include "track.h"
#include <QObject>
#include <QQueue>
class Queue : public QObject
{
    Q_OBJECT
public:
    Queue();
    void AddTrack(Track track);
    void RemoveTrack(Track track);
    Track NextTrack();
    bool TracksPending();
private:
    //QList<Track> Cola;
    QQueue<Track> Cola;

//public slots:

signals:
    void TrackAdded(Track track);
};

#endif // QUEUE_H
