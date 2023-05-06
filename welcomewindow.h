
#ifndef WELCOMEWINDOW_H
#define WELCOMEWINDOW_H

#include <QPushButton>
#include <QVBoxLayout>
#include <QApplication>
#include <QKeyEvent>
#include "settingwindow.h"
#include "styledwidget.h"
#include "musicplayer.h"

class WelcomeWindow : public StyledWidget
{
    Q_OBJECT

public:
    explicit WelcomeWindow(const int delay = 400, StyledWidget *parent = nullptr);
    ~WelcomeWindow();

private slots:
    void onPlayButtonClicked();
    void onSettingsButtonClicked();

private:
    QPushButton *playButton;
    QPushButton *settingsButton;
    QPushButton *exitButton;
    QVBoxLayout *vbox;

    SettingWindow *settingWindow;
    MusicPlayer *musicPlayer;

    int delay_;
};

#endif // WELCOMEWINDOW_H
