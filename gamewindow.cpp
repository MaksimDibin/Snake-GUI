#include "gamewindow.h"

GameWindow::GameWindow(const int delay, int choosingATopic, bool musicIsPlay, MusicPlayer *music, StyledWidget *parent) :
    StyledWidget(parent),
    _delay(delay),
    defaultDelay(delay),
    _music(music),
    _musicIsPlay(musicIsPlay),
    _choosingATopic(choosingATopic)
{
    score = new Score(this);

    score->checkDelay(delay);

    loadImages();

    headMap.insert(LEFT_DIRECTION, snakeHeadLeft);
    headMap.insert(RIGHT_DIRECTION, snakeHeadRight);
    headMap.insert(UP_DIRECTION, snakeHeadUp);
    headMap.insert(DOWN_DIRECTION, snakeHeadDown);

    head.setX(10);
    head.setY(10);

    dots.push_back(QPoint(10, 11));
    dots.push_back(QPoint(10, 12));

    locateMouseAndMine();

    setCursor(Qt::BlankCursor);

    setWindowFlags(Qt::FramelessWindowHint);

    timerID = startTimer(_delay);

    timerThread = std::thread(&GameWindow::timer, this);

    this->show();
}

GameWindow::~GameWindow()
{
    delete gameOver;
    delete _music;
    delete score;
}

void GameWindow::paintEvent(QPaintEvent * pe)
{
    Q_UNUSED(pe);

    QPainter qp(this);

    if (!isGameOver)
    {
        qp.drawImage(head * OBJECT_SIZE, headMap.value(current));
        qp.drawImage(mouse * OBJECT_SIZE, i_mouse);

        if(_delay <= 100)
        {
            qp.drawImage(p_mine * OBJECT_SIZE, mine);
        }

        for (const auto& dot : dots)
        {
            qp.drawImage(dot * OBJECT_SIZE, snakeBody);
        }
    }
    else
    {
        killTimer(timerID);

        this->close();

        score->close();

        _music->stopBackgroundActionMusic();
        _music->stopBackgroundFunMusic();

        gameOver = new GameOver(defaultDelay, _choosingATopic, _musicIsPlay, _music);
    }
}

void GameWindow::timerEvent(QTimerEvent *te)
{
    Q_UNUSED(te);

    moveHead();
    checkCollision();
    checkMouse();

    this->update();
}

void GameWindow::keyPressEvent(QKeyEvent *ke)
{
    int key = ke->key();

    if ((key == Qt::Key_Left) && (current != RIGHT_DIRECTION))
    {
        current = LEFT_DIRECTION;
    }

    if ((key == Qt::Key_Right) && (current != LEFT_DIRECTION))
    {
        current = RIGHT_DIRECTION;
    }

    if ((key == Qt::Key_Up) && (current != DOWN_DIRECTION))
    {
        current = UP_DIRECTION;
    }

    if ((key == Qt::Key_Down) && (current != UP_DIRECTION))
    {
        current = DOWN_DIRECTION;
    }

    if(key == Qt::Key_Escape)
    {
        QApplication::quit();
    }

    QWidget::keyPressEvent(ke);
}

QPoint GameWindow::gettingCoordinates() const
{
    int x, y;
    bool nCheck = false;

    while (!nCheck)
    {
        int counter = 0;
        x = mt19937(random_device{}())() % (WIDTH / OBJECT_SIZE);
        y = mt19937(random_device{}())() % (HEIGHT / OBJECT_SIZE);

        if(head.x() != x || head.y() != y)
        {
            for (const auto& dot : dots)
            {
                if(dot.y() != y || dot.x() != x)
                {
                    ++counter;
                }
                else
                {
                    break;
                }
            }
        }

        if (counter == dots.size())
        {
            nCheck = true;
        }
    }

    return QPoint(x, y);
}

