#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWebView>
#include <QWebFrame>
#include <string>
#include <QDirIterator>
#include <taglib/taglib.h>
#include <taglib/fileref.h>
#include <unistd.h>
#include <album.h>
#include <track.h>
#include <QVariantMap>
#include <QVariantList>
#include <QJsonObject>
#include <QJsonDocument>
#include <QWebInspector>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    _videoWidget = new QFrame(this);


    ui->setupUi(this);
    //std::string js (ui->webView->settings()-> == 1 ? "Habilitado" : "Deshabilitado");
    //qDebug( js.c_str());
    //ui->webView->settings()->
    //ui->webView->page()->mainFrame()->connect(ui->webView->page()->mainFrame()->javaScriptWindowObjectCleared, this->on_javaScriptWindowObjectCleared);
    QObject::connect(ui->webView->page()->mainFrame(), SIGNAL(javaScriptWindowObjectCleared()),this, SLOT(on_javaScriptWindowObjectCleared()));
    QObject::connect(&this->Cola, SIGNAL(TrackAdded(Track)),this, SLOT(OnTrackAdded(Track)) );
    this->ui->webView->page()->settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
    this->Poller = new QTimer();
    QObject::connect(this->Poller, SIGNAL(timeout()), this, SLOT(CheckPlayer()));
    this->Poller->start(100);

    //frame-
    //frame->addToJavaScriptWindowObject("QObj", _videoWidget);
    //frame->addToJavaScriptWindowObject("Statusbar", ui->statusbar);
    //frame->addToJavaScriptWindowObject("WindowObj", this);


    this->JukeboxCatalog = new Catalog();
    QWebInspector *i = new QWebInspector(this);
    this->dlg = new QDialog(this);
    dlg->setLayout(new QVBoxLayout());
    dlg->resize(800, 600);
    dlg->layout()->addWidget(i);
    dlg->setModal(false);
    dlg->show();
    dlg->raise();
    dlg->activateWindow();
    i->setPage(this->ui->webView->page());
    i->setVisible(true);
    i->show();
    i->update();

    //ui->webView->load(QUrl(QString("http://localhost/Rockola")));
    ui->webView->load(QUrl("qrc:/Resources/index.html"));
    //this->SearchMusic();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddTrackToQueue(int AlbumID, int TrackID)
{
    qDebug() << "Añadiendo track";
    if(this->JukeboxCatalog->GetSize() -1 < AlbumID || this->JukeboxCatalog->GetAlbum(AlbumID).GetSize() -1 < TrackID){
        qDebug() << "Requested album " << AlbumID << "/"<< this->JukeboxCatalog->GetSize() -1;
        //<< "\t RequestedTrack " << TrackID << "/"  << this->JukeboxCatalog->GetAlbum(AlbumID).GetSize() -1;
        return;
    }
    Track track = this->JukeboxCatalog->GetAlbum(AlbumID).GetTrack(TrackID);
    qDebug() << track.GetTitle();
    this->Cola.AddTrack(track);
}

void MainWindow::SkipSong()
{
    if(this->IsPlaying()){
        libvlc_media_player_stop(this->_media_player);
    }
}

void MainWindow::on_webView_loadFinished(bool arg1)
{
    if(arg1){
    ui->statusbar->showMessage(QString("Cargado"));
    }


    //ui->webView->

}

void MainWindow::on_webView_loadStarted()
{
    ui->statusbar->showMessage(QString("Iniciando..."));
}

void MainWindow::on_javaScriptWindowObjectCleared()
{
    ui->webView->page()->mainFrame()->addToJavaScriptWindowObject("WindowObj", this);
    //ui->webView->page()->mainFrame()->addToJavaScriptWindowObject("Catalog", this->JukeboxCatalog);
}

bool MainWindow::IsPlaying()
{
    if(this->_vlc_instance == NULL){
        //qDebug() << "No VLC instance";
        return false;
    }
    if(this->_media_player == NULL){
        qDebug() << "No MediaPlayer instance";
        return false;
    }
    return libvlc_media_player_is_playing(this->_media_player);
}

