#include <QApplication>

#include "mainwindow.h"
int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    MainWindow main;
    main.showFullScreen();
    /*
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    */
    return app.exec();
}