void GameWindow::timer()
{
    while (true)
    {
        if(_delay <= 200 && _delay > 100)
        {
            std::this_thread::sleep_for(std::chrono::seconds(5));
            locateMouseAndMine();
        }
        else if(_delay <= 100)
        {
            std::this_thread::sleep_for(std::chrono::seconds(2));
            locateMouseAndMine();
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void GameWindow::moveHead()
{
    tail = dots.at(dots.size() - 1);

    if (current == UP_DIRECTION)
    {
        if(head.y() == 0)
        {
            isGameOver = true;
        }
        else
        {
            int y = head.y();
            moveTail();
            y--;
            head.setY(y);
        }
    }
    else if (current == DOWN_DIRECTION)
    {
        if(head.y() == 19)
        {
            isGameOver = true;
        }
        else
        {
            int y = head.y();
            moveTail();
            y++;
            head.setY(y);
        }
    }
    else if (current == LEFT_DIRECTION)
    {
        if(head.x() == 0)
        {
            isGameOver = true;
        }
        else
        {
            int x = head.x();
            moveTail();
            x--;
            head.setX(x);
        }
    }
    else
    {
        if(head.x() == 19)
        {
            isGameOver = true;
        }
        else
        {
            int x = head.x();
            moveTail();
            x++;
            head.setX(x);
        }
    }
}

void GameWindow::moveTail()
{
    int x = head.x();
    int y = head.y();

    for (int i = dots.size() - 1; i > 0; i--)
    {
        dots.replace(i, QPoint(dots.at(i - 1).x(), dots.at(i - 1).y()));
    }

    dots.replace(0, QPoint(x, y));
}

void GameWindow::loadImages()
{
    i_mouse.load(":/new/icons/mouse.png");
    mine.load(":/new/icons/mine.png");
    snakeBody.load(":/new/icons/body.png");
    snakeHeadUp.load(":/new/icons/snakeHeadUp.png");
    snakeHeadDown.load(":/new/icons/snakeHeadDown.png");
    snakeHeadLeft.load(":/new/icons/snakeHeadLeft.png");
    snakeHeadRight.load(":/new/icons/snakeHeadRight.png");

    i_mouse = i_mouse.scaled(OBJECT_SIZE, OBJECT_SIZE, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    mine = mine.scaled(OBJECT_SIZE, OBJECT_SIZE, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    snakeBody = snakeBody.scaled(OBJECT_SIZE - 10, OBJECT_SIZE - 10, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    snakeHeadUp = snakeHeadUp.scaled(OBJECT_SIZE, OBJECT_SIZE, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    snakeHeadDown = snakeHeadDown.scaled(OBJECT_SIZE, OBJECT_SIZE, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    snakeHeadLeft = snakeHeadLeft.scaled(OBJECT_SIZE, OBJECT_SIZE, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    snakeHeadRight = snakeHeadRight.scaled(OBJECT_SIZE, OBJECT_SIZE, Qt::KeepAspectRatio, Qt::SmoothTransformation);
}

void GameWindow::locateMouseAndMine()
{
    auto coordinates = gettingCoordinates();

    mouse.setX(coordinates.x());
    mouse.setY(coordinates.y());

    bool nCheck = false;

    if(_delay <= 100)
    {
        while(!nCheck)
        {
           coordinates = gettingCoordinates();

            if(mouse.x() != coordinates.x() || mouse.y() != coordinates.y())
           {
                p_mine.setX(coordinates.x());
                p_mine.setY(coordinates.y());
                nCheck = true;
           }
        }
    }
}

void GameWindow::checkMouse()
{
    if (head.x() == mouse.x() && head.y() == mouse.y())
    {
        if(_musicIsPlay)
        {
           _music->playEatSound();
        }

        score->add();
        killTimer(timerID);

        if(_delay <= 300 && _delay > 200)
        {
           timerID = startTimer(_delay -= 10);
        }
        else if(_delay <= 200 && _delay > 100)
        {
          timerID = startTimer(_delay -= 5);
        }
        else
        {
          timerID = startTimer(_delay -= 1);
        }

        score->checkDelay(_delay);
        dots.push_back(tail);
        locateMouseAndMine();
    }
}

void GameWindow::checkCollision()
{
    for (const auto& dot : dots)
    {
        if (dot.x() == head.x() && dot.y() == head.y())
        {
            isGameOver = true;
        }
    }

    if(head.x() == p_mine.x() && head.y() == p_mine.y() && _delay <= 100)
    {
        isGameOver = true;
    }
}
