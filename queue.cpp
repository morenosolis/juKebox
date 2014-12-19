#include "queue.h"

Queue::Queue()
{
}

void Queue::AddTrack(Track track)
{
    this->Cola.enqueue(track);
    emit TrackAdded(track);
}

void Queue::RemoveTrack(Track track)
{

}

Track Queue::NextTrack()
{
    /*
    if(this->Cola.isEmpty()){
        return NULL;
    }
    */
    Track track = this->Cola.dequeue();
    /*
    if(this->Cola.size() > 0){
        this->Cola.removeFirst();
    }
    */
    return track;


}

bool Queue::TracksPending()
{
    return !this->Cola.empty();
}
