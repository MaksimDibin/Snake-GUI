#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include "styledwidget.h"
#include "musicplayer.h"
#include <QFile>
#include <QStandardItemModel>
#include <QMap>

namespace Ui {
class LeaderBoard;
}

class LeaderBoard : public StyledWidget
{
    Q_OBJECT

public:
    explicit LeaderBoard(const int delay, int choosingATopic = 0, bool musicIsPlay = true, MusicPlayer *music = nullptr, StyledWidget *parent = nullptr);
    ~LeaderBoard();

private:
    Ui::LeaderBoard *ui;
    void checkingTheExistenceOfTheTable();
    void openTheFile();
    void addAFile(const QString& participant);
    QFile file;
    std::map<int, QString>* data;

    MusicPlayer *_music;

    bool _musicIsPlay;
    int _choosingATopic;
    int _delay;
    int defaultDelay;
};

#endif // LEADERBOARD_H
