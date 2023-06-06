#include <QApplication>
#include "welcomewindow.h"
#include "musicplayer.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MusicPlayer* music = new MusicPlayer();

    music->playBackgroundWelcomeWindowMusic();

    WelcomeWindow welcomeWindow(300, music);

    return app.exec();
}
