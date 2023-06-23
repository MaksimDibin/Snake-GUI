#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamewindow.h"

GameWindow *gameWindow;

MainWindow::MainWindow(int delay, MusicPlayer *music, int choosingATopic, bool musicIsPlay, StyledWidget *parent) :
    StyledWidget(parent),
    ui(new Ui::MainWindow),
    _music(music),
    _musicIsPlay(musicIsPlay),
    _choosingATopic(choosingATopic),
    _delay(delay)
{
    if(!_musicIsPlay)
    {
        _music->stopBackgroundActionMusic();
        _music->stopBackgroundFunMusic();
    }
    else
    {
        if(_choosingATopic == 1)
        {
            _music->stopBackgroundFunMusic();
            _music->playBackgroundActionMusic();
        }
    }

    ui->setupUi(this);

    ui->play->setFont(parent->getFont());
    ui->play->setStyleSheet(parent->getStyledButton());
    ui->play->setFocusPolicy(Qt::ClickFocus);

    ui->setting->setFont(parent->getFont());
    ui->setting->setStyleSheet(this->getStyledButton());
    ui->setting->setFocusPolicy(Qt::ClickFocus);

    ui->leaderboard->setFont(parent->getFont());
    ui->leaderboard->setStyleSheet(this->getStyledButton());
    ui->leaderboard->setFocusPolicy(Qt::ClickFocus);

    ui->exit->setFont(parent->getFont());
    ui->exit->setStyleSheet(this->getStyledButton());
    ui->exit->setFocusPolicy(Qt::ClickFocus);

    QPixmap cursorPixmap(":/new/icons/cursor.png");
    QCursor customCursor(cursorPixmap.scaled(25, 25, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    setCursor(customCursor);

    setWindowFlags(Qt::FramelessWindowHint);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete gameWindow;
    delete _music;
    delete settingWindow;
    delete leaderBoard;
}

void MainWindow::on_setting_clicked()
{
    this->close();

    settingWindow = new SettingWindow(_delay, _choosingATopic, _musicIsPlay, _music);
}


void MainWindow::on_play_clicked()
{
    this->close();

    gameWindow = new GameWindow(_delay, _choosingATopic, _musicIsPlay, _music);
}


void MainWindow::on_exit_clicked()
{
    QApplication::quit();
}


void MainWindow::on_leaderboard_clicked()
{
    this->close();

    leaderBoard = new LeaderBoard(_delay, _choosingATopic, _musicIsPlay, _music);
}

