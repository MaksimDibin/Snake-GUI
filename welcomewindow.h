
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
    explicit WelcomeWindow(int delay = 300, MusicPlayer *musicPlayer = nullptr, StyledWidget *parent = nullptr);
    ~WelcomeWindow();

private slots:
    void onPlayButtonClicked();
    void onSettingsButtonClicked();

private:
    QPushButton *playButton;
    QPushButton *settingsButton;
    QPushButton *exitButton;
    QVBoxLayout *vbox;
    MusicPlayer *_music;
    SettingWindow *settingWindow;

    int delay_;
};

#endif // WELCOMEWINDOW_H
