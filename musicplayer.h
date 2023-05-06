
#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QMediaPlayer>
#include <QAudioOutput>
//#include <QObject>

class MusicPlayer
{
//    Q_OBJECT
public:
//    explicit MusicPlayer(QObject* parent = nullptr);
      explicit MusicPlayer();
    ~MusicPlayer();

    void playBackgroundWelcomeWindowMusic();
    void playBackgroundGameWindowMusic();
    void playEatSound();
    void playGameOverSound();

private:
    QMediaPlayer *m_backgroundWelcomeWindowMusic;
    QMediaPlayer *m_backgroundGameWindowMusic;
    QMediaPlayer *m_eatSound;
    QMediaPlayer *m_gameOverSound;
    QAudioOutput *audioOutput;
};

#endif // MUSICPLAYER_H
