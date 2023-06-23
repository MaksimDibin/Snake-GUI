
#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QMediaPlayer>
#include <QAudioOutput>

class MusicPlayer
{
public:
    explicit MusicPlayer();
    ~MusicPlayer();

    void playBackgroundFunMusic();
    void playBackgroundActionMusic();
    void playEatSound();
    void playGameOverSound();
    void stopBackgroundFunMusic();
    void stopBackgroundActionMusic();
    void stopEatSound();
    void stopGameOverSound();

private:
    QMediaPlayer *m_funMusic;
    QMediaPlayer *m_actionMusic;
    QMediaPlayer *m_eatSound;
    QMediaPlayer *m_gameOverSound;
    QAudioOutput *audioFunMusic;
    QAudioOutput *audioActionMusic;
    QAudioOutput *audioOutputEat;
    QAudioOutput *audioOutputGameOver;
};

#endif // MUSICPLAYER_H
