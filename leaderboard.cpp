#include "leaderboard.h"
#include "ui_leaderboard.h"
#include "mainwindow.h"

MainWindow *mW;

LeaderBoard::LeaderBoard(const int delay, int choosingATopic, bool musicIsPlay, MusicPlayer *music, StyledWidget *parent) :
    StyledWidget(parent),
    ui(new Ui::LeaderBoard),
    _delay(delay),
    defaultDelay(delay),
    _music(music),
    _musicIsPlay(musicIsPlay),
    _choosingATopic(choosingATopic)
{
    ui->setupUi(this);
    checkingTheExistenceOfTheTable();

    setWindowFlags(Qt::FramelessWindowHint);

    this->show();
}

LeaderBoard::~LeaderBoard()
{
    delete ui;
    delete _music;
    delete mW;
}

void LeaderBoard::checkingTheExistenceOfTheTable()
{
    QString fileName = "leader board";

    file.setFileName(fileName);

    if (file.exists())
    {
        openTheFile();
    }
    else
    {
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        file.close();
    }
}

void LeaderBoard::openTheFile()
{
    QTextStream in(&file);

    file.open(QIODevice::ReadOnly);

    int itemsCount = 0;
    int rowCount = 0;
    int columnCount = 0;

    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList items = line.split(',');
        data->insert(items.at(0), items.at(1));

        while (columnCount < 2)
        {
            QTableWidgetItem* item = new QTableWidgetItem(items.at(itemsCount));
            ui->tableWidget->setItem(rowCount, columnCount, item);
            ++columnCount;
            ++itemsCount;
        }
        columnCount = 0;
        itemsCount = 0;
        ++rowCount;
    }

    file.close();
}

void LeaderBoard::addAFile(const QString& participant)
{
    QStringList items = participant.split(',');



}
