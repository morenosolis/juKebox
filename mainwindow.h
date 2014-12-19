#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFrame>
#include <vlc/libvlc.h>
#include <vlc/libvlc_media.h>
#include <vlc/libvlc_media_player.h>
#include "catalog.h"
#include "queue.h"
#include <QDialog>
#include <QTimer>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Q_INVOKABLE void AddTrackToQueue(int AlbumID, int TrackID);
    Q_INVOKABLE void SkipSong();
private slots:
    void on_webView_loadFinished(bool arg1);

    void on_webView_loadStarted();
    void on_javaScriptWindowObjectCleared();
private:
    Ui::MainWindow *ui;
    QFrame *_videoWidget;
    libvlc_instance_t* _vlc_instance = NULL;
    libvlc_media_player_t * _media_player = NULL;
    Catalog *JukeboxCatalog;
    QDialog *dlg;
    Queue Cola;
    QTimer *Poller;
    bool IsPlaying( );
    void Play(Track track);

public slots:
    Q_INVOKABLE void SetMessage(QString);
    Q_INVOKABLE void SearchMusic(QString path);
    Q_INVOKABLE QString GetCatalog();
    void OnTrackAdded(Track track);
    void CheckPlayer();
};

#endif // MAINWINDOW_H
