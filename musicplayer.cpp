
#include "musicplayer.h"

MusicPlayer::MusicPlayer()
{
    audioFunMusic = new QAudioOutput;
    audioActionMusic = new QAudioOutput;
    audioOutputEat = new QAudioOutput;
    audioOutputGameOver = new QAudioOutput;

    m_funMusic = new QMediaPlayer;
    m_funMusic->setAudioOutput(audioFunMusic);
    m_funMusic->setSource(QUrl("qrc:/new/sounds/funMusic.wav"));
    m_funMusic->loops();

    m_actionMusic = new QMediaPlayer;
    m_actionMusic->setAudioOutput(audioActionMusic);
    m_actionMusic->setSource(QUrl("qrc:/new/sounds/hyper-spoiler.mp3"));
    m_actionMusic->loops();

    m_eatSound = new QMediaPlayer;
    m_eatSound->setAudioOutput(audioOutputEat);
    m_eatSound->setSource(QUrl("qrc:/new/sounds/eatSound.wav"));

    m_gameOverSound = new QMediaPlayer;
    m_gameOverSound->setAudioOutput(audioOutputGameOver);
    m_gameOverSound->setSource(QUrl("qrc:/new/sounds/gameOverSound.wav"));
}

MusicPlayer::~MusicPlayer()
{
    delete m_funMusic;
    delete m_eatSound;
    delete m_gameOverSound;
    delete audioFunMusic;
    delete audioOutputEat;
    delete audioOutputGameOver;
}

void MusicPlayer::playBackgroundFunMusic()
{
    m_funMusic->play();
}

void MusicPlayer::playBackgroundActionMusic()
{
    m_actionMusic->play();
}

void MusicPlayer::playEatSound()
{
    m_eatSound->play();
}

void MusicPlayer::playGameOverSound()
{
    m_gameOverSound->play();
}

void MusicPlayer::stopBackgroundFunMusic()
{
    m_funMusic->stop();
}

void MusicPlayer::stopBackgroundActionMusic()
{
    m_actionMusic->stop();
}

void MusicPlayer::stopEatSound()
{
    m_eatSound->stop();
}

void MusicPlayer::stopGameOverSound()
{
    m_gameOverSound->stop();
}
