
#include "musicplayer.h"

MusicPlayer::MusicPlayer()
{
    m_backgroundWelcomeWindowMusic = new QMediaPlayer;
    audioOutput = new QAudioOutput;
    m_backgroundWelcomeWindowMusic->setAudioOutput(audioOutput);
    m_backgroundWelcomeWindowMusic->setSource(QUrl("qrc:/new/sounds/backgroundWelcomeWindowMusic.wav"));
    audioOutput->setVolume(100);

    if (m_backgroundWelcomeWindowMusic->isPlaying()) {
        qDebug() << "File has been loaded and is ready to play.";
    } else {
        qDebug() << "Error loading file:" << m_backgroundWelcomeWindowMusic->errorString();
    }

    m_backgroundGameWindowMusic = new QMediaPlayer;
    m_backgroundGameWindowMusic->setSource(QUrl("qrc:/new/sounds/backgroundGameWindowMusic.wav"));

    m_eatSound = new QMediaPlayer;
    m_eatSound->setSource(QUrl("qrc:/new/sounds/eatSound.wav"));

    m_gameOverSound = new QMediaPlayer;
    m_gameOverSound->setSource(QUrl("qrc:/new/sounds/gameOverSound.wav"));
}

MusicPlayer::~MusicPlayer()
{
    delete m_backgroundWelcomeWindowMusic;
    delete m_backgroundGameWindowMusic;
    delete m_eatSound;
    delete m_gameOverSound;
}

void MusicPlayer::playBackgroundWelcomeWindowMusic()
{
        m_backgroundWelcomeWindowMusic->play();
}

void MusicPlayer::playBackgroundGameWindowMusic()
{
    m_backgroundGameWindowMusic->play();
}

void MusicPlayer::playEatSound()
{
    m_eatSound->play();
}

void MusicPlayer::playGameOverSound()
{
    m_gameOverSound->play();
}

void MusicPlayer::stopBackgroundWelcomeWindowMusic()
{
    m_backgroundWelcomeWindowMusic->stop();
}

void MusicPlayer::stopBackgroundGameWindowMusic()
{
    m_backgroundGameWindowMusic->stop();
}

void MusicPlayer::stopEatSound()
{
    m_eatSound->stop();
}

void MusicPlayer::stopGameOverSound()
{
    m_gameOverSound->stop();
}
