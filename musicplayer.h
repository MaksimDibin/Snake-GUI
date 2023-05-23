
#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QMediaPlayer>
#include <QAudioOutput>

class MusicPlayer
{
public:
    explicit MusicPlayer();
    ~MusicPlayer();

    void playBackgroundWelcomeWindowMusic();
    void playBackgroundGameWindowMusic();
    void playEatSound();
    void playGameOverSound();
    void stopBackgroundWelcomeWindowMusic();
    void stopBackgroundGameWindowMusic();
    void stopEatSound();
    void stopGameOverSound();

private:
    QMediaPlayer *m_backgroundWelcomeWindowMusic;
    QMediaPlayer *m_backgroundGameWindowMusic;
    QMediaPlayer *m_eatSound;
    QMediaPlayer *m_gameOverSound;
    QAudioOutput *audioOutput;
};

#endif // MUSICPLAYER_H
