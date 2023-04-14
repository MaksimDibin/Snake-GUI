
#include "welcomewindow.h"

WelcomeWindow::WelcomeWindow(QWidget *parent) : QMainWindow(parent)
{
    QIcon icon(":/new/icons/icon.jpg");

    this->setWindowIcon(icon);

    QFont font = this->font();

    font.setPointSize(font.pointSize() + 6);

    this->setFont(font);

    centralWidget = new QWidget(this);

    setCentralWidget(centralWidget);

    this->setStyleSheet("background-color: green;");

    QPushButton *playButton = new QPushButton("Играть", centralWidget);

    playButton->setGeometry(200, 150, 200, 100);

    playButton->setStyleSheet("background-color: grey;");

    QObject::connect(playButton, &QPushButton::clicked, this, &WelcomeWindow::onPlayButtonClicked);

    QPushButton *settingsButton = new QPushButton("Настройки", centralWidget);

    settingsButton->setGeometry(200, 350, 200, 100);

    settingsButton->setStyleSheet("background-color: grey;");

    QObject::connect(settingsButton, &QPushButton::clicked, this, &WelcomeWindow::onSettingsButtonClicked);
}

void WelcomeWindow::onPlayButtonClicked()
{

}

void WelcomeWindow::onSettingsButtonClicked()
{

}
