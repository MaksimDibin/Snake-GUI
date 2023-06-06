
#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QKeyEvent>
#include <QPainter>
#include <QTime>
#include <random>
#include <QList>
#include "gameover.h"
#include "styledwidget.h"
#include "musicplayer.h"

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
    explicit GameWindow(const int delay, MusicPlayer *music = nullptr, StyledWidget *parent = nullptr);
    ~GameWindow();
    void start();

private:
    QImage i_mouse;
    QImage snakeBody;
    QImage snakeHeadUp;
    QImage snakeHeadDown;
    QImage snakeHeadLeft;
    QImage snakeHeadRight;

    GameOver *gameOver;
    MusicPlayer *_music;

    static const int OBJECT_SIZE = 30;
    static const int HEIGHT = 600;
    static const int WIDTH = 600;
    int delay_;

    QMap<Move, QImage> headMap;

    Move current = UP_DIRECTION;

    int timerID;

    QPoint head;
    QPoint tail;
    QPoint mouse;
    QList<QPoint> dots;

    bool isGameOver = false;

    void paintEvent(QPaintEvent * pe);
    void timerEvent(QTimerEvent * te);
    void keyPressEvent(QKeyEvent * ke);

    void moveHead();
    void moveTail();
    void loadImages();
    void locateMouse();
    void checkMouse();
    void checkCollision();
};

#endif // GAMEWINDOW_H
