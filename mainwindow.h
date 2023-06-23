#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "styledwidget.h"
#include "musicplayer.h"
#include "settingwindow.h"
#include "leaderboard.h"
#include <QApplication>

namespace Ui {
class MainWindow;
}

class MainWindow : public StyledWidget
{
    Q_OBJECT

public:
    explicit MainWindow(int delay = 300, MusicPlayer *musicPlayer = nullptr, int choosingATopic = 0, bool musicIsPlay = true, StyledWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_setting_clicked();

    void on_play_clicked();

    void on_exit_clicked();

    void on_leaderboard_clicked();

private:
    Ui::MainWindow *ui;
    MusicPlayer *_music;
    SettingWindow *settingWindow;
    LeaderBoard *leaderBoard;
    bool _musicIsPlay;
    int _choosingATopic;
    int _delay;
};

#endif // MAINWINDOW_H
