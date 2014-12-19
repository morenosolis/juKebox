TEMPLATE = app

QT += core gui webkitwidgets
#qml quick widgets webkitwidgets

SOURCES += main.cpp \
    mainwindow.cpp \
    playlist.cpp \
    queue.cpp \
    catalog.cpp \
    album.cpp \
    track.cpp

RESOURCES += \
    qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    mainwindow.h \
    playlist.h \
    queue.h \
    catalog.h \
    album.h \
    track.h

FORMS += \
    mainwindow.ui

LIBS += -ltag -lvlc
CONFIG += c++11

TARGET = juKebox
