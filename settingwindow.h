
#ifndef SETTINGWINDOW_H
#define SETTINGWINDOW_H

#include <QObject>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QComboBox>
#include "styledwidget.h"
#include "musicplayer.h"

class SettingWindow : public StyledWidget
{
    Q_OBJECT

public:
    explicit SettingWindow(const int delay, MusicPlayer *music = nullptr, StyledWidget *parent = nullptr);
    ~SettingWindow();
    int getDelay() const;
    void setDelay(const int delay);

private slots:
    void onApplyButtonClicked();

private:
    int delay_;
    QPushButton *applyButton;
    QLabel *text;
    QVBoxLayout *vbox;
    QComboBox *difficultyComboBox;
    MusicPlayer *_music;
    int easyLevel = 300;
    int middleLevel = 200;
    int hardleLevel = 100;
};

#endif // SETTINGWINDOW_H
