#ifndef SETTINGWINDOW_H
#define SETTINGWINDOW_H

#include "styledwidget.h"
#include "musicplayer.h"

namespace Ui {
class SettingWindow;
}

class SettingWindow : public StyledWidget
{
    Q_OBJECT

public:
    explicit SettingWindow(const int delay, int choosingATopic = 0, bool musicIsPlay = true, MusicPlayer *music = nullptr, StyledWidget *parent = nullptr);
    ~SettingWindow();
    int getDelay() const;
    void setDelay(const int delay);
    int getChoosingATopic() const;
    void setChoosingATopic(const int choosingATopic);
    int getMusicIsPlay() const;
    void setMusicIsPlay(const bool musicIsPla);

private slots:
    void on_apply_clicked();

private:
    Ui::SettingWindow *ui;
    MusicPlayer *_music;
    bool _musicIsPlay;
    int _choosingATopic;
    int _delay;
    int easyLevel = 300;
    int middleLevel = 200;
    int hardleLevel = 100;
};

#endif // SETTINGWINDOW_H
