
#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QApplication>
#include <QKeyEvent>
#include <QPainter>
#include <QTime>
#include <random>
#include <QList>
#include <thread>
#include "gameover.h"
#include "styledwidget.h"
#include "musicplayer.h"
#include "score.h"

enum Move
{
    LEFT_DIRECTION,
    RIGHT_DIRECTION,
    UP_DIRECTION,
    DOWN_DIRECTION
};

class GameWindow : public StyledWidget
{
public:
    explicit GameWindow(const int delay, int choosingATopic = 0, bool musicIsPlay = true, MusicPlayer *music = nullptr, StyledWidget *parent = nullptr);
    ~GameWindow();
    void start();

private:
    QImage i_mouse;
    QImage mine;
    QImage snakeBody;
    QImage snakeHeadUp;
    QImage snakeHeadDown;
    QImage snakeHeadLeft;
    QImage snakeHeadRight;

    std::thread timerThread;

    GameOver *gameOver;
    MusicPlayer *_music;
    Score *score;

    static const int OBJECT_SIZE = 30;
    static const int HEIGHT = 600;
    static const int WIDTH = 600;

    bool _musicIsPlay;
    int _choosingATopic;
    int _delay;
    int defaultDelay;

    QMap<Move, QImage> headMap;

    Move current = UP_DIRECTION;

    int timerID;

    QPoint head;
    QPoint tail;
    QPoint mouse;
    QPoint p_mine;
    QList<QPoint> dots;

    bool isGameOver = false;

    void paintEvent(QPaintEvent * pe);
    void timerEvent(QTimerEvent * te);
    void keyPressEvent(QKeyEvent * ke);

    QPoint gettingCoordinates() const;

    void timer();
    void moveHead();
    void moveTail();
    void loadImages();
    void locateMouseAndMine();
    void checkMouse();
    void checkCollision();
};

#endif // GAMEWINDOW_H