void MainWindow::Play(Track track)
{
    qDebug() << "Trying to play " << track.GetTitle();
    this->Poller->stop();
    if(this->_vlc_instance == NULL){

        qDebug() << "Creating VLC instance";
        this->_vlc_instance = libvlc_new(0, NULL);
        qDebug() << "VLC instance created";
    }
    //this->Poller->start(100);
    /*
        if(this->_media_player == NULL){
            libvlc_media_t *media = libvlc_media_new_path(this->_vlc_instance, track.GetPath().toStdString().c_str());
            this->_media_player = libvlc_media_player_new_from_media(media);
            //this->_media_player->
            libvlc_media_player_play(this->_media_player);
        }else{

            if(!libvlc_media_player_is_playing(this->_media_player)){
                libvlc_media_t *media = libvlc_media_new_path(this->_vlc_instance, track.GetPath().toStdString().c_str());
                //this->_media_player = libvlc_media_player_new_from_media(media);
                libvlc_media_player_set_media(media);
                libvlc_media_player_play(this->_media_player);
            }
        }
        */
    if(this->_media_player == NULL){
        qDebug() << "Creating MediaPlayer instance";
        this->_media_player = libvlc_media_player_new(this->_vlc_instance);
    }
    if(!libvlc_media_player_is_playing(this->_media_player)){
        qDebug() << "Creating <media> instance";
        libvlc_media_t *media = libvlc_media_new_path(this->_vlc_instance, track.GetPath().toStdString().c_str());
        libvlc_media_player_set_media(this->_media_player, media); //this->_me
        qDebug() << "Trying to play!";
        libvlc_media_player_play(this->_media_player);
    }
    this->Poller->start(100);
}

void MainWindow::SetMessage(QString msg)
{
    qDebug()<< "SetMessage";
    qDebug() << msg;
    ui->statusbar->showMessage(msg);
    ui->statusbar->update();
}

void MainWindow::SearchMusic(QString path)
{
    /*
    QDirIterator dirIterator(path, QDirIterator::NoIteratorFlags);
    while(dirIterator.hasNext()){
        QFileInfo DirInfo = dirIterator.fileInfo();

        if(DirInfo.isDir() && DirInfo.fileName() != ".." && DirInfo.fileName() != "."){
            QString Artista = DirInfo.fileName();
            qDebug() << "Artista: " << Artista;
            QDirIterator ArtistIterator(DirInfo.absoluteFilePath(), QDirIterator::NoIteratorFlags);
            while(ArtistIterator.hasNext()){
                QFileInfo albumInfo = ArtistIterator.fileInfo();

                if(albumInfo.isDir() && albumInfo.fileName() != "."){
                    qDebug() << "Album: "  << albumInfo.fileName();
                    Album album;//= new Album();
                    album.SetArtist(Artista);
                    album.SetTitle(ArtistIterator.fileName() );
                    QDirIterator AlbumIterator(ArtistIterator.filePath(), QDirIterator::NoIteratorFlags);
                    while(AlbumIterator.hasNext()){
                        QFileInfo TrackInfo = AlbumIterator.fileInfo();
                        if(TrackInfo.suffix() == "mp3"){
                            Track * track = new Track();
                            TagLib::FileRef ref(TrackInfo.absoluteFilePath().toStdString().c_str());

                            track->SetTitle(QString(ref.tag()->title().toCString()));
                            track->SetTrackNumber(ref.tag()->track());
                            album.AddTrack(track);
                        }
                        AlbumIterator.next();
                    }
                    this->JukeboxCatalog->AddAlbum(album);
                }

                ArtistIterator.next();
            }
        }
        dirIterator.next();
    }*/
    qDebug() << path;
    QDir CatalogDir(path);
    CatalogDir.setSorting(QDir::Name);
    CatalogDir.setFilter(QDir::AllDirs| QDir::NoDotAndDotDot);
    QStringList ArtistNames = CatalogDir.entryList();
    foreach(QString artistName, ArtistNames){
        qDebug() << artistName;
        QString ArtistPath = path + "/" + artistName;
        QDir ArtistDir(ArtistPath);
        ArtistDir.setSorting(QDir::Name);
        ArtistDir.setFilter(QDir::AllDirs|QDir::NoDotAndDotDot);
        QStringList AlbumNames = ArtistDir.entryList();
        foreach(QString albumName, AlbumNames){
            qDebug() << "\t" <<  albumName;
            QString AlbumPath = ArtistPath + "/" + albumName;
            Album album;
            album.SetArtist(artistName);
            album.SetTitle(albumName);
            QDirIterator AlbumIterator(AlbumPath, QDirIterator::NoIteratorFlags);
            while(AlbumIterator.hasNext()){
                QFileInfo TrackInfo = AlbumIterator.fileInfo();
                qDebug() << "\t\t" << TrackInfo.completeBaseName();
                if(TrackInfo.suffix() == "mp3"){
                    Track track;// = new Track();
                    TagLib::FileRef ref(TrackInfo.absoluteFilePath().toStdString().c_str());

                    track.SetTitle(QString::fromStdWString(ref.tag()->title().toWString()));
                    track.SetTrackNumber(ref.tag()->track());
                    track.SetPath(TrackInfo.absoluteFilePath());
                    album.AddTrack(track);
                }
                AlbumIterator.next();
            }
            album.Sort();
            this->JukeboxCatalog->AddAlbum(album);
            //qSort()
        }
    }

    this->ui->statusbar->showMessage(QString("Catalogo listo"));
}

