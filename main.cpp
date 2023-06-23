#include <QApplication>
#include "musicplayer.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MusicPlayer* music = new MusicPlayer();
    
    music->playBackgroundFunMusic();

    MainWindow mainWindow(300, music);
    mainWindow.show();

    return app.exec();
}
