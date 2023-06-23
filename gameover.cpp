#include "gameover.h"

GameOver::GameOver(const int delay, int choosingATopic,  bool musicIsPlay, MusicPlayer *music, StyledWidget* parent) :
    StyledWidget(parent),
    _music(music),
    _musicIsPlay(musicIsPlay),
    _choosingATopic(choosingATopic),
    _delay(delay)
{
    if(musicIsPlay)
    {
        _music->playGameOverSound();
    }

    QTimer::singleShot(1, this, &GameOver::showNextLetter);

    setCursor(Qt::BlankCursor);

    setWindowFlags(Qt::FramelessWindowHint);

    this->show();
}

GameOver::~GameOver()
{
    delete mainWindow;
    delete _music;
}

void GameOver::paintEvent(QPaintEvent* pe)
{
    Q_UNUSED(pe);

    QPainter qp(this);

    qp.setPen(Qt::red);
    qp.setFont(this->getFont());

    for (int i = 0; i < current_letter_index_; i++)
    {
        qp.drawText(50 + 60 * i, this->getHeight() / 2, QString(GAME_OVER_STR.at(i)));
    }
}

void GameOver::showNextLetter()
{
    current_letter_index_++;
    update();

    if (current_letter_index_ <= GAME_OVER_STR.size())
    {
        QTimer::singleShot(DELAY_GAME_OVER_STR, this, &GameOver::showNextLetter);
    }
    else
    {
        this_thread::sleep_for(chrono::milliseconds(1500));

        this->hide();

        _music->stopGameOverSound();
        
        _music->playBackgroundFunMusic();

        mainWindow = new MainWindow(_delay, _music, _choosingATopic, _musicIsPlay);
        mainWindow->show();
    }
}