QString MainWindow::GetCatalog()
{
    //return this->JukeboxCatalog;
    QJsonDocument jsDoc;
    jsDoc.setObject(this->JukeboxCatalog->ToJsonObject());
    QString JSON = jsDoc.toJson();
    qDebug() << JSON;
    return JSON;
    /*
    try{


        qDebug() << "GetCatalog";
        QList<QVariantMap> catalog = this->JukeboxCatalog->ToList();
        qDebug() << "Lista creada";
        QVariantMap map;// = new QVariantMap;
        map.insert("Albums", QVariant::fromValue(catalog));
        qDebug() << "VariantMap creado";
        //QJsonArray _jsArr = QJsonArray::from
        QJsonObject _jsonObj = QJsonObject::fromVariantMap(map);
        qDebug() << "JsonObject creado";

    QJsonDocument _jsDoc;
    _jsDoc.setObject(_jsonObj);
    qDebug() << _jsDoc.toJson();
    //return _jsDoc.

        //return map;
    return this->JukeboxCatalog;
    }catch(std::exception ex){
        qDebug() << ex.what();
    }
*/

    //_jsonObj.
    /*
    QVariantList Albums;// = new QVariantList;
    for(int albumIndex = 0; albumIndex<= this->JukeboxCatalog->GetSize(); albumIndex++ ){
        QVariantMap albumMap;// = new QVariantMap;
        Album *album = this->JukeboxCatalog->GetAlbum(albumIndex);
        //QVariant title(album->GetTitle());
        albumMap.insert("Title", QVariant(album->GetTitle()));
        //QVariantList Tracks = new QVariantList();
        QList<QVariantMap> Tracks;
        for(int trackIndex = 0; trackIndex <= album->GetSize(); trackIndex++){
            Track *track = album->GetTrack(trackIndex);
            QVariantMap trackInfo;// = new QVariantMap;
            trackInfo.insert("Title", QVariant(track->GetTitle()));
            trackInfo.insert("TrackNumber", QVariant(track->GetTrackNumber()));

            Tracks.append(trackInfo);
        }
        albumMap.insert("Tracks", Tracks);
        //Albums.append(albumMap);
    }
    */

    /*
    QVariantList Albums;
    for(int32_t albumIndex = 0; albumIndex < this->JukeboxCatalog->GetSize(); albumIndex++ ){
        QVariantMap *albumMap = new QVariantMap;

    }
*/

    //QVariantList Albums;
    //return Albums;

}

void MainWindow::OnTrackAdded(Track track)
{
    qDebug() << "Slot reached!";
    qDebug() << track.GetPath();
    /*
    if(this->_vlc_instance != NULL){
        if(this->_media_player != NULL){
            if(libvlc_media_player_is_playing(this->_media_player)){
                return;
            }
        }
    }else{
    this->_vlc_instance = libvlc_new(0, NULL);
    libvlc_media_t *media = libvlc_media_new_path(this->_vlc_instance, track.GetPath().toStdString().c_str());
    this->_media_player = libvlc_media_player_new_from_media(media);
    //this->_media_player->
    libvlc_media_player_play(this->_media_player);
    }
    */
    if(this->IsPlaying()){
        return;
    }
    this->Play(track);
}



void MainWindow::CheckPlayer()
{
    if(IsPlaying()){
        return;
    }
    if(this->Cola.TracksPending()){
        Track track = this->Cola.NextTrack();

        this->Play(track);

    }
    //this->OnTrackAdded(track);
}



