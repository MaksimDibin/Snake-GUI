
#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QString>
#include <QTimer>
#include <QPainter>
#include <chrono>
#include <thread>
#include "welcomewindow.h"
#include "styledwidget.h"
#include "musicplayer.h"

using namespace std;

class GameOver : public StyledWidget
{

public:
   explicit GameOver(const int delay, MusicPlayer *music = nullptr, StyledWidget *parent = nullptr);
    ~GameOver();

protected:
    void paintEvent(QPaintEvent *event);

private slots:
    void showNextLetter();

private:
    static const int DELAY_GAME_OVER_STR = 150;
    const QString GAME_OVER_STR = "Game Over";

    WelcomeWindow *welcomeWindow;
    MusicPlayer *_music;

    int current_letter_index_ = 0;
    int delay_;
};

#endif // GAMEOVER_H
