#include "welcomewindow.h"
#include "gamewindow.h"

GameWindow *gameWindow;

WelcomeWindow::WelcomeWindow(const int delay, StyledWidget *parent) : StyledWidget(parent), delay_(delay)
{
    vbox = new QVBoxLayout(this);

    playButton = new QPushButton("Играть", this);
    playButton->setFont(this->getFont());
    playButton->setStyleSheet(this->getStyledButton());
    playButton->setFocusPolicy(Qt::ClickFocus);
    connect(playButton, &QPushButton::clicked, this, &WelcomeWindow::onPlayButtonClicked);

    settingsButton = new QPushButton("Настройки", this);
    settingsButton->setFont(this->getFont());
    settingsButton->setStyleSheet(this->getStyledButton());
    settingsButton->setFocusPolicy(Qt::ClickFocus);
    connect(settingsButton, &QPushButton::clicked, this, &WelcomeWindow::onSettingsButtonClicked);

    exitButton = new QPushButton("Выход", this);
    exitButton->setFont(this->getFont());
    exitButton->setStyleSheet(this->getStyledButton());
    exitButton->setFocusPolicy(Qt::ClickFocus);
    connect(exitButton, &QPushButton::clicked, QApplication::instance(), &QApplication::quit);

    vbox->setAlignment(Qt::AlignCenter);
    vbox->setSpacing(50);
    vbox->addStretch(1);
    vbox->addWidget(playButton);
    vbox->addWidget(settingsButton);
    vbox->addWidget(exitButton);
    vbox->addStretch(1);

    QPixmap cursorPixmap(":/new/icons/cursor.png");
    QCursor customCursor(cursorPixmap.scaled(35, 35));
    setCursor(customCursor);

    setWindowFlags(Qt::FramelessWindowHint);

    musicPlayer = new MusicPlayer();
    musicPlayer->playBackgroundWelcomeWindowMusic();

    this->show();
}

WelcomeWindow::~WelcomeWindow()
{
    delete playButton;
    delete settingsButton;
    delete exitButton;
    delete vbox;
    delete gameWindow;
    delete musicPlayer;
}

void WelcomeWindow::onPlayButtonClicked()
{
    this->close();
    musicPlayer->stopBackgroundWelcomeWindowMusic();

    gameWindow = new GameWindow(delay_);
}

void WelcomeWindow::onSettingsButtonClicked()
{
    this->close();
    musicPlayer->stopBackgroundWelcomeWindowMusic();
    settingWindow = new SettingWindow(delay_);
}
