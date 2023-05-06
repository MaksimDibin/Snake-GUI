#include "gamewindow.h"

GameWindow::GameWindow(const int delay, StyledWidget *parent) : StyledWidget(parent), delay_(delay)
{

    loadImages();

    headMap.insert(LEFT_DIRECTION, snakeHeadLeft);
    headMap.insert(RIGHT_DIRECTION, snakeHeadRight);
    headMap.insert(UP_DIRECTION, snakeHeadUp);
    headMap.insert(DOWN_DIRECTION, snakeHeadDown);

    head.setX(10);
    head.setY(10);

    dots.push_back(QPoint(10, 11));
    dots.push_back(QPoint(10, 12));

    locateMouse();

    setCursor(Qt::BlankCursor);

    setWindowFlags(Qt::FramelessWindowHint);

    timerID = startTimer(delay_);

    this->show();
}

GameWindow::~GameWindow()
{
    delete gameOver;
}

void GameWindow::paintEvent(QPaintEvent * pe)
{
    Q_UNUSED(pe);

    QPainter qp(this);

    if (!isGameOver)
    {
        qp.drawImage(head * OBJECT_SIZE, headMap.value(current));
        qp.drawImage(mouse  * OBJECT_SIZE, i_mouse);

        for (const auto& dot : dots)
        {
            qp.drawImage(dot * OBJECT_SIZE, snakeBody);
        }
    }
    else
    {
        killTimer(timerID);

        this->close();

        gameOver = new GameOver(delay_);
    }
}

void GameWindow::timerEvent(QTimerEvent *te)
{
    Q_UNUSED(te);

    moveHead();
    checkCollision();
    checkMouse();

    update();
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
        dots.replace(i, QPoint(dots.at(i - 1).x(), dots.at(i - 1).y()));

    dots.replace(0, QPoint(x, y));
}

void GameWindow::loadImages()
{
    i_mouse.load(":/new/icons/mouse.png");
    snakeBody.load(":/new/icons/body.png");
    snakeHeadUp.load(":/new/icons/snakeHeadUp.png");
    snakeHeadDown.load(":/new/icons/snakeHeadDown.png");
    snakeHeadLeft.load(":/new/icons/snakeHeadLeft.png");
    snakeHeadRight.load(":/new/icons/snakeHeadRight.png");

    i_mouse = i_mouse.scaled(OBJECT_SIZE, OBJECT_SIZE, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    snakeBody = snakeBody.scaled(OBJECT_SIZE - 10, OBJECT_SIZE - 10, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    snakeHeadUp = snakeHeadUp.scaled(OBJECT_SIZE, OBJECT_SIZE, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    snakeHeadDown = snakeHeadDown.scaled(OBJECT_SIZE, OBJECT_SIZE, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    snakeHeadLeft = snakeHeadLeft.scaled(OBJECT_SIZE, OBJECT_SIZE, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    snakeHeadRight = snakeHeadRight.scaled(OBJECT_SIZE, OBJECT_SIZE, Qt::KeepAspectRatio, Qt::SmoothTransformation);
}

void GameWindow::locateMouse()
{
    int x, y;
    bool nCheck = false;

    while (!nCheck)
    {
        int counter = 0;
        x = std::mt19937(std::random_device{}())() % (WIDTH / OBJECT_SIZE);
        y = std::mt19937(std::random_device{}())() % (HEIGHT / OBJECT_SIZE);

        if(head.x() != x && head.y() != y)
        {
            for (const auto& dot : dots)
            {
                if(dot.y() != y && dot.x() != x)
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
            nCheck = true;
    }

    mouse.setX(x);
    mouse.setY(y);
}

void GameWindow::checkMouse()
{
    if (head.x() == mouse.x() && head.y() == mouse.y())
    {
        dots.push_back(tail);
        locateMouse();
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
}
