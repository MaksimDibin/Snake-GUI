
#include "musicplayer.h"

MusicPlayer::MusicPlayer()
{
    audioOutputWelcome = new QAudioOutput;
    audioOutputGame = new QAudioOutput;
    audioOutputEat = new QAudioOutput;
    audioOutputGameOver = new QAudioOutput;

    m_backgroundWelcomeWindowMusic = new QMediaPlayer;
    m_backgroundWelcomeWindowMusic->setAudioOutput(audioOutputWelcome);
    m_backgroundWelcomeWindowMusic->setSource(QUrl("qrc:/new/sounds/backgroundWelcomeWindowMusic.wav"));

    m_backgroundGameWindowMusic = new QMediaPlayer;
    m_backgroundGameWindowMusic->setAudioOutput(audioOutputGame);
    m_backgroundGameWindowMusic->setSource(QUrl("qrc:/new/sounds/backgroundGameWindowMusic.wav"));

    m_eatSound = new QMediaPlayer;
    m_eatSound->setAudioOutput(audioOutputEat);
    m_eatSound->setSource(QUrl("qrc:/new/sounds/eatSound.wav"));

    m_gameOverSound = new QMediaPlayer;
    m_gameOverSound->setAudioOutput(audioOutputGameOver);
    m_gameOverSound->setSource(QUrl("qrc:/new/sounds/gameOverSound.wav"));


}

MusicPlayer::~MusicPlayer()
{
    delete m_backgroundWelcomeWindowMusic;
    delete m_backgroundGameWindowMusic;
    delete m_eatSound;
    delete m_gameOverSound;
    delete audioOutputWelcome;
    delete audioOutputGame;
    delete audioOutputEat;
    delete audioOutputGameOver;
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
